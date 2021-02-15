#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int cnt[26];
int tecnt[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string a;
    cin>>n>>a;
    for(int i=0;i<n;i++)cnt[a[i]-'a']++;
    int ans=0;
    for(int i=0;i<n-1;i++){
        tecnt[a[i]-'a']++;
        int am=0;
        for(int j=0;j<26;j++){
            if(tecnt[j]&&cnt[j]-tecnt[j]>0)am++;
        }
        ans=max(ans,am);
    }
    printf("%d\n",ans);
    return 0;
}