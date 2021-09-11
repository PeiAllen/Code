#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t=10;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int loc=max_element(arr,arr+n)-arr;
        int good=n;
        for(int i=loc-1;i>=0;i--){
            if(arr[i]==good-1)good--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]<good) {
                int cnt=i;
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] > arr[i]&&arr[j]<good){
                        cnt++;
                    }
                }
                ans+=cnt;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}