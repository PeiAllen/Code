#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e3+1;
pii arr[MAXN];
int n;
bool work(int a){
    for(int i=0;i<n;i++){
        if(a+arr[i].second>arr[i].first)return false;
        a+=arr[i].second;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr,arr+n);
    int lo=0,hi=1e6;
    while(lo!=hi){
        int mid=(lo+hi)/2+1;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    if(!work(lo))printf("-1\n");
    else printf("%d\n",lo);
    return 0;
}