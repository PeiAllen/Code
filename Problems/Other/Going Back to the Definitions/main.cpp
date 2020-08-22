#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
string arr[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n,[&](auto lhs, auto rhs){
        return rhs+lhs<lhs+rhs;
    });
    for(int i=0;i<n;i++)cout<<arr[i];
    return 0;
}