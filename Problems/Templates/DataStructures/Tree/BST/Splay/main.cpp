#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct Splay{
    struct node{
        int data,ts;
        node *p,*ch[2];
        node(int v){data=v,ts=1,p=nullptr,ch[0]=ch[1]=nullptr;}
        int dir(){return p?p->ch[1]==this:-1;}
        void calc(){ts=(ch[0]?ch[0]->ts:0)+(ch[1]?ch[1]->ts:0)+1;}
    };
    node* rt;
    Splay(){rt=nullptr;}
    int ts(node *x){return x?x->ts:0;}
    void connect(node *x, node *p, int d){
        if(x)x->p=p;
        if(p)p->ch[d]=x;
        else rt=x;
    }
    void rotate(node *x){
        int a=x->dir();node *p=x->p;
        connect(x->ch[!a],p,a);
        connect(x,p->p,p->dir());
        connect(p,x,!a);
        p->calc(),x->calc();
    }
    void splay(node* x){
        while(x!=rt){
            if(x->p==rt)rotate(x);
            else if(x->p->dir()==x->dir())rotate(x->p),rotate(x);
            else rotate(x),rotate(x);
        }
    }
    void insert(int v){
        node *t=rt,*p=nullptr,*x=new node(v);
        while(t)p=t,t=t->ch[x->data>=t->data];
        connect(x,p,p?x->data>=p->data:-1),(p?p->calc():void()),splay(x);
    }
    void erase(int v){
        node *t=rt,*p=nullptr;
        while(t&&t->data!=v)p=t,t=t->ch[v>=t->data];
        if(t){
            splay(t);
            if(!t->ch[0]||!t->ch[1]){
                rt=(t->ch[0]?t->ch[0]:t->ch[1]);
                if(rt)rt->p=nullptr;
            }
            else{
                rt=t->ch[0],rt->p=nullptr;
                node *te=rt;
                while(te->ch[1])te=te->ch[1];
                splay(te);
                connect(t->ch[1],te,1);
                te->calc();
            }
            delete t;
        }
        else if(p)splay(p);
    }
    void get(int i){
        node *t=rt;
        while(ts(t->ch[0])+1!=i)t=t->ch[i>ts(t->ch[0])],i-=(i>ts(t->p->ch[0])?ts(t->p->ch[0])+1:0);
        splay(t);
    }
    int ind(int v){
        int ans=-1,s=0;
        node *t=rt,*last=nullptr;
        while(t){
            if(t->data==v)ans=s+ts(t->ch[0])+1;
            last=t,s+=v>t->data?ts(t->ch[0])+1:0,t=t->ch[v>t->data];
        }
        if(last)splay(last);
        return ans;
    }
    void print(node *t){
        if(!t)return;
        print(t->ch[0]),printf("%d ",t->data),print(t->ch[1]);
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
        cin>>t>>a;
        a^=last;
        if(t=='I')tree.insert(a);
        else if(t=='R')tree.erase(a);
        else if(t=='S')tree.get(a),printf("%d\n",last=tree.rt->data);
        else printf("%d\n",last=tree.ind(a));
    }
    tree.print(tree.rt);
    return 0;
}