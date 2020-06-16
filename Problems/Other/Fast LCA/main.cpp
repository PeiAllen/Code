#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=6e6+1;
int par[MAXN];
int dep[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++)cin>>par[i],dep[i]=dep[par[i]]+1;
    int a,b;
    while(q--){
        cin>>a>>b;
        while(a!=b){
            if(dep[a]<dep[b])swap(a,b);
            a=par[a];
        }
        printf("%d\n",a);
    }
    return 0;
}