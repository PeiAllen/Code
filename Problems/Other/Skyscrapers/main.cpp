#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
int row[MAXN],col[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll m,n,c,C;
    cin>>m>>n>>c>>C;
    multiset<ll> findsame;
    ll sam=0;
    for(int i=0;i<m;i++)cin>>row[i],sam+=row[i];
    for(int i=0;i<n;i++)cin>>col[i],findsame.insert(col[i]),sam+=col[i];
    sort(row,row+m),sort(col,col+n);
    if(row[m-1]!=col[n-1]){
        printf("Impossible\n");
        return 0;
    }
    int cused=0;
    ll lam=0;
    for(int i=0;i<m;i++){
        while(cused<n&&col[cused]<row[i])lam+=col[cused]*ll(m-i),cused++;
        lam+=row[i]*ll(n-cused);
    }
    for(int i=0;i<m;i++){
        if(findsame.count(row[i])){
            sam-=row[i];
            findsame.erase(findsame.find(row[i]));
        }
    }
    printf("Minimum: %lli, maximum: %lli\n",sam*c,lam*C);
    return 0;
}