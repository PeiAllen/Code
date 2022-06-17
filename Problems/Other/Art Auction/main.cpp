#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a;
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        cin>>a;
        q.push(a-arr[i]);
    }
    for(int i=0;i<m;i++){
        sum+=q.top();
        q.pop();
    }
    printf("%d\n",sum);
    return 0;
}