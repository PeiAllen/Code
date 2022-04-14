#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1001;
pii dsu[MN];
int find(int a){
    if(dsu[a].A==a)return a;
    return dsu[a].A=find(dsu[a].A);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].B<dsu[bp].B)swap(ap,bp);
    dsu[ap].B+=dsu[bp].B;
    dsu[bp].A=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q,a,b;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a;
            uni(j,a);
        }
    }
    while(q--){
        cin>>a>>b;
        if(find(a)==find(b))printf("DA\n");
        else printf("NE\n");
    }
    return 0;
}