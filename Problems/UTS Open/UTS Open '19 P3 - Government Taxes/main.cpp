#include <bits/stdc++.h>
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
lli salary[MAXN];
int n,q;
struct node{
    lli rev,sal,lazypc,lazyextra,lazysaladd;
    int le,ri;
    struct node *left;
    struct node *right;
    node(){
        rev=0;
        sal=0;
        lazypc=0;
        lazyextra=0;
        lazysaladd=0;
        le=0;
        ri=0;
        left=NULL;
        right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left= new node(),right=new node();
            left->mt(l,mid()),right->mt(mid()+1,r);
        }
        else{
            sal=salary[l];
        }
    }
    void rl(){
        rev+=lazyextra+lazypc*sal;
        sal+=lazysaladd;
        if(le!=ri){
            left->lazypc+=lazypc;
            left->lazyextra+=lazyextra+left->lazysaladd*lazypc;
            left->lazysaladd+=lazysaladd;
            right->lazypc+=lazypc;
            right->lazyextra+=lazyextra+right->lazysaladd*lazypc;
            right->lazysaladd+=lazysaladd;
        }
        lazypc=0;
        lazyextra=0;
        lazysaladd=0;
    }
    void update(int l, int r, lli pc, lli raise){
        rl();
        if(le>r||ri<l)return;
        if(le>=l&&ri<=r){
            lazypc+=pc;
            lazyextra+=pc*lazysaladd;
            lazysaladd+=raise;
            rl();
            return;
        }
        left->update(l,r,pc,raise),right->update(l,r,pc,raise);
    }
    void print(){
        rl();
        if(le==ri){
            pr(rev);
            if(le==n)prl("");
            else pr(" ");
            return;
        }
        left->print(),right->print();
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,q);
    rep(i,1,n+1)sc(salary[i]);
    node citizens;
    citizens.mt(1,n);
    int a,l,r;
    lli x;
    while(q--){
        sc(a,l,r);
        if(a==1){
            sc(x);
            citizens.update(l,r,0,x);
        }
        else citizens.update(l,r,1,0);
    }
    citizens.print();
    return 0;
}