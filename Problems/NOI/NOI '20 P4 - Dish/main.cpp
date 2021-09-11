#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=501;
void solve(set<pii> vals, int m, int k){
    while(m&&m>SZ(vals)-1){
        pii large=*vals.rbegin();
        vals.erase(large);
        printf("%d %d\n",large.second,k);
        m--;
        if(large.first-k>0)vals.insert({large.first-k,large.second});
    }
    while(m){
        pii small=*vals.begin();
        vals.erase(vals.begin());
        pii large=*vals.rbegin();
        vals.erase(large);
        printf("%d %d %d %d\n",small.second,small.first,large.second,k-small.first);
        m--;
        vals.insert({large.first-(k-small.first),large.second});
    }
}
bitset<2500001> dp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,a;
        cin>>n>>m>>k;
        set<pii> vals;
        for(int i=0;i<n;i++){
            cin>>a;
            vals.insert({a,i+1});
        }
        if(m==n-2){
            dp[0].reset();
            dp[0][k]=1;
            int i=1;
            for(auto it=vals.rbegin();it!=vals.rend();it++){
                if(it->first-k>=0)dp[i]=dp[i-1]|(dp[i-1]<<(it->first-k));
                else dp[i]=dp[i-1]|(dp[i-1]>>(k-it->first));
                i++;
            }
            if(!dp[SZ(vals)][0]){
                printf("-1\n");
                continue;
            }
            set<pii> valone,valtwo;
            int cur=0;
            i=SZ(vals);
            for(auto x:vals){
                if(dp[i-1][cur])valtwo.insert(x);
                else valone.insert(x),cur-=(x.first-k);
                i--;
            }
            solve(valone,SZ(valone)-1,k),solve(valtwo,SZ(valtwo)-1,k);
        }
        else solve(vals,m,k);
    }
    return 0;
}