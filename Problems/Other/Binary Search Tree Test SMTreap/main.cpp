#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(ll(0), ll(1e18));
struct SMTreap{
    struct node{
        int data,sts;
        ll pri;
        node* l,*r;
        node(int d=0){data=d,sts=1,pri=dis(gen),l=nullptr,r=nullptr;}
        void calc(){
            sts=1;
            if(l)sts+=l->sts;
            if(r)sts+=r->sts;
        }
    };
    node* rt;
    SMTreap(){
        rt=nullptr;
    }
    int sts(node* c){return c?c->sts:0;}
    void split(node *c, int val, node *&l, node *&r){//>= to right
        if(!c){l=r=nullptr;return;}
        if(c->data>=val)split(c->l,val,l,c->l),r=c;
        else split(c->r,val,c->r,r),l=c;
        c->calc();
    }
    void merge(node*& c, node* l, node* r){
        if(!l||!r)c=l?l:r;
        else if(l->pri>=r->pri)merge(l->r,l->r,r),c=l;
        else merge(r->l,l,r->l),c=r;
        if(c)c->calc();
    }
    void insert(int val){
        node *te;
        split(rt,val,rt,te);
        merge(rt,rt,new node(val));
        merge(rt,rt,te);
    }
    void erase(int val){
        node *te,*te2;
        split(rt,val+1,rt,te);
        split(rt,val,rt,te2);
        if(te2)merge(te2,te2->l,te2->r);
        merge(rt,rt,te2);
        merge(rt,rt,te);
    }
    int ind(int val){
        node *te,*te2;
        split(rt,val+1,rt,te);
        split(rt,val,rt,te2);
        int ret=te2?sts(rt)+1:-1;
        merge(rt,rt,te2);
        merge(rt,rt,te);
        return ret;
    }
    int kth(int ind){return rt&&ind>=1&&ind<=sts(rt)?kth(ind,rt):-1;}
    int kth(int ind, node *c){
        if(sts(c)==1)return c->data;
        if(sts(c->l)>=ind)return kth(ind,c->l);
        if(sts(c->l)+1==ind)return c->data;
        return kth(ind-sts(c->l)-1,c->r);
    }
    void print(){print(rt);}
    void print(node *c){
        if(!c)return;
        print(c->l),printf("%d ",c->data),print(c->r);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a;
    for(int i=0;i<n;i++)cin>>a,tree.insert(a);
    int last=0;
    char t;
    while(m--){
        cin>>t>>a,a^=last;
        if(t=='I')tree.insert(a);
        else if(t=='R')tree.erase(a);
        else if(t=='S')printf("%d\n",last=tree.kth(a));
        else printf("%d\n",last=tree.ind(a));
    }
    tree.print();
    return 0;
}