#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
const int MAXM=3e5+1;
int ans[MAXM];
pii dsu[MAXN];
vector<pair<pii,pair<pii,pii>>> updates;
int n,m,q;
int find(int a){
    if(dsu[a].first==a)return a;
    return find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    updates.push_back({{ap,bp},{dsu[ap],dsu[bp]}});
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
void undo(){
    auto cur=updates.back();
    updates.pop_back();
    dsu[cur.first.first]=cur.second.first;
    dsu[cur.first.second]=cur.second.second;
}
bool connected(){
    return dsu[find(1)].second==n;
}
vector<lli> duri;
vector<lli> tim;
vector<pair<pll,pii>> highways;
vector<pair<int,pii>> highwayts[MAXM];
vector<pair<int,pii>> highwayds[MAXM];
void solve(int lduri, int rduri, int l, int r){//everything that has >=rduri and has time <l is already there.
    if(lduri==rduri){
        int cnt=0;
        bool done=false;
        for(int i=l;i<=r&&!done;i++){
            for(auto x:highwayts[i]){
                if(x.first>=lduri)uni(x.second.first,x.second.second),cnt++;
                else break;
            }
            if(connected()){
                ans[lduri]=i;
                done=true;
                break;
            }
        }
        if(!done)ans[lduri]=INT_MAX;
        while(cnt--)undo();
        cnt=0;
        return;
    }
    int mid=(lduri+rduri)/2;
    int timeneeded=-2;
    int cnt=0;
    for(int i=mid;i<rduri;i++){
        for(auto x:highwayds[i]){
            if(x.first<l)uni(x.second.first, x.second.second), cnt++;
            else break;
        }
    }
    bool ndch=true;
    for (int i = l; i <= r&&ndch; i++) {
        for (auto x:highwayts[i]) {
            if (x.first >= mid)uni(x.second.first, x.second.second), cnt++;
            else break;
        }
        if (connected()) {
            timeneeded = i;
            break;
        }
    }
    while (cnt--)undo();
    cnt = 0;
    if(mid>=lduri) {
        for (int i = mid; i <= rduri; i++) {
            for (int j = 0; j < sz(highwayds[i]) && highwayds[i][j].first < l; j++) {
                uni(highwayds[i][j].second.first, highwayds[i][j].second.second), cnt++;
            }
        }
        solve(lduri, mid, l, (timeneeded==-2?r:timeneeded));
        while (cnt--)undo();
        cnt = 0;
    }
    if(timeneeded==-2){
        for(int i=mid+1;i<=rduri;i++)ans[i]=INT_MAX;
    }
    else {
        if(mid+1<=rduri) {
            if (timeneeded  <= r) {
                for (int i = l; i < timeneeded; i++) {
                    for (auto x:highwayts[i]) {
                        if (x.first >= rduri)uni(x.second.first, x.second.second), cnt++;
                        else break;
                    }
                }
                solve(mid+1, rduri, timeneeded , r);
                while (cnt--)undo();
                cnt=0;
            } else {
                for(int i=mid+1;i<=rduri;i++)ans[i]=INT_MAX;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    freopen("data.in","r",stdin);
//    freopen("main.out","w",stdout);
    cin>>n>>m>>q;
    int a,b;
    lli d,t;
    int cnt=0;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    for(int i=0;i<m;i++){
        cin>>a>>b>>d>>t;
        uni(a,b);
        cnt++;
        duri.push_back(d);
        highways.push_back({{d,t},{a,b}});
        tim.push_back(t);
    }
    sort(duri.begin(),duri.end());
    sort(tim.begin(),tim.end());
    duri.erase(unique(duri.begin(),duri.end()),duri.end());
    tim.erase(unique(tim.begin(),tim.end()),tim.end());
    if(!connected())for(int i=0;i<sz(duri);i++)ans[i]=INT_MAX;
    else{
        while(cnt--)undo();
        cnt=0;
        for(auto x:highways){
            int nd=lower_bound(duri.begin(),duri.end(),x.first.first)-duri.begin();
            int nt=lower_bound(tim.begin(),tim.end(),x.first.second)-tim.begin();
            highwayts[nt].push_back({nd,x.second});
            highwayds[nd].push_back({nt,x.second});
        }
        for(int i=0;i<sz(duri);i++)sort(highwayds[i].begin(),highwayds[i].end());
        for(int i=0;i<sz(tim);i++)sort(highwayts[i].begin(),highwayts[i].end(),greater<>());
        solve(0,sz(duri)-1,0,sz(tim)-1);
    }
    while(q--){
        cin>>d>>t;
        int nd=lower_bound(duri.begin(),duri.end(),d)-duri.begin();
        if(nd==sz(duri)){
            printf("NO\n");
            continue;
        }
        int nt=(upper_bound(tim.begin(),tim.end(),t)-tim.begin())-1;
        if(ans[nd]<=nt)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}