#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e6+1;
int kmp[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    s=t+"$"+s;
    for(int i=1;i<sz(s);i++){
        int j=kmp[i-1];
        while(j>0&&s[j]!=s[i])j=kmp[j-1];
        if(s[j]==s[i])j++;
        kmp[i]=j;
        if(kmp[i]==sz(t)){
            printf("%d\n",i-sz(t)-sz(t));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}