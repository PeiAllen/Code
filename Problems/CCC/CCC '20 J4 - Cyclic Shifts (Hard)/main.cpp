#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e7+1;
int kmp[MN],z[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    string s=b+"$"+a;
    for(int i=1;i<sz(s);i++){
        int j=kmp[i-1];
        while(j>0&&s[i]!=s[j])j=kmp[j-1];
        kmp[i]=j+(s[i]==s[j]);
    }
    reverse(b.begin(),b.end()),reverse(a.begin(),a.end());
    s=b+"$"+a;
    for(int i=1,l=0,r=0;i<sz(s);i++){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(z[i]+i<sz(s)&&s[z[i]]==s[z[i]+i])z[i]++;
        if(z[i]+i-1>r)l=i,r=z[i]+i-1;
    }
    for(int i=0;i<sz(a);i++){
        if(kmp[i+sz(b)+1]+z[sz(s)-(i-kmp[i+sz(b)+1])-1]>=sz(b)){
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}