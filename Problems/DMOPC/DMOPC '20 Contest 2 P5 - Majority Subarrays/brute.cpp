#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e6+1;
int arr[MN];
pii am[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int ma=0;
        int oth=0;
        for(int j=i;j<n;j++){
            oth++;
            if(am[arr[j]].second!=i){
                am[arr[j]].second=i;
                am[arr[j]].first=1;
                ma=max(ma,1);
            }
            else am[arr[j]].first++,ma=max(ma,am[arr[j]].first);
            if(2*ma>oth)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}