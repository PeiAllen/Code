#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
lli arr[MAXN];
struct node{
    lli data,lazya,lazys;
    int le,ri;
    struct node *left,*right;
    node(){
        data=0,lazya=0,lazys=0,le=0,ri=0;
        left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left=new node(),right=new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
            data=min(left->data,right->data);
        }
        else data=arr[le];
    }
    void resolvelazy(){
        if(lazys)data=lazys;
        data+=lazya;
        if(le!=ri){
            if(lazys)left->lazys=lazys,left->lazya=lazya,right->lazys=lazys,right->lazya=lazya;
            else left->lazya+=lazya,right->lazya+=lazya;
        }
        lazys=0,lazya=0;
    }
    void update(int l, int r, lli a, lli s){
        resolvelazy();
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            if(s)lazya=0;
            lazys=s;
            lazya+=a;
            resolvelazy();
            return;
        }
        left->update(l,r,a,s),right->update(l,r,a,s);
        data=min(left->data,right->data);
    }
    lli query(int l, int r){
        resolvelazy();
        if(l>ri||r<le)return LLONG_MAX;
        if(le>=l&&ri<=r)return data;
        return min(left->query(l,r),right->query(l,r));
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    sc(n,q);
    rep(i,1,n+1)sc(arr[i]);
    node tree;
    tree.mt(1,n);
    int a,l,r,v;
    while(q--){
        sc(a,l,r);
        if(a==1){
            sc(v);
            tree.update(l,r,v,0);
        }
        else if(a==2){
            sc(v);
            tree.update(l,r,0,v);
        }
        else prl(tree.query(l,r));
    }
    return 0;
}