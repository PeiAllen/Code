#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n,[&](auto lhs, auto rhs){
        return (lhs%k<rhs%k)||(lhs%k==rhs%k&&lhs<rhs);
    });
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}