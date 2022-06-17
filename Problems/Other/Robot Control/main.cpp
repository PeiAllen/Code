#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

const int MN=1e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+m);
    priority_queue<int,vector<int>,greater<>> q;
    for(int i=2;i<=m;i++){
        q.push(arr[i]-arr[i-1]);
    }
    ll ans=0;
    for(int i=0;i<m-n;i++){
        ans+=q.top();
        q.pop();
    }
    printf("%lli\n",ans);
    return 0;
}