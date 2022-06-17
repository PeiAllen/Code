#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string a;
    cin>>a;
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+(a[i-1]=='b');
    }
    int ans=INT_MAX;
    int redcnt=0;
    for(int i=n;i>=0;i--){
        ans=min(ans,redcnt+cnt[i]);
        if(i>0)redcnt+=a[i-1]=='r';
    }
    printf("%d\n",ans);
    return 0;
}