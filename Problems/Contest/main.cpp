#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e4+1;
const int MM=2e6+1;
const int MD=41;
const int MV=1e9;
vector<pii> items[MN];
vector<bool> spec[MN];
vector<int> badind[MN];
int needed[MN];
int am[MN];
bool bad[MN];
int cost[MD];
int notneeded[MN];
int costspec[13][MD+13*201];
int anscost[MD];
int dp[MM];
int dp2[MN];
pair<pii,pair<pii,pii>> relation[MN];
vector<int> solve(vector<pii> vals, int l, int r){
    int masum=0;
    vector<int> ones,twos,threes;
    for(auto x:vals){
        if(x.first==0)continue;
        masum+=x.first;
        if(x.first==1)ones.push_back(x.second);
        else if(x.first==2)twos.push_back(x.second);
        else threes.push_back(x.second);
    }
    sort(ones.begin(),ones.end());
    sort(twos.begin(),twos.end());
    sort(threes.begin(),threes.end());
    for(int i=1;i<sz(ones);i++)ones[i]+=ones[i-1];
    for(int i=1;i<sz(twos);i++)twos[i]+=twos[i-1];
    for(int i=1;i<sz(threes);i++)threes[i]+=threes[i-1];
    for(int i=0;i<=masum;i++){
        int lo=max(0,(i-sz(ones)+1)/2),hi=min(i/2,sz(twos));
        int lmin=lo,rmax=hi;
        auto getcost=[&](int a){
            if(a<lmin||a>rmax)return MV;
            return (a==0?0:twos[a-1])+(i-a*2==0?0:ones[i-a*2-1]);
        };
        if(lo>hi)dp[i]=INT_MAX;
        else{
            while(lo!=hi){
                int mid=(lo+hi)/2;
                int slope=getcost(mid+1)-getcost(mid);
                if(slope<=0)lo=mid+1;
                else hi=mid;
            }
            dp[i]=getcost(lo);
        }
    }
    int mareached[2]={(sz(ones)+2*sz(twos))/2*2,(sz(ones)==0?-1:((sz(ones)+2*sz(twos))%2==1?sz(ones)+2*sz(twos):sz(ones)+2*sz(twos)-1))};
    for(int i=0;i<=masum;i++){
        int rmax=min(i/3,sz(threes));
        dp2[i]=INT_MAX;
        int lo=(max(0,(i-mareached[i%2]+2)/3)+1)/2,hi=rmax/2;//solve eventhrees
        int lmin=lo;
        auto getcost=[&](int a){
            if(a<lmin||a>rmax)return MV;
            return (a==0?0:threes[a-1])+dp[i-3*a];
        };
        if(lo<=hi){
            while(lo!=hi){
                int mid=(lo+hi)/2;
                int slope=getcost(2*(mid+1))-getcost(2*mid);
                if(slope<=0)lo=mid+1;
                else hi=mid;
            }
            dp2[i]=min(dp2[i],getcost(2*lo));
        }
        lo=max(0,(i-mareached[(i+1)%2]+2)/3)/2,hi=(rmax-1)/2;//solve oddthrees
        lmin=lo;
        if(rmax==0)hi=-1;
        if(lo<=hi){
            while(lo!=hi){
                int mid=(lo+hi)/2;
                int slope=getcost(2*(mid+1)+1)-getcost(2*mid+1);
                if(slope<=0)lo=mid+1;
                else hi=mid;
            }
            dp2[i]=min(dp2[i],getcost(2*lo+1));
        }
    }
    vector<int> toret(r-l+1);
    for(int i=l;i<=r;i++){
        toret[i-l]=(i>masum?INT_MAX:dp2[i]);
    }
    for(int i=r+1;i<=masum;i++){
        toret[r-l]=min(toret[r-l],dp2[i]);
    }
    return toret;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,t;
    cin>>m>>t;
    for(int i=1;i<=m;i++){
        int n;
        cin>>n>>needed[i];
        am[i]=n;
        t-=needed[i];
        items[i].resize(n+1);
        spec[i].resize(n+1);
        badind[i].resize(n+1);
        for(int j=1;j<=n;j++)cin>>items[i][j].first>>items[i][j].second;
    }
    for(int i=1;i<=t;i++)cost[i]=INT_MAX;
    int p;
    cin>>p;
    for(int i=0;i<p;i++){
        cin>>relation[i].first.first>>relation[i].second.first.first>>relation[i].second.first.second>>relation[i].second.second.first>>relation[i].second.second.second;
        if(relation[i].first.first<=2)cin>>relation[i].first.second;
        spec[relation[i].second.first.first][relation[i].second.first.second]=true;
        spec[relation[i].second.second.first][relation[i].second.second.second]=true;
        bad[relation[i].second.first.first]=true;
        bad[relation[i].second.second.first]=true;
    }
    vector<int> specind;
    vector<pii> baditems;
    for(int i=1;i<=m;i++){
        if(!bad[i]){
            vector<int> te=solve(items[i],needed[i],needed[i]+t);
            vector<int> teres(t+1,INT_MAX);
            for(int a=0;a<=t;a++){
                if(te[a]!=INT_MAX)for(int b=0;b<=t;b++){
                    if(cost[b]!=INT_MAX)teres[min(a+b,t)]=min(teres[min(a+b,t)],te[a]+cost[b]);
                }
            }
            for(int j=0;j<=t;j++)cost[j]=teres[j];
        }
        else{
            vector<pii> temp;
            for(int j=1;j<=am[i];j++){
                if(spec[i][j])notneeded[i]+=items[i][j].first,badind[i][j]=sz(baditems),baditems.push_back({i,j});
                else temp.push_back(items[i][j]);
            }
            int micalc=max(0,needed[i]-notneeded[i]);
            vector<int> te=solve(temp,micalc,needed[i]+t);
            for(int j=micalc;j<=needed[i]+t;j++){
                costspec[sz(specind)][j-micalc]=te[j-micalc];
            }
            specind.push_back(i);
        }
    }
    int baditemcnt=sz(baditems);
    int ans=INT_MAX;
    for(int i=0;i<(1<<baditemcnt);i++){
        int fixedcost=0;
        bool work=true;
        for(int j=0;j<p;j++){
            int a=badind[relation[j].second.first.first][relation[j].second.first.second];
            int b=badind[relation[j].second.second.first][relation[j].second.second.second];
            if((i&(1<<a))&&(i&(1<<b))){
                if(relation[j].first.first==3)work=false;
                else if(relation[j].first.first==2)fixedcost+=relation[j].first.second;
                else fixedcost-=relation[j].first.second;
            }
        }
        if(!work)continue;
        for(int j=0;j<baditemcnt;j++){
            if(i&(1<<j)){
                fixedcost+=items[baditems[j].first][baditems[j].second].second;
            }
        }
        for(int j=0;j<=t;j++)anscost[j]=cost[j];
        int curspec=0;
        for(auto x:specind){
            int micalc=max(0,needed[x]-notneeded[x]);
            int given=0;
            for(int j=0;j<baditemcnt;j++){
                if(i&(1<<j)){
                    if(baditems[j].first==x){
                        given+=items[x][baditems[j].second].first;
                    }
                }
            }
            vector<int> teres(t+1,INT_MAX);
            for(int a=0;a<t;a++){
                if(a+needed[x]-given-micalc>=0&&costspec[curspec][a+needed[x]-given-micalc]!=INT_MAX)for(int b=0;b<=t;b++){
                    if(anscost[b]!=INT_MAX)teres[min(a+b,t)]=min(teres[min(a+b,t)],costspec[curspec][a+needed[x]-given-micalc]+anscost[b]);
                }
            }
            int best=INT_MAX;
            for(int j=max(0,t+needed[x]-given-micalc);j<=needed[x]+t-micalc;j++){
                best=min(best,costspec[curspec][j]);
            }
            if(best!=INT_MAX)for(int b=0;b<=t;b++){
                if(anscost[b]!=INT_MAX)teres[min(t+b,t)]=min(teres[min(t+b,t)],best+anscost[b]);
            }
            for(int j=0;j<=t;j++)anscost[j]=teres[j];
            curspec++;
        }
        if(anscost[t]!=INT_MAX)ans=min(ans,fixedcost+anscost[t]);
    }
    if(ans==INT_MAX)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}