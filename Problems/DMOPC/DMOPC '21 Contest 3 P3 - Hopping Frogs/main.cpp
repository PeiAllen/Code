#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int sizes[MN];
struct seg{
    int t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]=sizes[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=min(t[left],t[right]);
    }
    void update(int ind, int le, int ri, int loc){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind]=sizes[le];
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind]=min(t[left],t[right]);
    }
    int query(int ind, int le, int ri, int val){
        if(t[ind]>val)return INT_MAX;
        if(le==ri)return le;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(t[left]<=val)return query(left,le,mid,val);
        return query(right,mid+1,ri,val);
    }
}tree;
pii dsu[MN];
int arr[MN];
int ind[MN];
int leftover[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp),swap(leftover[ap],leftover[bp]);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)sizes[i]=1;
    tree.mt(0,1,n);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dsu[i]={i,1};
        ind[arr[i]]=i;
        leftover[i]=arr[i];
    }
    tree.update(0,1,n,1);
    for(int i=1;i<=n;i++){
        int p=find(i);
        int best=leftover[p];
        int oth=tree.query(0,1,n,k-dsu[p].second);
        if(oth<best){
            printf("%d%c",oth," \n"[i==n]);
            int loc=ind[oth];
            sizes[oth]=INT_MAX;
            uni(p,find(loc));
            p=find(p);
            sizes[leftover[p]]=dsu[p].second;
            tree.update(0,1,n,oth);
            tree.update(0,1,n,leftover[p]);
        }
        else{
            printf("%d%c",best," \n"[i==n]);
            leftover[p]=-1;
            sizes[best]=INT_MAX;
            tree.update(0,1,n,best);
        }
    }
    return 0;
}