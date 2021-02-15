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
    string al,a;
    cin>>al>>a;
    set<string> fin;
    for(auto x:al)fin.insert(x+a);
    for(int i=0;i<sz(a);i++){
        for(auto x:al){
            fin.insert(a.substr(0,i)+x+a.substr(i+1));
            fin.insert(a.substr(0,i+1)+x+a.substr(i+1));
        }
        fin.insert(a.substr(0,i)+a.substr(i+1));
    }
    if(fin.count(a))fin.erase(a);
    for(auto x:fin)cout<<x<<"\n";
    return 0;
}