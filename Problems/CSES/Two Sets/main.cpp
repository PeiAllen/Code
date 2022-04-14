#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n*(n+1)/2%2==1)return 0*printf("NO\n");
    printf("YES\n");
    ll sum=n*(n+1)/2/2;
    vector<int> a,b;
    for(int i=n;i>=1;i--){
        if(sum>=i){
            a.push_back(i);
            sum-=i;
        }
        else b.push_back(i);
    }
    printf("%d\n",sz(a));
    for(auto x:a)printf("%d%c",x," \n"[x==a.back()]);
    printf("%d\n",sz(b));
    for(auto x:b)printf("%d%c",x," \n"[x==b.back()]);
    return 0;
}