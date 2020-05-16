#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
int arr[MAXN];
random_device rd;
struct treap{
    struct item {
        int key, cnt;
        unsigned int prior;
        item * l, * r;
        item() { }
        item (int key, unsigned int prior) : key(key), prior(prior), l(NULL), r(NULL),cnt(0) { }
    };
    typedef item * pitem;
    int cnt (pitem t) {
        return t ? t->cnt : 0;
    }

    void upd_cnt (pitem t) {
        if (t)
            t->cnt = 1 + cnt(t->l) + cnt (t->r);
    }
    void split (pitem t, int key, pitem & l, pitem & r) {
        if (!t)
            l = r = NULL;
        else if (key < t->key)
            split (t->l, key, l, t->l),  r = t;
        else
            split (t->r, key, t->r, r),  l = t;
        upd_cnt(t);
    }

    void insert (pitem & t, pitem it) {
        if (!t)
            t = it;
        else if (it->prior > t->prior)
            split (t, it->key, it->l, it->r),  t = it;
        else
            insert (it->key < t->key ? t->l : t->r, it);
        upd_cnt(t);
    }
    int query(pitem it, int val){
        if(!it)return 0;
        if(it->key>=val)return query(it->l,val)+cnt(it->r)+1;
        return query(it->r,val);
    }
    item* root;
    treap(){
        root=NULL;
    }
    void insertt(int x){
        insert(root,new item(x,rd()));
    }
    int queryy(int x){
        return query(root,x);
    }
    int getsz(){
        return cnt(root);
    }
};
struct seg{
    struct node2 {
        treap data1,data2;
        node2(){
            data1= treap(),data2= treap();
        }
    }t[2*MAXN];
    void update(int ind, int le, int ri, int l, int r, int val, bool larger){
        if(l>r)return;
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            if(larger)t[ind].data1.insertt(val);
            else t[ind].data2.insertt(val);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val,larger),update(right,mid+1,ri,l,r,val,larger);
    }
    lli query(int ind, int le, int ri, int loc, int val){
        if(loc>ri||loc<le)return 0;
        if(le==ri){
            return t[ind].data1.queryy(val+1)+t[ind].data2.getsz()-t[ind].data2.queryy(val);
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        lli am=t[ind].data1.queryy(val+1)+t[ind].data2.getsz()-t[ind].data2.queryy(val);
        return am+query(left,le,mid,loc,val)+query(right,mid+1,ri,loc,val);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    lli inv=0;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        inv+=tree.query(0,1,n,a,arr[a]);
        tree.update(0,1,n,1,a-1,arr[a],0);
        tree.update(0,1,n,a+1,n,arr[a],1);
        printf("%lli\n",inv);
    }
    return 0;
}