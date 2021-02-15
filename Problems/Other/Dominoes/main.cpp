#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
pii dominoes[MAXN];
vector<int> locs;
int whereright[MAXN];
int dp[MAXN];
vector<int> toremove[MAXN];
struct seg{
    int t[2*MAXN];
    void update(int ind, int le, int ri, int loc, int val){
        if(le==ri){
            t[ind]=val;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(loc<=mid)update(left,le,mid,loc,val);
        else update(right,mid+1,ri,loc,val);
        t[ind]=min(t[left],t[right]);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||r<l)return INT_MAX;
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree1,tree2;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dominoes[i].first>>dominoes[i].second;
        locs.push_back(dominoes[i].first);
    }
    sort(locs.begin(),locs.end());
    sort(dominoes,dominoes+n);
    for(int i=n-1;i>=0;i--){
        int mostright=upper_bound(locs.begin(),locs.end(),dominoes[i].first+dominoes[i].second)-locs.begin()-1;
        whereright[i]=max(i,-tree1.query(0,0,n-1,i+1,mostright));
        tree1.update(0,0,n-1,i,-whereright[i]);
    }
    multiset<int> vals;
    vals.insert(0),toremove[whereright[0]+1].push_back(0);
    for(int i=0;i<n;i++){
        int mostleft=lower_bound(locs.begin(),locs.end(),dominoes[i].first-dominoes[i].second)-locs.begin();
        int whereleft=min(i,tree2.query(0,0,n-1,mostleft,i-1));
        tree2.update(0,0,n-1,i,whereleft);
        for(auto x:toremove[i])vals.erase(vals.find(x));
        dp[i]=min((whereleft-1<0?0:dp[whereleft-1])+1,*vals.begin()+1);
        vals.insert(dp[i]),toremove[whereright[i+1]+1].push_back(dp[i]);
    }
    printf("%d\n",dp[n-1]);
    return 0;
}