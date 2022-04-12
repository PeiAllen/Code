#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+2;
pii arr[MN];
int lift[__lg(MN)+1][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].A>>arr[i].B;
    }
    lift[0][n+1]=n+1;
    set<pii> ranges;
    for(int i=1,rptr=1;i<=n;i++){
        while(ranges.lower_bound({arr[rptr].A,0})==ranges.lower_bound({arr[rptr].B+1,0})){
            rptr++;
            ranges.insert(arr[rptr]);
        }
        lift[0][i]=rptr;
        ranges.erase(arr[rptr]);
    }
    for(int i=1;i<=__lg(n+1);i++){
        for(int j=1;j<=n+1;j++){
            lift[i][j]=lift[i-1][lift[i-1][j]];
        }
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        int jumps=0;
        for(int i=__lg(n+1);i>=0;i--){
            if(lift[i][a]<=b)jumps+=(1<<i),a=lift[i][a];
        }
        printf("%d\n",jumps+1);
    }
    return 0;
}