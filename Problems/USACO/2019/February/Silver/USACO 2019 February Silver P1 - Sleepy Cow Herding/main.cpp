#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int n;
bool bad(){
    bool work=true;
    for(int i=1;i<n-1;i++){
        if(arr[i]!=arr[i-1]+1)work=false;
    }
    if(work)return true;
    work=true;
    for(int i=2;i<n;i++){
        if(arr[i]!=arr[i-1]+1)work=false;
    }
    if(work)return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ptr=0;
    int ans=n;
    for(int i=0;i<n;i++){
        while(ptr+1<n&&arr[ptr+1]-arr[i]+1<=n)ptr++;
        ans=min(ans,n-(ptr-i+1));
    }
    if(ans==1&&(bad())){
        ans=min(2,max(arr[n-1]-arr[n-2]-1,arr[1]-arr[0]-1));
    }
    printf("%d\n%d\n",ans,arr[n-1]-arr[0]+1-n+max(-(arr[1]-arr[0]-1),-(arr[n-1]-arr[n-2]-1)));
    return 0;
}