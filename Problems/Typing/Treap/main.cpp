#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
mt19937_64 gen(23);
uniform_int_distribution<int> rnd(INT_MIN,INT_MAX);
struct treap{
    struct node{
        ll data,lazy,tdata;
        node *l,*r;
        int size,pri;
        node(ll a){
            data=a,tdata=a,lazy=0;
            l=nullptr,r=nullptr;
            size=1,pri=rnd(gen);
        }
        void apply(ll a){
            data+=a,lazy+=a,tdata+=a*size;
        }
        void prop(){
            if(l)l->apply(lazy);
            if(r)r->apply(lazy);
            lazy=0;
        }
        void calc(){
            prop();
            size=(l?l->size:0)+(r?r->size:0)+1;
            tdata=(l?l->tdata:0)+(r?r->tdata:0)+data;
        }
    };
    node *rt, *le, *ri, *mid;
    treap(){
        rt=nullptr,le=nullptr,ri=nullptr,mid=nullptr;
    }
    void split(node *root, node *&left, node *&right, ll val){
        if(root==nullptr){left=nullptr,right=nullptr;return;}
        root->prop();
        if(root->data<=val)split(root->r,root->r,right,val),left=root,left->calc();
        else split(root->l,left,root->l,val),right=root,right->calc();
    }
    void splitind(node *root, node *&left, node *&right, int ind){
        if(root==nullptr){left=nullptr,right=nullptr;return;}
        root->prop();
        if((root->l?root->l->size:0)+1<=ind)splitind(root->r,root->r,right,ind-((root->l?root->l->size:0)+1)),left=root,left->calc();
        else splitind(root->l,left,root->l,ind),right=root,right->calc();
    }
    void merge(node *&root, node *left, node *right){
        if(left==nullptr||right==nullptr){root=(left?left:right);return;}
        left->prop(),right->prop();
        if(left->pri>=right->pri)merge(left->r,left->r,right),root=left,left->calc();
        else merge(right->l,left,right->l),root=right,right->calc();
    }
    void insert(ll v){
        split(rt,le,ri,v);
        merge(le,le,new node(v)),merge(rt,le,ri);
    }
    void erase(ll v){
        split(rt,le,ri,v),split(le,le,mid,v-1);
        if(mid)merge(mid,mid->l,mid->r);
        merge(le,le,mid),merge(rt,le,ri);
    }
    ll ith(int ind){
        splitind(rt,le,ri,ind),splitind(le,le,mid,ind-1);
        ll retval=mid->data;
        merge(le,le,mid),merge(rt,le,ri);
        return retval;
    }
    int getind(ll v){
        split(rt,le,ri,v),split(le,le,mid,v-1);
        int retval=(mid?(le?le->size:0)+1:-1);
        merge(le,le,mid),merge(rt,le,ri);
        return retval;
    }
    void print(node *root){
        if(root==nullptr)return;
        print(root->l),printf("%lli ",root->data),print(root->r);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        tree.insert(a);
    }
    int lastans=0;
    char t;
    while(m--){
        cin>>t>>a,a^=lastans;
        if(t=='I')tree.insert(a);
        else if(t=='R')tree.erase(a);
        else if(t=='S')printf("%d\n",lastans=tree.ith(a));
        else printf("%d\n",lastans=tree.getind(a));
    }
    tree.print(tree.rt);
    return 0;
}