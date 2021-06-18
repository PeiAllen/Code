#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
pii dsu[MN];
int get(int a){
    return dsu[a].first==a?0:dsu[a].second;
}
int find(int a){
    if(dsu[a].first==a)return a;
    int te=find(dsu[a].first);
    dsu[a].second^=get(dsu[a].first);
    dsu[a].first=te;
    return te;
}
bool uni(int a, int b, int rel){
    int ap=find(a),bp=find(b);
    if(ap==bp){
        return 1^get(a)^get(b)^rel;
    }
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp),swap(a,b);
    dsu[bp].second=get(a)^get(b)^rel;
    dsu[bp].first=ap;
    dsu[ap].second+=dsu[bp].second;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    char a;
    int b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(!uni(b,c,a=='D')){
            printf("0\n");
            return 0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(find(i)==i){
        ans++;
    }
    printf("1");
    while(ans--)printf("0");
    return 0;
}