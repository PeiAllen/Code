#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e8;
const int MN=501;
bool play[MN][MN];
ll dp[MN][MN];
bool poss[MN][MN];
pii dsu[MN];
vector<int> dudes[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        n*=2;
        for(int i=1;i<=n;i++){
            dudes[i]=vector<int>();
            dsu[i]={i,1};
            for(int j=1;j<=n;j++)play[i][j]=false;
        }
        for(int i=0;i<m;i++){
            cin>>a>>b;
            play[a][b]=play[b][a]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!play[i][j])uni(i,j);
            }
        }
        vector<pii> groups;
        for(int i=1;i<=n;i++){
            dudes[find(i)].push_back(i);
            if(find(i)==i){
                groups.push_back({dsu[i].second,i});
            }
        }
        dp[1][0]=1;
        poss[1][0]=true;
        for(int i=2;i<=sz(groups);i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=(dp[i-1][j]+(j>=groups[i-1].first?dp[i-1][j-groups[i-1].first]:0))%mod;
                poss[i][j]=poss[i-1][j]|(j>=groups[i-1].first?poss[i-1][j-groups[i-1].first]:false);
            }
        }
        printf("%lli\n",dp[sz(groups)][n/2]);
        vector<int> teama;
        int cur=n/2;
        for(int i=sz(groups);i>=2;i--){
            if(poss[i-1][cur])continue;
            for(auto x:dudes[groups[i-1].second]){
                teama.push_back(x);
            }
            cur-=groups[i-1].first;
        }
        sort(teama.begin(),teama.end());
        for(int i=0;i<sz(teama);i++){
            printf("%d%c",teama[i]," \n"[i==sz(teama)-1]);
        }
    }
    return 0;
}