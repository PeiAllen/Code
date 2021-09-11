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
    int n;
    ll b,c;
    cin>>n>>b>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll cost=0;
    c=min(c,b);
    for(int i=0;i<n;i++){
        if(i+2<n){
            ll am=min({arr[i],arr[i+1],arr[i+2]});
            ll threeone=max(ll(0),min(am,arr[i+1]-am-(arr[i+2]-am+arr[i]-am)));
            ll twos=min(arr[i]-am,arr[i+1]-am);
            cost+=(threeone+twos)*(b+c);
            arr[i]-=(threeone+twos),arr[i+1]-=(threeone+twos);
            am=min({arr[i],arr[i+1],arr[i+2]});
            cost+=am*(b+2*c);
            arr[i]-=am,arr[i+1]-=am,arr[i+2]-=am;
        }
        if(i+1<n){
            ll am=min(arr[i],arr[i+1]);
            cost+=am*(b+c);
            arr[i]-=am,arr[i+1]-=am;
        }
        ll am=arr[i];
        cost+=am*(b);
        arr[i]-=am;
    }
    printf("%lli\n",cost);
    return 0;
}