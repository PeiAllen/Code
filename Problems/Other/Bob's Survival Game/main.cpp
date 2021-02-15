#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t,m;
    cin>>n>>t>>m;
    if(m<t){
        printf("%d\n",n);
        return 0;
    }
    int ans=0;
    int a;
    for(int i=0;i<m;i++){
        cin>>a;
        cnt[a]++;
        if(cnt[a]==m-t+1)ans++;
    }
    printf("%d\n",ans);
    return 0;
}