#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli r;
    cin>>r;
    lli ans=0;
    for(lli i=0;i<=sqrt(r);i++){
        ans+=sqrt(r-(i*i));
    }
    printf("%lli\n",ans*4);
    return 0;
}