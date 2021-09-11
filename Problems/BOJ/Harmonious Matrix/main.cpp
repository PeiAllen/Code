#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
struct seg{
    set<pii> t[2*MN];
    void update(int ind, int le, int ri, int loc, pii val){
        if(loc>ri||loc<le)return;
        auto it=t[ind].lower_bound({val.first,0});
        while(it!=t[ind].end()&&it->second<=val.second){
            it++;
            t[ind].erase(prev(it,1));
        }
        if(it==t[ind].begin()||prev(it,1)->second<val.second)t[ind].insert(val);
        if(le==ri){
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
    }
    int query(int ind, int le, int ri, int l, int r, int val){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r){
            auto it=t[ind].lower_bound({val,0});
            if(it==t[ind].begin())return 0;
            return prev(it,1)->second;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r,val),query(right,mid+1,ri,l,r,val));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<pair<int,pii>> arr(m);
    vector<int> vals;
    for(int i=0;i<m;i++)cin>>arr[i].first;
    for(int i=0;i<m;i++)cin>>arr[i].second.first,vals.push_back(arr[i].second.first);
    for(int i=0;i<m;i++){
        if(n==3)cin>>arr[i].second.second;
    }
    sort(arr.begin(),arr.end());
    sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<m;i++){
        int ind=lower_bound(vals.begin(),vals.end(),arr[i].second.first)-vals.begin(),othind=(n==2?i:arr[i].second.second);
        tree.update(0,0,sz(vals)-1,ind,{othind,tree.query(0,0,sz(vals)-1,0,ind-1,othind)+1});
    }
    printf("%d\n",tree.t[0].rbegin()->second);
    return 0;
}