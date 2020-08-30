#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
unordered_map<ll,int> am;
ll base=131,mod=68720001023;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string a;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<(1<<m);j++){
            string te=a;
            for(int k=0;k<m;k++){
                if(j&(1<<k)){
                    if(te[k]!='?')te[k]='?';
                    else te[k]='|';
                }
            }
            ll val=0;
            ll mut=1;
            for(int k=0;k<m;k++){
                if(te[k]=='?')te[k]='{';
                val=(val+(mut*ll(te[k]-'`')%mod))%mod;
                mut=mut*base%mod;
            }
            if(am.count(val))ans+=am[val];
        }
        for(int j=0;j<(1<<m);j++){
            string te=a;
            bool work=true;
            for(int k=0;k<m&&work;k++){
                if(j&(1<<k)){
                    if(te[k]!='?')te[k]='|';
                    else work=false;
                }
            }
            ll val=0;
            ll mut=1;
            for(int k=0;k<m;k++){
                if(te[k]=='?')te[k]='{';
                val=(val+(mut*ll(te[k]-'`')%mod))%mod;
                mut=mut*base%mod;
            }
            if(work)am[val]++;
        }
    }
    printf("%lli\n",ans);
    return 0;
}