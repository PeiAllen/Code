#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=2e6+1;
int kmp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    a=b+"$"+a;
    for(int i=1;i<sz(a);i++){
        int j=kmp[i-1];
        while(j>0&&a[j]!=a[i])j=kmp[j-1];
        if(a[i]==a[j])j++;
        kmp[i]=j;
        if(i>sz(b)&&kmp[i]==sz(b)){
            printf("%d\n",i-sz(b)+1-(sz(b)+1));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}