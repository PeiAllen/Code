#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,a,b;
    cin>>n>>m>>k;
    set<int> rows,cols;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        if(rows.count(a))rows.erase(a);
        else rows.insert(a);
        if(cols.count(b))cols.erase(b);
        else cols.insert(b);
    }
    printf("%d\n",max(sz(rows),sz(cols)));
    while(sz(rows)||sz(cols)){
        int x=(sz(rows)?*rows.begin():1);
        int y=(sz(cols)?*cols.begin():1);
        printf("%d %d\n",x,y);
        rows.erase(x),cols.erase(y);
    }
    return 0;
}