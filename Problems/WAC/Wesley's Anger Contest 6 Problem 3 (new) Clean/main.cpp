#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
pair<ll,int> arr[MN];
int n;
bool work(ll diff){
    int mi=INT_MAX,ma=INT_MIN,st=0;
    for(int i=0;i<n;i++){
        mi=min(mi,arr[i].second),ma=max(ma,arr[i].second);
        if(i==n||arr[i+1].first-arr[i].first>diff){
            if(mi!=st||ma!=i)return false;
            mi=INT_MAX,ma=INT_MIN,st=i+1;
        }
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<ll> diffs={0};
    for(int i=0;i<n;i++)cin>>arr[i].first,arr[i].second=i;
    sort(arr,arr+n);
    for(int i=1;i<n;i++)diffs.push_back(arr[i].first-arr[i-1].first);
    sort(diffs.begin(),diffs.end()),diffs.erase(unique(diffs.begin(),diffs.end()),diffs.end());
    int lo=0,hi=sz(diffs)-1;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(work(diffs[mid]))hi=mid;
        else lo=mid+1;
    }
    printf("%lli\n",diffs[lo]);
    return 0;
}