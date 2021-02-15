#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
ll sal[MN];
ll rev[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>sal[i];
    }
    int a,b,c;
    ll d;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            cin>>d;
            for(int i=b;i<=c;i++)sal[i]+=d;
        }
        else{
            for(int i=b;i<=c;i++)rev[i]+=sal[i];
        }
    }
    for(int i=1;i<=n;i++)printf("%lli%c",rev[i]," \n"[i==n]);
    return 0;
}