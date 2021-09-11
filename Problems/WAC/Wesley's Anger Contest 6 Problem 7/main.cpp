#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct node{
    int data,ts,td;
    node *p,*ch[2];
    node(int v){data=v,ts=1,p=nullptr,ch[0]=ch[1]=nullptr,td=v;}
    int dir(){return p?p->ch[1]==this:-1;}
    void calc(){ts=(ch[0]?ch[0]->ts:0)+(ch[1]?ch[1]->ts:0)+1,td=max({(ch[0]?ch[0]->td:0),(ch[1]?ch[1]->td:0),data});}
};
struct Splay{
    node* rt;
    Splay(){rt=nullptr;}
    int td(node *x){return x?x->td:0;}
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
    node* insert(int v, int dir){
        node *t=rt->ch[dir],*p=rt,*x=new node(v);
        while(t)p=t,t=t->ch[!dir];
        connect(x,p,(p==rt?dir:!dir)),(p?p->calc():void()),splay(x);
        return x;
    }
    int query(node *l, node *r){
        splay(l);
        int ans=max(r->data,(r==rt?0:td(r->ch[0])));
        while(r!=rt){
            if(r->dir()==1)ans=max({ans,r->p->data,(r->p==rt?0:td(r->p->ch[0]))});
            r=r->p;
        }
        splay(r);
        return ans;
    }
}tree;
struct SAM{
    int last;
    struct state{
        node* st,*en;
        map<int,int> t;
        int len,link;
        state(int l){
            t={},len=l,link=-1,st=nullptr,en=nullptr;
        }
    };
    vector<state> t;
    SAM(){
        t={state(0)},t[0].st=tree.rt=new node(0),t[0].en=tree.insert(0,1);
        last=0;
    }
    void addnode(int ch, int p, int v){
        tree.splay(t[p].st);
        t[ch].st=tree.insert(v,1);
        t[ch].en=tree.insert(v,1);
    }
    void addchar(int c, int v){
        int cur=sz(t);
        t.push_back(state(t[last].len+1));
        while(last!=-1&&!t[last].t.count(c))t[last].t[c]=cur,last=t[last].link;
        if(last==-1)t[cur].link=0;
        else{
            int oth=t[last].t[c];
            if(t[last].len+1==t[oth].len)t[cur].link=oth;
            else{
                t.push_back(state(t[last].len+1));
                t.back().link=t[oth].link,t[oth].link=sz(t)-1,t[cur].link=sz(t)-1,t.back().t=t[oth].t;
                tree.splay(t[oth].st),t.back().st=tree.insert(max(t[oth].st->data,v),0);
                tree.splay(t[oth].en),t.back().en=tree.insert(max(t[oth].st->data,v),1);
                while(last!=-1&&t[last].t[c]==oth)t[last].t[c]=sz(t)-1,last=t[last].link;
            }
        }
        addnode(cur,t[cur].link,v);
        last=cur;
    }
    int query(const vector<int> &a){
        int cur=0;
        for(auto x:a){
            if(!t[cur].t.count(x))return 0;
            cur=t[cur].t[x];
        }
        return tree.query(t[cur].st,t[cur].en);
    }
}solver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int r,k,last,a,oneans=0;
    for(int i=0;i<n;i++){
        cin>>r>>k>>last,oneans=max(oneans,r);
        for(int j=1;j<k;j++)cin>>a,solver.addchar(a-last,r),last=a;
        solver.addchar(1e9,0);
    }
    int lastans=0;
    while(q--){
        cin>>a;
        if(a==1){
            cin>>r>>k>>last,last^=lastans,oneans=max(oneans,r);
            for(int i=1;i<k;i++)cin>>a,a^=lastans,solver.addchar(a-last,r),last=a;
            solver.addchar(1e9,0);
        }
        else{
            cin>>k>>last,last^=lastans;
            if(k==1)printf("%d\n",lastans=oneans);
            else{
                vector<int> te;
                for(int i=1;i<k;i++)cin>>a,a^=lastans,te.push_back(a-last),last=a;
                printf("%d\n",lastans=solver.query(te));
            }
        }
    }
    return 0;
}