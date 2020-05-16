#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
struct node{
    int data,size;
    int prio;
    node* l,*r;
    node(int d,int p){
        data=d,size=1,prio=p,l=NULL,r=NULL;
    }
    void calc(){size=1+(l?l->size:0)+(r?r->size:0);}
};
struct Treap{
    node *root;
    Treap(){
        root=NULL;
    }
    int gtsz(node* cur){
        return (cur?cur->size:0);
    }
    void split(node* cur,node*& l, node*& r, int mid){
        if(!cur)l=r=NULL;
        else if(cur->data>=mid)split(cur->l,l,cur->l,mid),r=cur;
        else split(cur->r,cur->r,r,mid),l=cur;
        if(cur)cur->calc();
    }
    void merge(node*& rt,node* l, node* r){
        if(!l||!r)rt=(l?l:r);
        else if(l->prio>r->prio)rt=l,merge(l->r,l->r,r);
        else rt=r,merge(r->l,l,r->l);
        if(rt)rt->calc();
    }
    void insert(node*& cur,node* ne){
        if(!cur)cur=ne;
        else if(cur->prio<ne->prio)split(cur,ne->l,ne->r,ne->data),cur=ne;
        else insert(ne->data>=cur->data?cur->r:cur->l,ne);
        cur->calc();
    }
    void insert(node* ne){insert(root,ne);}
    void erase(node*& cur,int val){
        if(!cur)return;
        if(cur->data==val)merge(cur,cur->l,cur->r);
        else erase(val>cur->data?cur->r:cur->l,val);
        if(cur)cur->calc();
    }
    void erase(int val){erase(root,val);}
    int at(node* cur,int ind){
        if(!cur)return -1;
        if(gtsz(cur->l)+1==ind)return cur->data;
        if(gtsz(cur->l)+1<ind)return at(cur->r,ind-gtsz(cur->l)-1);
        return at(cur->l,ind);
    }
    int at(int ind){return at(root,ind);}
    int find(node* cur,int val){
        if(!cur)return -1;
        if(cur->data==val)return gtsz(cur->l)+1;
        if(val>cur->data){
            int te=find(cur->r,val);
            return (te==-1?te:te+gtsz(cur->l)+1);
        }
        return find(cur->l,val);
    }
    int find(int val){return find(root,val);}
    void pt(node* cur){
        if(!cur)return;
        pt(cur->l),printf("%d ",cur->data),pt(cur->r);
    }
    void pt(){pt(root);}
}tree;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        tree.insert(new node(a,rand()));
    }
    int last=0;
    char x;
    while(m--){
        cin>>x>>a;
        a^=last;
        if(x=='I')tree.insert(new node(a,rand()));
        else if(x=='R')tree.erase(a);
        else if(x=='S')printf("%d\n",last=tree.at(a));
        else printf("%d\n",last=tree.find(a));
    }
    tree.pt();
    return 0;
}