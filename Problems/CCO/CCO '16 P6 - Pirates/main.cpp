#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(INT_MIN,INT_MAX);
struct treap{
    struct node{
        node *l,*r;
        ll data,lazyset,lazyadd,datasum;
        int size,pri;
        node(ll v){
            lazyset=LLONG_MIN,size=1,data=v,lazyadd=0,datasum=v,pri=dis(gen);
            l=nullptr,r=nullptr;
        }
        void apply(ll set, ll add){
            if(set!=LLONG_MIN){
                data=set+add;
                datasum=(set+add)*size;
                lazyset=set,lazyadd=add;
            }
            else{
                data+=add,datasum+=add*size;
                lazyadd+=add;
            }
        }
        void prop(){
            if(l)l->apply(lazyset,lazyadd);
            if(r)r->apply(lazyset,lazyadd);
            lazyset=LLONG_MIN,lazyadd=0;
        }
        void calc(){
            prop();
            size=1+(l?l->size:0)+(r?r->size:0);
            datasum=data+(l?l->datasum:0)+(r?r->datasum:0);
        }
    };
    node *rt,*le,*ri,*mid;
    treap(){
        rt=nullptr,le=nullptr,ri=nullptr,mid=nullptr;
    }
    void split(node *cur, node *&left, node *&right, ll val){
        if(cur==nullptr){left=nullptr,right=nullptr;return;}
        cur->prop();
        if(cur->data<=val)split(cur->r,cur->r,right,val),left=cur,left->calc();
        else split(cur->l,left,cur->l,val),right=cur,right->calc();
    }
    void splitind(node *cur, node *&left, node *&right, int ind){
        if(cur==nullptr){left=nullptr,right=nullptr;return;}
        cur->prop();
        if((cur->l?cur->l->size:0)+1<=ind)splitind(cur->r,cur->r,right,ind-((cur->l?cur->l->size:0)+1)),left=cur,left->calc();
        else splitind(cur->l,left,cur->l,ind),right=cur,right->calc();
    }
    void merge(node *&root, node *left, node *right){
        if(left==nullptr||right==nullptr)root=(left?left:right);
        else if(left->pri>right->pri)left->prop(),merge(left->r,left->r,right),root=left,root->calc();
        else right->prop(),merge(right->l,left,right->l),root=right,root->calc();
    }
    void insert(ll v){
        node *cur=new node(v);
        split(rt,le,ri,v);
        merge(le,le,cur),merge(rt,le,ri);
    }
    ll querysum(int l, int r){
        if(l>r)return 0;
        splitind(rt,le,ri,r),splitind(le,le,mid,l-1);
        ll retval=mid->datasum;
        merge(le,le,mid),merge(rt,le,ri);
        return retval;
    }
    void update(int ind){
        splitind(rt,le,ri,ind);
        if(le)le->apply(LLONG_MIN,1);
        if(ri)ri->apply(0,0);
        merge(rt,ri,le);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
        ll am=tree.querysum(1,a-1)+(a-1);
        if(am<=k){
            printf("%lli\n",k-am);
            tree.update(a-1);
            tree.insert(k-am);
        }
        else{
            tree.insert(-1);
            printf("-1\n");
        }
    }
    return 0;
}