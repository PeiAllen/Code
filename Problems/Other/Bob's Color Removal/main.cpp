#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
int last[MN],arr[MN];
ll val[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mt19937_64 gen(time(NULL));
    uniform_int_distribution<ll> rand(1,1e12);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            val[i]=0;
            cin>>arr[i];
            last[arr[i]]=i;
        }
        ll psa=0,ans=0;
        map<ll,ll> cnt={{0,1}};
        for(int i=1;i<=n;i++){
            ll cur=0;
            if(last[arr[i]]==i)cur=val[arr[i]];
            else{
                cur=rand(gen);
                val[arr[i]]^=cur;
            }
            psa^=cur;
            ans+=cnt[psa];
            cnt[psa]++;
        }
        printf("%lli\n",ans);
    }
    return 0;
}