#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    for(int i=1;i+sz(b)<=sz(a);i++){
        bool work=true;
        for(int j=0;j<sz(b)&&work;j++){
            if(a[i+j]!=b[j]){
                work=false;
            }
        }
        if(work){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}