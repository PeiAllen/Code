#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+2;
ll psa[MN];
int lenl[MN],lenr[MN],work[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>psa[i],psa[i]+=psa[i-1];
    lenl[0]=0;
    for(int i=1;i<=n;i++){
        lenl[i]=lenl[i-1]+1;
        while(psa[i]-psa[i-lenl[i]]>s)lenl[i]--;
    }
    lenr[n]=0;
    for(int i=n-1;i>=1;i--){
        lenr[i]=lenr[i+1]+1;
        while(psa[i+lenr[i]]-psa[i]>s)lenr[i]--;
    }
    for(int i=1;i<=n;i++)work[i-min(lenl[i],lenr[i])+1]=i;
    int best=0;
    for(int i=1;i<=n;i++){
        best=max(best,work[i]);
        printf("%d\n",(best-i+1)*2);
    }
    return 0;
}