#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5001;
unordered_set<ll> can;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int am=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        bool work=false;
        for(int j=0;j<i;j++){
            if(can.count(arr[i]-arr[j]))work=true;
        }
        am+=work;
        for(int j=0;j<=i;j++)can.insert(arr[i]+arr[j]);
    }
    printf("%d\n",am);
    return 0;
}