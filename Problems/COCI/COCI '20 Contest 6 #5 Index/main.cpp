#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
struct seg{
   struct node{
       int data,left,right;
       node(){
           data=0;
           left=-1,right=-1;
       }
   };
   vector<node> t;
   seg(){
       t.push_back(node());
   }
   int nn(){
       t.push_back(node());
       return sz(t)-1;
   }
   int update(int ind, int le, int ri, int loc, int v){
       if(loc>ri||loc<le)return ind;
       int nind=nn();
       if(le==ri){
           t[nind].data=(ind==-1?0:t[ind].data)+v;
           return nind;
       }
       int mid=(le+ri)/2;
       {int te=update((ind==-1?-1:t[ind].left),le,mid,loc,v);t[nind].left=te;}
       {int te=update((ind==-1?-1:t[ind].right),mid+1,ri,loc,v);t[nind].right=te;}
       t[nind].data=(t[nind].left==-1?0:t[t[nind].left].data)+(t[nind].right==-1?0:t[t[nind].right].data);
       return nind;
   }
   int walk(int indl, int indr, int le, int ri, int haveextra){
       if(le==ri){
           return le;
       }
       int mid=(le+ri)/2;
       if(haveextra+((indr==-1||t[indr].right==-1)?0:t[t[indr].right].data)-((indl==-1||t[indl].right==-1)?0:t[t[indl].right].data)>=mid+1){
           return walk((indl==-1?-1:t[indl].right),(indr==-1?-1:t[indr].right),mid+1,ri,haveextra);
       }
       return walk((indl==-1?-1:t[indl].left),(indr==-1?-1:t[indr].left),le,mid,haveextra+((indr==-1||t[indr].right==-1)?0:t[t[indr].right].data)-((indl==-1||t[indl].right==-1)?0:t[t[indl].right].data));
   }
}tree;
int roots[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,l,r;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        roots[i]=tree.update(roots[i-1],1,MN-1,arr[i],1);
    }
    while(q--){
        cin>>l>>r;
        printf("%d\n",tree.walk(roots[l-1],roots[r],1,MN-1,0));
    }
    return 0;
}