#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
const ll mod=1e9+7;
string given[MN];
pair<string,int> arr[5002];
int ord[5001];
int n,l,m;
ll getval(int ind){
    ll ans=0,val=1;
    for(int i=sz(arr[ind].first)-1;i>=0;i--){
        if(arr[ind].first[i]=='1')ans=(ans+val)%mod;
        val=val*2%mod;
    }
    return ans;
}
int main(){//&1 and |0 dont do anything, and &0,|1 set it to 0 and 1 respectively, so if we think of the operations as a binary number with & as 1 and | as 0, the bit for each power of 2 is the first differing bit(the bit of the binary string(since [1,0] is &0)) between the binary string of that power and the operation string. So every binary string <= operation number becomes 0, everything > becomes a 1
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>m;
    for(int i=0;i<n;i++)cin>>given[i];
    for(int i=0;i<l;i++){
        arr[i+1].second=i;
        for(int j=n-1;j>=0;j--)arr[i+1].first.push_back(given[j][i]);
    }
    sort(arr+1,arr+l+1);
    for(int i=1;i<=l;i++)ord[arr[i].second]=i;
    arr[0]={string(n,'0'),-1};
    arr[l+1]={string(n+1,'0'),-1};
    arr[l+1].first[0]='1';
    char a;
    while(m--){
        int le=0,ri=l+1;
        for(int i=0;i<l;i++){
            cin>>a;
            if(a=='0')le=max(le,ord[i]);
            else ri=min(ri,ord[i]);
        }
        if(ri>le)printf("%lli\n",(getval(ri)-getval(le)+mod)%mod);
        else printf("0\n");
    }
    return 0;
}