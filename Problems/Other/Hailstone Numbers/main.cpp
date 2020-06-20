#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    int cnt=0;
    while(n!=1){
        if(n%2)n=n*3+1;
        else n/=2;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}