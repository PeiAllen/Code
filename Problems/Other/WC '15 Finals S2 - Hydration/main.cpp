#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN],height[MN],am[MN];
int n,m,k;
map<int,int> can;
bool work(int amount){
    for(int i=0;i<m;i++)am[i]=0;
    int ptr=m-1;
    for(int i=n-1;i>=0;i--){
        while(ptr>=0&&height[ptr]>arr[i])ptr--;
        if(ptr==-1)return false;
        if(height[ptr]<arr[i]-k)return false;
        am[ptr]++;
        if(am[ptr]==amount)ptr--;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>height[i];
    sort(arr,arr+n),sort(height,height+m);
    for(int i=0;i<n;i++){
        int ind=upper_bound(height,height+m,arr[i])-height-1;
        if(ind==-1||height[ind]<arr[i]-k){
            printf("-1\n");
            return 0;
        }
    }
    int lo=1,hi=n;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(work(mid))hi=mid;
        else lo=mid+1;
    }
    printf("%d\n",lo);
    return 0;
}