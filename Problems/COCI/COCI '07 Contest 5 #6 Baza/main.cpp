#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=3e4+1;
int bit[MN],n,q,endup[MN];
int ans[MN];
void update(int loc, int val){
    loc++;
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    loc++;
    int am=0;
    for(;loc>0;loc-=loc&-loc)am+=bit[loc];
    return am;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    string a;
    vector<pair<string,int>> arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back({a,i});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        endup[arr[i].second]=i;
    }
    cin>>q;
    vector<pair<pair<int,string>,int>> queries;
    for(int i=0;i<q;i++){
        cin>>a;
        int ind=lower_bound(arr.begin(),arr.end(),pair<string,int>{a,-1})-arr.begin();
        if(ind==sz(arr)||arr[ind].first!=a){
            queries.push_back({{n-1,a},i});
        }
        else queries.push_back({{arr[ind].second,a},i});
    }
    sort(queries.begin(),queries.end());
    int ptr=-1;
    for(auto x:queries){
        ans[x.second]+=x.first.first+1;
        while(ptr<x.first.first){
            ptr++;
            update(endup[ptr],1);
        }
        int prev=0;
        for(int j=sz(x.first.second);j>0;j--) {
            int l = lower_bound(arr.begin(), arr.end(), pair<string, int>{x.first.second.substr(0,j), -1})-arr.begin();
            string te=x.first.second.substr(0,j);
            te.back()++;
            int r = lower_bound(arr.begin(), arr.end(), pair<string, int>{te, -1})-arr.begin()-1;
            int cur=query(r)-query(l-1);
            ans[x.second]+=(cur-prev)*j;
            prev=cur;
        }
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}