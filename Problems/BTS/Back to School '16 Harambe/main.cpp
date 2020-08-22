#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    string a;
    getline(cin,a);
    int l=0,u=0;
    for(char x:a){
        if(islower(x))l++;
        else if(isupper(x))u++;
    }
    if(l>u)for(int i=0;i<sz(a);i++)a[i]=tolower(a[i]);
    if(u>l)for(int i=0;i<sz(a);i++)a[i]=toupper(a[i]);
    cout<<a;
    return 0;
}