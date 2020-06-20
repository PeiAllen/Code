#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=6e6+1;
int par[MAXN];
bool gone[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++)cin>>par[i];
    int a,b;
    while(q--){
        cin>>a>>b;
        int old=a;
        gone[a]=true;
        while(par[a]){
            a=par[a];
            gone[a]=true;
        }
        while(!gone[b]){
            b=par[b];
        }
        printf("%d\n",b);
        a=old;
        gone[a]=false;
        while(par[a]){
            a=par[a];
            gone[a]=false;
        }
    }
    return 0;
}