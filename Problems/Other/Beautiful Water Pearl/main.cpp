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
    int a,b,c;
    cin>>a>>b>>c;
    int ans=1;
    for(int i=0;i<30;i++){
        if((a&(1<<i))==0)ans*=((b&(1<<i))==0&&(c&(1<<i))==0);
        else if(b&(1<<i))ans*=((a&(1<<i))&&(c&(1<<i))==0);
        else ans*=((c&(1<<i))?2:0);
    }
    printf("%d\n",ans);
    return 0;
}