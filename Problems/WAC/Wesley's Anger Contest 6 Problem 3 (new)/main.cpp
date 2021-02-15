#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll og[MN];
pair<ll,int> arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i].first,og[i]=arr[i].first,arr[i].second=i;
    sort(arr,arr+n);
    set<int> splits={0,n};
    map<ll,vector<int>> loc;
    for(int i=1;i<n;i++)if(arr[i].first!=arr[i-1].first)loc[-(arr[i].first-arr[i-1].first)].push_back(i);
    for(auto x:loc){
        bool work=true;
        for(auto y:x.second){
            auto it=splits.lower_bound(y);
            int right=*it,left=*prev(it,1);
            if(y-left<=right-y){
                int mi=INT_MAX,ma=INT_MIN;
                for(int i=left;i<y;i++)mi=min(mi,arr[i].second),ma=max(ma,arr[i].second);
                if(mi!=left||ma!=y-1)work=false;
            }
            else{
                int mi=INT_MAX,ma=INT_MIN;
                for(int i=y;i<right;i++)mi=min(mi,arr[i].second),ma=max(ma,arr[i].second);
                if(mi!=y||ma!=right-1)work=false;
            }
            splits.insert(y);
        }
        if(!work){
            printf("%lli\n",-x.first);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}