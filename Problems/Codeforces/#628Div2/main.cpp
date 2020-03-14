#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli v,u;
void solve(){
    if(v<u||(v-u)%2){
        printf("-1\n");
        return;
    }
    if(v==u){
        if(v==0)printf("0\n");
        else printf("1\n%lli\n",v);
    }
    printf("HI\n");
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>v>>u;
    solve();
    return 0;
}