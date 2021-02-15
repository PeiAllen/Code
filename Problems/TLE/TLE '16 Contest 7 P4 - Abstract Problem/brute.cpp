#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        int count=0;
        while(x){
            if(x%2!=0){
                if((x&2)!=0&&x!=3)x++;
                else x--;
            }
            else x/=2;
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}