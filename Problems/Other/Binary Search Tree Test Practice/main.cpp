#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
uniform_int_distribution<ll> rnd(LLONG_MIN,LLONG_MAX);
mt19937_64 gen;
struct treap{
    struct node{
        node *l,*r;
        int data,size;
        ll prio;
        node(int d=0){
            prio=rnd(gen);
            data=d;
            size=1;
            l=nullptr,r=nullptr;
        }
    };
    node *root,*left,*right;

    treap(){
        root=nullptr,left=nullptr,right=nullptr;
    }

    void recalc(node *rt){
        if(!rt)return;
        rt->size=(rt->l?rt->l->size:0)+(rt->r?rt->r->size:0)+1;
    }

    void split(node *rt, node *&le, node *&ri, int val){//<=val goes left
        if(!rt)le=nullptr,ri=nullptr;
        else if(rt->data<=val)split(rt->r,rt->r,ri,val),le=rt;
        else split(rt->l,le,rt->l,val),ri=rt;
        recalc(rt);
    }

    void splitind(node *rt, node *&le, node *&ri, int ind){//<=ind goes left
        if(!rt)le=nullptr,ri=nullptr;
        else if((rt->l?rt->l->size:0)+1<=ind)splitind(rt->r,rt->r,ri,ind-((rt->l?rt->l->size:0)+1)),le=rt;
        else splitind(rt->l,le,rt->l,ind),ri=rt;
        recalc(rt);
    }

    void merge(node *&rt, node *le, node *ri) {
        if (!le || !ri)rt = (le ? le : ri);
        else if (le->prio > ri->prio)merge(le->r, le->r, ri), rt = le;
        else merge(ri->l,le,ri->l),rt=ri;
        recalc(rt);
    }

    void insert(int x){
        node *te = new node(x);
        split(root,left,right,x);
        merge(left,left,te),merge(root,left,right);
    }

    void erase(int x){
        split(root,left,right,x);
        split(left,left,root,x-1);
        node *te=root;
        if(root)merge(root,root->l,root->r);
        delete te;
        merge(left,left,root),merge(root,left,right);
    }

    int kth(int ind){
        splitind(root,left,right,ind);
        splitind(left,left,root,ind-1);
        int retval;
        if(!root)retval = -1;
        retval=root->data;
        merge(left,left,root),merge(root,left,right);
        return retval;
    }

    int first(int x){
        split(root,left,right,x);
        split(left,left,root,x-1);
        int retval;
        if(!root)retval=-1;
        else retval=(left?left->size:0)+1;
        merge(left,left,root),merge(root,left,right);
        return retval;
    }

    void print(node *rt){
        if(!rt)return;
        print(rt->l);
        printf("%d ",rt->data);
        print(rt->r);
    }

    void print(){
        print(root);
    }

}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    gen.seed(time(NULL));
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        tree.insert(a);
    }
    char c;
    int lastans=0;
    while(m--){
        cin>>c>>a;
        a^=lastans;
        if(c=='I')tree.insert(a);
        else if(c=='R')tree.erase(a);
        else if(c=='S')printf("%d\n",lastans=tree.kth(a));
        else printf("%d\n",lastans=tree.first(a));
    }
    tree.print();
    return 0;
}