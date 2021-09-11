#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN],deq[MN];
bool bot[MN];
bool work(int am){
    int l=-1;
    for(int i=0;i<am;i++)deq[++l]=arr[i],bot[arr[i]]=false;
    sort(deq,deq+l+1);
    set<int> nums;
    l=0;
    for(int i=0;i<am;i++){
        if(arr[i]==deq[l]){
            l++;
            while(sz(nums)&&*nums.begin()==deq[l])l++,nums.erase(nums.begin());
        }
        else {
            auto it = nums.lower_bound(arr[i]);
            if (it == nums.begin()) {
                if (it == nums.end())bot[arr[i]] = true;
            } else {
                it--;
                if (!bot[*it])return 0;
                if (it == prev(nums.end(), 1))bot[arr[i]] = true;
            }
            nums.insert(arr[i]);
        }
    }
    return 1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int lo=1,hi=n;
    while(lo!=hi){
        int mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%d\n",lo);
    return 0;
}