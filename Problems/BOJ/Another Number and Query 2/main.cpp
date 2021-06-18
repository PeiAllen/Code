#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN],nex[MN],n,arr2[MN];
struct seg{
    vector<int> t[2*MN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind].push_back(arr2[le]);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind].resize(sz(t[left])+sz(t[right]));
        merge(t[left].begin(),t[left].end(),t[right].begin(),t[right].end(),t[ind].begin());
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return sz(t[ind])-(upper_bound(t[ind].begin(),t[ind].end(),r)-t[ind].begin());
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)+query(right,mid+1,ri,l,r);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<int> vals;
    for(int i=1;i<=n;i++)cin>>arr[i],vals.push_back(arr[i]);
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<sz(vals);i++)nex[i]=n+1;
    for(int i=n;i>=1;i--){
        int v=lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin();
        arr2[i]=nex[v];
        nex[v]=i;
    }
    tree.mt(0,1,n);
    int q,a,b,lastans=0;
    cin>>q;
    while(q--){
        cin>>a>>b,a+=lastans;
        printf("%d\n",lastans=tree.query(0,1,n,a,b));
    }
    return 0;
}