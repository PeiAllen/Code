#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e6+1;
const ll mod=1e9+7;
int z[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        int n=sz(a);
        for(int i=1,r=-1;i<n;i++){
            if(r<i){
                r=i-1;
                while(r+1<n&&a[r+1]==a[r+1-i])r++;
            }
            else{
                int k=1;
            }
            z[i]=r-i+1;
        }
        printf("%lli\n",ans);
    }
    return 0;
}