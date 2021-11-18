#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
ll query(int a, int b){
    printf("? %d %d\n",a,b);
    ll ret;
    cin>>ret;
    if(ret==1e18+1)exit(0);
    return ret;
}
ll arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int n;
    cin>>n;
    ll diff=query(1,2);
    arr[2]=query(1,2)/2;
    arr[1]=diff+arr[2];
    ll firstval=2*arr[1];
    for(int i=3;i<=n;i++){
        ll te=query(1,i);
        arr[i]=firstval-te;
        firstval+=arr[i];
    }
    printf("!");
    for(int i=1;i<=n;i++)printf(" %lli",arr[i]);
    printf("\n");
    return 0;
}