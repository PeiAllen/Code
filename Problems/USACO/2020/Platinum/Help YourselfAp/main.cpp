#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli mod=1e9+7;
inline lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
struct node {
    lli data, lazy;
    int le, ri;
    node() {
        data = 0;
        lazy = 1;
        le = 0;
        ri = 0;
    }

    int mid() { return (le + ri) / 2; }
};
node seg[11][MAXN*5];
    void mt(int l,int r, int ind, int loc){
        seg[loc][ind].le=l,seg[loc][ind].ri=r;
        if(seg[loc][ind].le!=seg[loc][ind].ri){
            mt(seg[loc][ind].le,seg[loc][ind].mid(),(ind<<1),loc);
            mt(seg[loc][ind].mid()+1,seg[loc][ind].ri,(ind<<1)|1,loc);
        }
    }
    void rl(int ind, int loc){
        seg[loc][ind].data=seg[loc][ind].data*seg[loc][ind].lazy%mod;
        if(left){
            seg[loc][ind<<1].lazy=seg[loc][ind<<1].lazy*seg[loc][ind].lazy%mod;
            seg[loc][(ind<<1)|1].lazy=seg[loc][(ind<<1)|1].lazy*seg[loc][ind].lazy%mod;
        }
        seg[loc][ind].lazy=1;
    }
    void rupdate(int l, int r,int ind, int loc){
        rl(ind,loc);
        if(l>seg[loc][ind].ri||r<seg[loc][ind].le)return;
        if(seg[loc][ind].le>=l&&seg[loc][ind].ri<=r){
            seg[loc][ind].lazy=2;
            rl(ind,loc);
            return;
        }
        rupdate(l,r,ind<<1,loc),rupdate(l,r,(ind<<1)|1,loc);
        seg[loc][ind].data=fix(seg[loc][ind<<1].data+seg[loc][(ind<<1)|1].data);
    }
    void update(int a, int val,int ind, int loc){
        rl(ind,loc);
        if(a>seg[loc][ind].ri||a<seg[loc][ind].le)return;
        if(seg[loc][ind].le>=a&&seg[loc][ind].ri<=a){
            seg[loc][ind].data=fix(seg[loc][ind].data+val);
            return;
        }
        update(a,val,ind<<1,loc),update(a,val,(ind<<1)|1,loc);
        seg[loc][ind].data=fix(seg[loc][ind<<1].data+seg[loc][(ind<<1)|1].data);
    }
    lli query(int l,int r,int ind, int loc){
        rl(ind,loc);
        if(l>seg[loc][ind].ri||r<seg[loc][ind].le)return 0;
        if(seg[loc][ind].le>=l&&seg[loc][ind].ri<=r)return seg[loc][ind].data;
        return fix(query(l,r,ind<<1,loc)+query(l,r,(ind<<1)|1,loc));
    }

pii arr[MAXN];
lli precalc[11];
lli dp[11][11];
lli curexp[11];
lli choose(int a, int b){
    if(a==b||b==0)return 1;
    if(dp[a][b]!=-1)return dp[a][b];
    return dp[a][b]=fix(choose(a-1,b-1)+choose(a-1,b));
}
vector<int> coord;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    set<int> ends;
    precalc[0]=1;
    for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)dp[i][j]=-1;
    for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)choose(i,j);
    for(int i=1;i<=k;i++){
        precalc[i]=precalc[i-1]*2%mod;
    }
    ends.insert(0);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        ends.insert(arr[i].second);
    }
    sort(arr,arr+n);
    for(int x:ends)coord.push_back(x);
    for(int i=0;i<=k;i++){
        mt(1,sz(coord),1,i);
    }
    update(1,1,1,k);
    lli ans=0;
    for(int i=0;i<n;i++){
        int cur=(lower_bound(coord.begin(),coord.end(),arr[i].first)-coord.begin())+1;
        int en=(lower_bound(coord.begin(),coord.end(),arr[i].second)-coord.begin())+1;
        lli te;
        if(cur<=sz(coord))ans=fix(ans+query(cur,sz(coord),1,0));
        for(int j=0;j<=k;j++) {
            if(cur<=en)update(en,query(cur,en,1,j),1,j);//cur->en
            if(en+1<=sz(coord))rupdate(en+1,sz(coord),1,j);//en + 1->sz(coord)
        }
        for(int j=0;j<=k;j++){
            te=choose(k,j)*query(1,cur-1,1,j)%mod;//left query
            ans=fix(ans+te);
        }
        for(int j=0;j<=k;j++)curexp[j]=query(1,cur-1,1,j);
        for(int j=k;j>=0;j--){
            lli toup=0;
            for(int l=0;l<=k-j;l++) {
                 toup=fix(toup+(choose(k-j,l)*curexp[k-l]%mod));//left move update
            }
            update(en,toup,1,j);
        }
    }
    printf("%lli\n",ans);
    return 0;
}
/*
3 2
1 2
2 3
3 4

4 2
1 2
2 3
3 4
4 5

4 2
1 4
2 3
6 7
1 7

7 2
1 2
3 5
1 2
3 10
7 12
3 100
20 30

5 2
1 2
3 5
1 2
3 10
7 12

6 2
1 2
3 5
1 2
3 10
7 12
20 30

4 2
1 2
3 4
5 6
7 8
 */
