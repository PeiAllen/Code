#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
template <typename T>
int sz(T &a){return (int)a.size();}
const int MAXN=5e4+1;
const int MAXQ=2e5+1;
lli mod=1e9+7;
lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
int n,k,q;
int arr[MAXN];
lli dp[MAXN][21];
lli precalc[21][21];
lli ans[MAXQ];
vector<pair<pii,int>> queries;
void calc(int l, int r,vector<pair<pii,int>> queries){
    int mid=(l+r)/2;
    memset(precalc,0,sizeof(precalc));
    precalc[0][0]=1;
    for(int i=mid+1;i<=r;i++){
        for(int a=1;a<=arr[i];a++){
            for(int b=arr[i];b>=a;b--){
                precalc[a][arr[i]]=fix(precalc[a][arr[i]]+precalc[a][b]);
            }
        }
        precalc[arr[i]][arr[i]]=fix(precalc[arr[i]][arr[i]]+1);
        for(int a=0;a<=20;a++){
            dp[i][a]=0;
            for(int b=a;b<=20;b++){
                dp[i][a]=fix(dp[i][a]+precalc[a][b]);
            }
        }
    }
    memset(precalc,0,sizeof(precalc));
    precalc[0][0]=1;
    for(int i=mid;i>=l;i--){
        for(int b=arr[i];b<=20;b++){
            for(int a=arr[i];a<=b;a++){
                precalc[arr[i]][b]=fix(precalc[arr[i]][b]+precalc[a][b]);
            }
        }
        precalc[arr[i]][arr[i]]=fix(precalc[arr[i]][arr[i]]+1);
        for(int b=0;b<=20;b++){
            dp[i][b]=0;
            for(int a=0;a<=b;a++){
                dp[i][b]=fix(dp[i][b]+precalc[a][b]);
            }
        }
    }
    vector<pair<pii,int>> left,right;
    for(auto x:queries){
        if(x.first.second<mid)left.push_back(x);
        else if(x.first.second==mid){
            for(int a=0;a<=20;a++){
                ans[x.second]=fix(ans[x.second]+dp[x.first.first][a]);
            }
        }
        else if(x.first.first>mid)right.push_back(x);
        else{
            for(int a=0;a<=20;a++){
                ans[x.second]=fix(ans[x.second]+(dp[x.first.first][a]*dp[x.first.second][0]%mod));
                for(int b=max(a,1);b<=20;b++){
                    ans[x.second]=fix(ans[x.second]+(dp[x.first.first][a]*dp[x.first.second][b]%mod));
                }
            }
        }
    }
    if(sz(left))calc(l,mid,left);
    if(sz(right))calc(mid+1,r,right);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>q;
    queries.resize(q);
    for(int i=0;i<q;i++){
        cin>>queries[i].first.first>>queries[i].first.second;
        queries[i].second=i;
    }
    calc(1,n,queries);
    for(int i=0;i<q;i++)printf("%lli\n",ans[i]);
    return 0;
}