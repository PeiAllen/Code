#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,s,d;
    cin>>n>>s>>d;
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans=0;
    for(int i=0;i<=s;i++){
        for(int j=s;j<n;j++){
            int daycnt=d-2*(j-s)-2*(s-i)+max(j-s,s-i);
            if(daycnt>0){
                priority_queue<ll> vals;
                ll te=0;
                for(int k=i;k<=j;k++){
                    vals.push(arr[k]);
                }
                for(int k=0;k<daycnt&&sz(vals);k++)te+=vals.top(),vals.pop();
                ans=max(ans,te);
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}