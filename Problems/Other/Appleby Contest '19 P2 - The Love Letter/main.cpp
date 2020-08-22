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
    string te;
    getline(cin,te);
    getline(cin,te);
    int l=stoi(te);
    string a;
    getline(cin,a);
    for(int i=0;i<sz(a);i++)if(a[i]!=' ')a[i]=(((a[i]-'a')+l)%26)+'a';
    cout<<a<<"\n";
    return 0;
}