#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        map<int,ll> rs;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(i>1&&arr[i]<arr[i-1]){
                rs[i]=arr[i-1]-arr[i];
            }
        }
        if(arr[n]>0)rs[n+1]=arr[n];
        ll ans=0;
        bool poss=true;
        map<int,ll> leftover;
        for(int i=1;i<=n;i++){
            if(arr[i]>arr[i-1]){
                ll val=arr[i]-arr[i-1];
                while(val) {
                    auto it = rs.lower_bound(i + l);
                    if (it == rs.end()){
                        poss = false;
                        break;
                    }
                    else {
                        int ind=it->first;
                        if(ind-i>r){
                            leftover[i]=val;
                            break;
                        }
                        ll mi=min(it->second,val);
                        ans+=mi*(ind-i>r?2:1);
                        val-=mi;
                        rs[ind]-=mi;
                        if(rs[ind]==0)rs.erase(ind);
                    }
                }
            }
        }
        for(auto x:leftover){
            ll val=x.second;
            int i=x.first;
            while(val) {
                auto it = rs.lower_bound(i + l);
                if (it == rs.end()){
                    poss = false;
                    break;
                }
                else {
                    int ind=it->first;
                    ll mi=min(it->second,val);
                    ans+=mi*(ind-i>r?2:1);
                    val-=mi;
                    rs[ind]-=mi;
                    if(rs[ind]==0)rs.erase(ind);
                }
            }
        }
        if(poss)printf("%lli\n",ans);
        else printf("-1\n");
    }
    return 0;
}