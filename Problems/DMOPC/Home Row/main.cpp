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
    string a,b;
    cin>>a>>b;
    int am=min(sz(a),sz(b));
    for(int i=0;i<min(sz(a),sz(b));i++){
        if(a[i]!=b[i]){
            am=i;
            break;
        }
    }
    printf("%d\n",sz(a)-am+sz(b)-am);
    return 0;
}