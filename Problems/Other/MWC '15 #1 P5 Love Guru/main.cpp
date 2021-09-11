#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int mod=10;
int val[27];
int getval(const string& a){
    for(int i=1;i<=26;i++)val[i]=i;
    int ans=0;
    for(int i=0;i<sz(a);i++){
        ans=(ans+val[tolower(a[i])-'`'])%mod;
        for(int i=1;i<=26;i++)val[i]=val[i]*i%mod;
    }
    return ans==0?10:ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    printf("%d\n",getval(a)+getval(b));
    return 0;
}