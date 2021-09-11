#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int cnt[MN],arr[MN],nex[MN],pre[MN],last[MN];
vector<pii> ones;
bool solve(int l, int r){
    if(l>r){
        ones=vector<pii>();
        return true;
    }
    if(l==r){
        cnt[arr[l]]--;
        ones=vector<pii>();
        return true;
    }
    while(sz(ones)&&cnt[ones.back().first]==0)ones.pop_back();
    if(!sz(ones))return false;
    int mid=ones.back().second;
    cnt[ones.back().first]=0;
    ones.pop_back();
    if(r-mid>=mid-l){
        for(int i=l;i<mid;i++){
            cnt[arr[i]]--;
            if(cnt[arr[i]]==1)ones.push_back({arr[i],nex[i]});
        }
        if(!solve(mid+1,r))return false;
        for(int i=l;i<mid;i++)cnt[arr[i]]++;
        for(int i=l;i<mid;i++)if(cnt[arr[i]]==1)ones.push_back({arr[i],i});
        if(!solve(l,mid-1))return false;
    }
    else{
        for(int i=r;i>mid;i--){
            cnt[arr[i]]--;
            if(cnt[arr[i]]==1)ones.push_back({arr[i],pre[i]});
        }
        if(!solve(l,mid-1))return false;
        for(int i=r;i>mid;i--)cnt[arr[i]]++;
        for(int i=r;i>mid;i--)if(cnt[arr[i]]==1)ones.push_back({arr[i],i});
        if(!solve(mid+1,r))return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vals;
        for(int i=0;i<n;i++)cin>>arr[i],vals.push_back(arr[i]);
        sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end());
        for(int i=0;i<n;i++)arr[i]=lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin(),cnt[arr[i]]++;
        for(int i=0;i<n;i++)if(cnt[arr[i]]==1)ones.push_back({arr[i],i});
        for(int i=0;i<sz(vals);i++)last[i]=-1;
        for(int i=0;i<n;i++)pre[i]=last[arr[i]],last[arr[i]]=i;
        for(int i=0;i<sz(vals);i++)last[i]=-1;
        for(int i=n-1;i>=0;i--)nex[i]=last[arr[i]],last[arr[i]]=i;
        if(solve(0,n-1))printf("non-boring\n");
        else printf("boring\n");
        ones=vector<pii>();
        for(int i=0;i<sz(vals);i++)cnt[i]=0;
    }
    return 0;
}