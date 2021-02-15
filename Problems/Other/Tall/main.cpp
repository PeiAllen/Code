#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2001;
int arr[MN];
bitset<MN> used;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    pii ans={0,0};
    for(int i=0;i<n;i++){
        used.reset();
        for(int j=0;j<n;j++)if((arr[j]^arr[i])<n)used[arr[j]^arr[i]]=true;
        int mex=n;
        for(int j=0;j<n&&mex==n;j++)if(!used[j])mex=j;
        ans=max(ans,{mex,-arr[i]});
    }
    printf("%d %d\n",ans.first,-ans.second);
    return 0;
}