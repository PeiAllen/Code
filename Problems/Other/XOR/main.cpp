#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll getprexor(ll a){
    if(a%4==0)return a;
    if(a%4==1)return 1;
    if(a%4==2)return a+1;
    return 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    ll s,f;
    while(t--){
        cin>>s>>f;
        printf("%lli\n",getprexor(f)^getprexor(s-1));
    }
    return 0;
}