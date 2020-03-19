#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
map<lli,lli> arr;
lli sum(lli a){
    return a*(a+1)/2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    int m;
    cin>>n>>m;
    lli a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[b]=max(arr[b],n-a);
    }
    pll last={0,0};
    lli ans=0;
    for(auto x:arr){
        lli cur=last.second-(x.first-last.first);
        lli calc=cur;
        calc=max((lli)-1,calc);
        calc=min(x.second,calc);
        ans+=sum(x.second+1)-sum(calc+1);
        last={x.first,max(cur,x.second)};
    }
    printf("%lli\n",ans);
    return 0;
}