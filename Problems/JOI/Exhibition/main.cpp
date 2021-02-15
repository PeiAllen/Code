#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pii arr[MN];
int frame[MN];
int n,m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i].second>>arr[i].first;
    for(int i=0;i<m;i++)cin>>frame[i];
    sort(arr,arr+n),sort(frame,frame+m);
    int ptr=m-1;
    for(int i=n-1;i>=0;i--)if(ptr>=0&&arr[i].second<=frame[ptr])ptr--;
    printf("%d\n",m-ptr-1);
    return 0;
}