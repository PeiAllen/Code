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
    set<string> arr;
    int c;
    cin>>c;
    int type;
    while(c--){
        cin>>type;
        string a;
        if(type==1){
            cin>>a;
            if(arr.count(a))printf("false\n");
        }
    }
    return 0;
}