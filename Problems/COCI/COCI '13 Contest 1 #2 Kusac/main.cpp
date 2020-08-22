#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int lcm=n*m/(__gcd(m,n));
    int cut=0;
    for(int i=0;i<lcm;i+=lcm/m){
        if(i%(lcm/n)!=0)cut++;
    }
    printf("%d\n",cut);
    return 0;
}