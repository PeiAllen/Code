#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=21;
pii dsu[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc, argv, 1);
    int n=20,m=rnd.next(19,50);
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    for(int i=1;i<=19;i++){
        int a=rnd.next(1,20),b=rnd.next(1,20);
        if(find(a)!=find(b)){
            uni(a,b);
            printf("%d %d\n",a,b);
        }
        else i--;
    }
    for(int j=20;j<=m;j++){
        int a=rnd.next(1,20),b=rnd.next(1,20);
        printf("%d %d\n",a,b);
    }
    return 0;
}