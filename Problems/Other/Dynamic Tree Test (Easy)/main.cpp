#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
template<typename T> struct LCT{
    const static T def=0,bad=LLONG_MIN;
    static T F(T a, T b){return a+b;}//sum for this one(need to change apply if funciton changed)
    struct node{
        int s;
        bool rev;
        T d,psum,pmin,pmax,lazyset,lazyinc;
        node *p,*ch[2];
        node(){d=def,psum=def,pmin=def,pmax=def,lazyset=bad,lazyinc=0,rev=false,s=1,p=nullptr,ch[0]=ch[1]=nullptr;}
        node(int v){d=v,psum=v,pmin=v,pmax=v,lazyset=bad,lazyinc=0,rev=false,s=1,p=nullptr,ch[0]=ch[1]=nullptr;}
        int dir(){return p&&(p->ch[0]==this||p->ch[1]==this)?p->ch[1]==this:-1;}
        void apply(T set,T inc, bool r){
            rev^=r;
            if(r)swap(ch[0],ch[1]);
            if(set!=bad)lazyset=set,lazyinc=def,d=set,psum=set*T(s),pmin=set,pmax=set;
            lazyinc+=inc,d+=inc,psum+=inc*T(s),pmin+=inc,pmax+=inc;
        }
        void prop(){
            if(ch[0])ch[0]->apply(lazyset,lazyinc,rev);
            if(ch[1])ch[1]->apply(lazyset,lazyinc,rev);
            lazyset=bad,lazyinc=0,rev=false;
        }
        void calc(){
            s=(ch[0]?ch[0]->s:0)+(ch[1]?ch[1]->s:0)+1;
            psum=(d+(ch[0]?ch[0]->psum:0)+(ch[1]?ch[1]->psum:0));
            pmin=min({d,(ch[0]?ch[0]->pmin:LLONG_MAX),(ch[1]?ch[1]->pmin:LLONG_MAX)});
            pmax=max({d,(ch[0]?ch[0]->pmax:LLONG_MIN),(ch[1]?ch[1]->pmax:LLONG_MIN)});
        }
        bool isroot(){return !p||(p->ch[0]!=this&&p->ch[1]!=this);}
    };
    vector<node> t;
    LCT(int n){t.resize(n+1);}
    void nn(int ind,T v){t[ind]=node(v);}
    int ts(node *x){return x?x->s:0;}
    int vert(node *x){return x-t.data();}
    void connect(node *x, node *p, int d){
        if(x)x->p=p;
        if(p&&d!=-1)p->ch[d]=x;
    }
    void rotate(node *x){
        int a=x->dir();node *p=x->p;
        connect(x->ch[!a],p,a);
        connect(x,p->p,p->dir());
        connect(p,x,!a);
        p->calc(),x->calc();
    }
    void splay(node *x){
        while(!x->isroot()){
            if(!x->p->isroot())x->p->p->prop();
            x->p->prop(),x->prop();
            if(!x->p->isroot())rotate(x->p->dir()==x->dir()?x->p:x);
            rotate(x);
        }
        x->prop();
    }
    node* access(node *x){
        splay(x),x->ch[1]=nullptr,x->calc();
        node *last=x;
        while(x->p)splay(x->p),last=x->p,x->p->ch[1]=x,x->p->calc(),splay(x);
        return last;
    }
    node* get(node *x,int i){
        x->prop();
        while(ts(x->ch[0])+1!=i)x=x->ch[i>ts(x->ch[0])],x->prop(),i-=(i>ts(x->p->ch[0])?ts(x->p->ch[0])+1:0);
        splay(x);
        return x;
    }
    void makeroot(int x){
        access(&t[x]);
        t[x].apply(bad,0,1);
    }
    int getroot(int x){
        access(&t[x]);
        return vert(get(&t[x],1));
    }
    int lca(int a, int b){
        if(a==b)return a;
        access(&t[a]);
        node* te=access(&t[b]);
        return t[a].p?vert(te):-1;
    }
    T pathval(int x){
        access(&t[x]);
        return t[x].td;
    }
    bool cut(int x){
        access(&t[x]);
        if(!t[x].ch[0])return false;
        t[x].ch[0]=t[x].ch[0]->p=nullptr,t[x].calc();
        return true;
    }
    bool link(int ch, int p){
        int old=getroot(p);
        makeroot(ch);
        access(&t[ch]),access(&t[p]);
        if(t[ch].p){makeroot(old);return false;}
        t[ch].ch[0]=&t[p],t[p].p=&t[ch],t[ch].calc();
        makeroot(old);return true;
    }
    bool updatepath(int a, int b, T set, T inc){
        int old=getroot(a);
        makeroot(a),access(&t[b]);
        if(a!=b&&!t[a].p){makeroot(old);return false;}
        t[b].apply(set,inc,0);makeroot(old);return true;
    }
    T querypath(int a, int b, int type){
        int old=getroot(a);
        makeroot(a),access(&t[b]);
        T ans;
        if(type==0)ans=(a==b||t[a].p?t[b].pmin:bad);
        else if(type==1)ans=(a==b||t[a].p?t[b].pmax:bad);
        else if(type==2)ans=(a==b||t[a].p?t[b].psum:bad);
        else ans=bad;
        makeroot(old);return ans;
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    LCT<ll> tree(n);
    ll a,b,c,d;
    for(int i=1;i<=n;i++)cin>>a,tree.updatepath(i,i,a,0);
    for(int i=1;i<n;i++){
        cin>>a>>b;
        tree.link(a,b);
    }
    cin>>a;
    tree.makeroot(a);
    while(m--){
        cin>>a>>b;
        if(a==0)tree.makeroot(b);
        else if(a==1){
            cin>>c>>d;
            tree.updatepath(b,c,d,0);
        }
        else if(a==2){
            cin>>c>>d;
            tree.updatepath(b,c,LLONG_MIN,d);
        }
        else if(a>=3&&a<=5){
            cin>>c;
            printf("%lli\n",tree.querypath(b,c,a-3));
        }
        else if(a==6){
            cin>>c;
            if(tree.lca(b,c)!=b)tree.cut(b),tree.link(b,c);
        }
        else{
            cin>>c;
            printf("%d\n",tree.lca(b,c));
        }
    }
    return 0;
}