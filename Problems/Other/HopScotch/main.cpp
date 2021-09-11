#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
template<typename T, const T def, const int N> struct LCT{
    static T F(T a, T b){return a+b;}
    struct node{
        int s;
        T d,td;
        node *p,*ch[2];
        node(){d=def,td=def,s=1,p=nullptr,ch[0]=ch[1]=nullptr;}
        node(int v){d=v,td=v,s=1,p=nullptr,ch[0]=ch[1]=nullptr;}
        int dir(){return p&&(p->ch[0]==this||p->ch[1]==this)?p->ch[1]==this:-1;}
        void calc(){s=(ch[0]?ch[0]->s:0)+(ch[1]?ch[1]->s:0)+1,td=F(d,F(ch[0]?ch[0]->td:def,ch[1]?ch[1]->td:def));}
        bool isroot(){return !p||(p->ch[0]!=this&&p->ch[1]!=this);}
    };
    node t[N];
    void nn(int ind,T v){t[ind]=node(v);}
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
            if(x->p->isroot())rotate(x);
            else if(x->p->dir()==x->dir())rotate(x->p),rotate(x);
            else rotate(x),rotate(x);
        }
    }
    void access(node *x){
        splay(x);
        if(x->ch[1])x->ch[1]=nullptr,x->calc();
        while(x->p)splay(x->p),x->p->ch[1]=x,x->p->calc(),splay(x);
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
        access(&t[ch]),access(&t[p]);
        if(t[ch].p)return false;
        t[ch].ch[0]=&t[p],t[p].p=&t[ch],t[ch].calc();
        return true;
    }
};
LCT<int,0,MN> solver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)solver.nn(i,1);
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        solver.link(i,min(n,i+a));
    }
    int q;
    cin>>q;
    int b,c;
    while(q--){
        cin>>a>>b;
        if(a==1)printf("%d\n",solver.pathval(b)-1);
        else{
            cin>>c;
            solver.cut(b);
            solver.link(b,min(n,b+c));
        }
    }
    return 0;
}