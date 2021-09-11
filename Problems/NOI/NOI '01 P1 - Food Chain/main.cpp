#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e4+1;
int parrel[MAXN];
int par[MAXN];
int dsusize[MAXN];
int find(int a){
    if(par[a]==a)return a;
    int rt=find(par[a]);
    parrel[a]=(parrel[a]+parrel[par[a]])%3;
    par[a]=rt;
    return rt;
}
int rtrel(int a){
    find(a);
    return parrel[a];
}
bool uni(int a, int b, int type){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    int mut=1;
    if(dsusize[bp]>dsusize[ap])swap(ap,bp),mut=-1;
    parrel[bp]=((mut*(rtrel(a)-rtrel(b)+(type-1))%3)+3)%3;
    par[bp]=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)parrel[i]=0,par[i]=i,dsusize[i]=1;
    int a,b,c;
    int cnt=0;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c;
        if(b>n||c>n)cnt++;
        else if(a==2&&b==c)cnt++;
        else if(!uni(b,c,a)&&(((rtrel(c)-rtrel(b))%3)+3)%3!=(a-1))cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}