#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;

vector<pair<int,lli>> matrix[MAXN];
vector<pair<int,lli>> railways[MAXN];
map<int,pii> railindex[MAXN];
map<pii,int> trueindex[MAXN];
vector<int> sizes[MAXN];
lli dist[MAXN];
lli dp[MAXN];
vector<int> partof[MAXN];
map<lli,pii> atindex;
lli calc(int rail, int ind, int i, int ind2){
    if(ind==-1)return -1;
    if(ind>i)return -1;
    int tind=trueindex[rail][{ind2,ind}];
    int ti=trueindex[rail][{ind2,i}];
    return dp[railways[rail][tind].first]+(railways[rail][ti].second-railways[rail][tind].second)*(railways[rail][ti].second-railways[rail][tind].second);
}
struct seg {
    vector<int> t;
    seg(){t={};}
    void update(int ind, int le, int ri, int np, int rail, int ind2){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        bool l = calc(rail,np, le,ind2) >= calc(rail,t[ind], le,ind2);
        bool m = calc(rail,np, mid,ind2) >= calc(rail,t[ind], mid,ind2);
        if(mid)swap(t[ind],np);
        if(le==ri)return;
        else if(l!=m)update(left,le,mid,np,rail,ind2);
        else update(right,mid+1,ri,np,rail,ind2);
    }
    lli query(int ind, int le, int ri, int loc, int rail, int ind2){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        lli ans=calc(rail,t[ind],loc,ind2);
        if(le!=ri)ans=max(ans,(loc<=mid?query(left,le,mid,loc,rail,ind2):query(right,mid+1,ri,loc,rail,ind2)));
        return ans;
    }
};
vector<seg> lichao[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int s;
    vector<int> ord;
    for(int i=1;i<=n;i++)dist[i]=LLONG_MAX,ord.push_back(i);
    for(int i=0;i<m;i++){
        cin>>s;
        int cit;
        lli time;
        cin>>cit;
        railways[i].push_back({cit,0});
        int cit2;
        railindex[i][cit]={-1,0};
        partof[cit].push_back(i);
        for(int j=0;j<s;j++){
            cin>>time>>cit2;
            matrix[cit].push_back({cit2,time});
            cit=cit2;
            railindex[i][cit]= {-1,j + 1};
            partof[cit].push_back(i);
            railways[i].push_back({cit,time+railways[i].back().second});
        }
    }
    priority_queue<pair<lli,int>,vector<pair<lli,int>>,greater<>> q;
    dist[1]=0;
    q.push({0,1});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(dist[cur.second]>=cur.first){
            for(auto x:matrix[cur.second]){
                pair<lli,int> ne={x.second+cur.first,x.first};
                if(dist[ne.second]>ne.first){
                    dist[ne.second]=ne.first;
                    q.push(ne);
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        atindex.clear();
        for(auto x:railways[i]){
            lli todist=dist[x.first]-x.second;
            if(!atindex.count(todist))atindex[todist]={sz(atindex),0};
            trueindex[i][{atindex[todist].first,atindex[todist].second}]=railindex[i][x.first].second;
            railindex[i][x.first]={atindex[todist].first,atindex[todist].second++};
        }
        sizes[i].resize(sz(atindex));
        lichao[i].resize(sz(atindex));
        for(auto x:atindex){
            lichao[i][x.second.first].t.resize(3*x.second.second,-1);
            sizes[i][x.second.first]=x.second.second;
        }
    }
    sort(ord.begin(),ord.end(),[&](auto lhs, auto rhs){
        return dist[lhs]<dist[rhs];
    });
    for(int cur:ord){
        for(int x:partof[cur])dp[cur]=max(dp[cur],lichao[x][railindex[x][cur].first].query(1,0,sizes[x][railindex[x][cur].first]-1,railindex[x][cur].second,x,railindex[x][cur].first));
        for(int x:partof[cur])lichao[x][railindex[x][cur].first].update(1,0,sizes[x][railindex[x][cur].first]-1,railindex[x][cur].second,x,railindex[x][cur].first);
    }
    printf("%lli %lli\n",dist[n],dp[n]);
    return 0;
}