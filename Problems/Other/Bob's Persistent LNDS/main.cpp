#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
struct pseg{
    struct node{
        int data,left,right;
        node(){
            data=0,left=0,right=0;
        }
    };
    vector<node> t;
    pseg(){
        t={node()};
    }
    int update(int ind, int le, int ri, int loc, int val){
        int newind=sz(t);
        t.push_back(t[ind]);
        if(le==ri){
            t[newind].data=max(t[newind].data,val);
            return newind;
        }
        int mid=(le+ri)/2;
        if(loc<=mid){int nind=update(t[newind].left,le,mid,loc,val);t[newind].left=nind;}
        else {int nind=update(t[newind].right,mid+1,ri,loc,val);t[newind].right=nind;}
        t[newind].data=max(t[t[newind].left].data,t[t[newind].right].data);
        return newind;
    }
    int query(int ind, int le, int ri, int l, int r){
        if(ind==0||l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        int mid=(le+ri)/2;
        return max(query(t[ind].left,le,mid,l,r),query(t[ind].right,mid+1,ri,l,r));
    }
}tree;
int lastloc[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    int lastsize=0;
    lastloc[0]=0;
    int prev=0;
    while(n--){
        cin>>a>>b;
        if(a==0){
            lastsize++;
            prev=tree.update(prev,0,1e7,b,tree.query(prev,0,1e7,0,b)+1);
            lastloc[lastsize]=prev;
        }
        else{
            lastsize=b;
            prev=lastloc[lastsize];
        }
        printf("%d\n",tree.query(prev,0,1e7,0,1e7));
    }
    return 0;
}