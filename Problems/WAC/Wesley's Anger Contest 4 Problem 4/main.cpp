#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
struct node{
    lli data,lazy;
    int dist,ch[2];
    node(lli d=0,lli l=0,int di=0,int ch0=0,int ch1=0){
        data=d,lazy=l,dist=di,ch[0]=ch0,ch[1]=ch1;
    }
    node clone(){
        return node(data,lazy,dist,ch[0],ch[1]);
    }
};
vector<node> t;
void rl(int a){
    t[a].data+=t[a].lazy;
    if(t[a].ch[0]&&t[a].lazy){
        int newnode=sz(t);
        t.push_back(t[t[a].ch[0]].clone());
        t[newnode].lazy+=t[a].lazy;
        t[a].ch[0]=newnode;
    }
    if(t[a].ch[1]&&t[a].lazy){
        int newnode=sz(t);
        t.push_back(t[t[a].ch[1]].clone());
        t[newnode].lazy+=t[a].lazy;
        t[a].ch[1]=newnode;
    }
    t[a].lazy=0;
}
int merge(int a, int b){
    if(a==0||b==0)return (a?a:b);
    rl(a),rl(b);
    if(t[a].data<t[b].data)swap(a,b);
    int newnode=sz(t);
    t.push_back(t[a].clone());
    int te=merge(t[newnode].ch[1],b);
    t[newnode].ch[1]=te;
    if(t[t[newnode].ch[1]].dist>t[t[newnode].ch[0]].dist)swap(t[newnode].ch[0],t[newnode].ch[1]);
    t[newnode].dist=t[t[newnode].ch[1]].dist+1;
    return newnode;
}
lli query(int a){
    rl(a);
    return t[a].data;
}
int pop(int a){
    rl(a);
    int te=merge(t[a].ch[0],t[a].ch[1]);
    int newnode=sz(t);
    t.push_back(node());
    t[newnode].dist=1;
    return merge(newnode,te);
}
struct nodearr{
    pair<pii,int> data;
    int ind;
    nodearr* l,*r;
    nodearr(pair<pii,int> d={{0,0},0},int i=0,nodearr* lt=NULL,nodearr* rt=NULL){
        data=d,ind=i,l=lt,r=rt;
    }
    void marr(int le, int ri){
        ind=(le+ri)/2;
        if(le!=ri){
            if(ind-1>=le){
                l=new nodearr();
                l->marr(le,ind-1);
            }
            if(ind+1<=ri){
                r=new nodearr();
                r->marr(ind+1,ri);
            }
        }
    }
    pair<pii,int> get(int id){
        if(ind==id)return data;
        if(id>ind)return r->get(id);
        else return l->get(id);
    }
    nodearr* set(int id, pair<pii,int> val){
        if(ind==id)return new nodearr(val,ind,l,r);
        if(id>ind)return new nodearr(data,ind,l,r->set(id,val));
        else return new nodearr(data,ind,l->set(id,val),r);
    }
};
vector<nodearr*> dsu;
int tim=0;
int find(int a){
    if(dsu[tim]->get(a).first.first==a)return a;
    auto te=dsu[tim]->get(a);
    int ret=find(te.first.first);
    dsu[tim]=dsu[tim]->set(a,{{ret,te.first.second},te.second});
    return ret;
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    auto aps=dsu[tim]->get(ap),bps=dsu[tim]->get(bp);
    if(aps.first.second<bps.first.second)swap(ap,bp),swap(aps,bps);
    dsu[tim]=dsu[tim]->set(ap,{{aps.first.first,aps.first.second+bps.first.second},merge(aps.second,bps.second)});
    dsu[tim]=dsu[tim]->set(bp,{{ap,bps.first.second},bps.second});
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    t.push_back(node());
    dsu.push_back(new nodearr());
    dsu.back()->marr(1,n);
    for(int i=1;i<=n;i++){
        t.push_back(node());
        cin>>t[i].data,t[i].dist=1;
        dsu.back()=dsu.back()->set(i,{{i,1},i});
    }
    lli last=0;
    lli a,b;
    lli type,from;
    while(q--){
        cin>>type>>from>>a;
        from^=last,a^=last;
        assert(from>=0&&from<=tim);
        assert(from==tim);
        tim++;
        assert(a>=1&&a<=n);
        dsu.push_back(dsu[from]);
        if(type==1){
            cin>>b;
            b^=last;
            assert(b>=1&&b<=n);
            uni(a,b);
        }
        else if(type==2){
            last=query(dsu[tim]->get(find(a)).second);
            printf("%lli\n",last);
            auto te=dsu[tim]->get(find(a));
            dsu[tim]=dsu[tim]->set(find(a),{te.first,pop(te.second)});
        }
        else{
            cin>>b;
            b^=last;
            assert(b>=1&&b<=1e9);
            auto te=dsu[tim]->get(find(a));
            dsu[tim]=dsu[tim]->set(find(a),{te.first,sz(t)});
            t.push_back(t[te.second].clone());
            t.back().lazy+=b;
        }
    }
    return 0;
}