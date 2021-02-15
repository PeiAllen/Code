#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int pos[MN];
int bit[MN];
int inord[MN];
int n,k;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
bool solve(int dist){
    for(int i=1;i<=n;i++)bit[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(query(inord[i])==0)ans++;
        int left=lower_bound(pos+1,pos+n+1,pos[inord[i]]-dist)-pos;
        int right=upper_bound(pos+1,pos+n+1,pos[inord[i]]+dist)-pos-1;
        update(left,1),update(right+1,-1);
    }
    return ans<=k;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    vector<pii> sorted;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        sorted.push_back({a,b});
    }
    sort(sorted.begin(),sorted.end());
    vector<pii> bad;
    for(int i=0;i<n;i++){
        pos[i+1]=sorted[i].first;
        bad.push_back({sorted[i].second,i+1});
    }
    sort(bad.begin(),bad.end());
    for(int i=0;i<n;i++){
        inord[i+1]=bad[i].second;
    }
    int lo=0,hi=1e9;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(solve(mid))hi=mid;
        else lo=mid+1;
    }
    printf("%d\n",lo);
    return 0;
}