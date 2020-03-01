#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli mod=1e9+7;
lli fix(lli a){
    while(a<0)a+=mod;
    return a%mod;
}
struct node{
    lli data,lazy;
    int le,ri;
    struct node *left,*right;
    node(){
        data=0;
        lazy=1;
        le=0;
        ri=0;
        left=NULL;
        right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l,int r){
        le=l,ri=r;
        if(le!=ri){
            left = new node();
            right = new node();
            left->mt(le,mid());
            right->mt(mid()+1,ri);
        }
    }
    void rl(){
        data=fix(data*lazy);
        if(left){
            left->lazy=fix(left->lazy*lazy);
            right->lazy=fix(right->lazy*lazy);
        }
        lazy=1;
    }
    void rupdate(int l, int r){
        rl();
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            lazy=2;
            rl();
            return;
        }
        left->rupdate(l,r),right->rupdate(l,r);
        data=fix(left->data+right->data);
    }
    void update(int loc, int val){
        rl();
        if(loc>ri||loc<le)return;
        if(le>=loc&&ri<=loc){
            data=fix(data+val);
            return;
        }
        left->update(loc,val),right->update(loc,val);
        data=fix(left->data+right->data);
    }
    lli query(int l,int r){
        rl();
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return data;
        return fix(left->query(l,r)+right->query(l,r));
    }
};
pii arr[MAXN];
node seg[11];
lli precalc[11];
lli dp[11][11];

lli choose(int a, int b){
    if(a==b||b==0)return 1;
    if(dp[a][b]!=-1)return dp[a][b];
    return dp[a][b]=fix(choose(a-1,b-1)+choose(a-1,b));
}
vector<int> coord;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("C:\\Users\\allen\\Downloads\\help_platinum_feb20\\11.in", "r", stdin);
    freopen("answer.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    set<int> ends;
    precalc[0]=1;
    for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)dp[i][j]=-1;
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
        seg[i].mt(1,sz(coord));
    }
    seg[k].update(1,1);
    lli ans=0;
    for(int i=0;i<n;i++){
        int cur=(lower_bound(coord.begin(),coord.end(),arr[i].first)-coord.begin())+1;
        int en=(lower_bound(coord.begin(),coord.end(),arr[i].second)-coord.begin())+1;
        lli te;
        if(cur<=sz(coord))ans=fix(ans+seg[0].query(cur,sz(coord)));
        for(int j=0;j<=k;j++) {
            if(cur<=en)seg[j].update(en,seg[j].query(cur,en));//cur->en
            if(en+1<=sz(coord))seg[j].rupdate(en+1,sz(coord));//en + 1->sz(coord)
        }
        for(int j=0;j<=k;j++){
            te=fix(choose(k,j)*seg[j].query(1,cur-1));//left query
            ans=fix(ans+te);
        }
        for(int j=k;j>=0;j--){
            lli toup=0;
            for(int l=0;l<=k-j;l++) {
                 toup=fix(toup+fix(choose(k-j,l)*seg[k-l].query(1,cur-1)));//left move update
            }
            seg[j].update(en,toup);
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
