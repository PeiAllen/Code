#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>y>>x;
        ll box=max(x,y)-1;
        ll before=box*box;
        if(box%2==0)swap(x,y);
        if(box+1==x){
            printf("%lli\n",before+y);
        }
        else{
            printf("%lli\n",before+y-x+y);
        }
    }
    return 0;
}