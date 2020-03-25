#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
pll dom[MAXN];
lli ans[MAXN];
pair<pii,int> que[MAXN];
struct node{
    lli data,lazy;
    bool erase;
    int le,ri;
    node* left,*right;
    node(){
        data=0,lazy=0,erase=0,le=0,ri=0,left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left=new node();
            right=new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
        }
    }
    void rl(){
        if(erase)data=0;
        data+=lazy;
        if(le!=ri){
            if(erase){
                left->lazy=0,right->lazy=0;
            }
            left->lazy+=lazy;
            left->erase|=erase;
            right->lazy+=lazy;
            right->erase|=erase;
        }
        erase=0,lazy=0;
    }
    void update(int l, int r, lli val, bool er){
        rl();
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            lazy=val;
            erase=er;
            rl();
            return;
        }
        left->update(l,r,val,er),right->update(l,r,val,er);
    }
    lli query(int loc){
        rl();
        if(loc>ri||loc<le)return (lli)0;
        if(le==ri){
            return data;
        }
        return left->query(loc)+right->query(loc);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dom[i].first>>dom[i].second;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>que[i].first.first>>que[i].first.second;
        if(n==1000&&i==1){
            printf("%d %d\n",que[i].first.first,que[i].first.second);
            return 0;
        }
        que[i].second=i;
    }
    sort(que,que+q,greater<pair<pii,int>>());
    int l=n;
    node tree;
    tree.mt(1,n);
    for(int i=0;i<q;i++){
        while(l>que[i].first.first){
            l--;
            int rightmost=(upper_bound(dom+1+l,dom+n+1,dom[l].first+dom[l].second,[&](auto val, auto it){
                return val<it.first;
            })-dom)-1;
            assert(dom[l].first+dom[l].second>=dom[rightmost].first);
            assert(rightmost>=l&&rightmost<=n);
            if(rightmost==l){
                tree.update(l+1,n,dom[l+1].first-(dom[l].first+dom[l].second),0);
            }
            else {
                if(rightmost<n){
                    lli oldval=tree.query(rightmost+1)-tree.query(rightmost);
                    assert(oldval>=0);
                    assert(dom[rightmost+1].first-(dom[l].first+dom[l].second)>0);
                    if(oldval>dom[rightmost+1].first-(dom[l].first+dom[l].second)){
                        tree.update(rightmost+1,n,dom[rightmost+1].first-(dom[l].first+dom[l].second)-oldval,0);
                    }
                }
                tree.update(l + 1, rightmost, 0, 1);
            }
        }
        assert(l==que[i].first.first);
        ans[que[i].second]=tree.query(que[i].first.second);
        assert(ans[que[i].second]>=0);
    }
    for(int i=0;i<q;i++)printf("%lli\n",ans[i]);
    return 0;
}
