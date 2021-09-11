#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans=0;
    int last=INT_MAX;
    int am=0,a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<=last)am++;
        else am=1;
        ans=max(ans,am);
        last=a;
    }
    printf("%d\n",ans);
    return 0;
}