#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int M = 4500007;
struct hashmap{//eric ty
    ll key[M];
    pair<short,ll> val[M];
    int to[M], nxt[M], vis[M], size, null=1;
    void clear(){
        size = 0; null++;
    }
    void update(ll x, pair<short,ll> v){
        int cur = x%M;
        if(vis[cur] != null)
            vis[cur] = null, to[cur] = -1;
        for(cur = to[cur]; cur != -1; cur = nxt[cur])
            if(key[cur] == x){
                if(val[cur].first==v.first)val[cur].second+=v.second;
                else if(val[cur].first>v.first)val[cur]=v;
                return;
            }
        cur = x%M; nxt[size] = to[cur]; to[cur] = size; val[size] = v; key[size] = x;
        size++;
    }
} dp[2];
int cur=1;
bool gone[41];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll val;
    dp[0].update(((ll(1)<<(n+1))-1),{0,1});
    for(int i=1;i<=n;i++){
        dp[cur].clear();
        cin>>val;
        int right=n+1;
        for(int j=val+1;j<=n;j++) {
            if(!gone[j]){
                right=j;
                break;
            }
        }
        for(int ind=0;ind<dp[!cur].size;ind++){
            pair<ll,pair<short,ll>> x={dp[!cur].key[ind],dp[!cur].val[ind]};
            int invcnt=0;
            for(int j=val+1;j<=n;j++)if(gone[j]&&(x.first&(ll(1)<<j)))invcnt++;
            x.first-=ll(1)<<val;
            int curbit=val+1;
            int cnt=0;
            while(curbit!=right&&x.first&(ll(1)<<curbit)){
                cnt++;
                x.first-=ll(1)<<curbit;
                curbit++;
            }
            curbit=val-1;
            while(!(x.first&(ll(1)<<curbit)))curbit--;
            for(curbit++;cnt;cnt--,curbit++){
                x.first+=ll(1)<<curbit;
            }
            dp[cur].update(x.first,x.second);
            x.first+=ll(1)<<curbit;
            x.second.first+=invcnt;
            dp[cur].update(x.first,x.second);
        }
        cur=!cur;
        gone[val]=true;
    }
    vector<pair<int,pair<int,ll>>> ans;
    for(int ind=0;ind<dp[!cur].size;ind++){
        if(__builtin_popcountll(dp[!cur].key[ind])>1)ans.push_back({__builtin_popcountll(dp[!cur].key[ind]),dp[!cur].val[ind]});
    }
    sort(ans.begin(),ans.end());
    for(auto &&x:ans)printf("%d %lli\n",x.second.first,x.second.second);
    return 0;
}