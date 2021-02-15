#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
map<pii,pair<int,vector<int>>> edges;
struct dsu{
    pii arr[MN];
    void reset(int n){
        for(int i=0;i<=n;i++)arr[i]={i,1};
    }
    int find(int a){
        if(arr[a].first==a)return a;
        return arr[a].first=find(arr[a].first);
    }
    bool uni(int a, int b){
        int ap=find(a),bp=find(b);
        if(ap==bp)return false;
        if(arr[ap].second<arr[bp].second)swap(ap,bp);
        arr[ap].second+=arr[bp].second,arr[bp].first=ap;
        return true;
    }
}one,two;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a;
        vector<int> te(a);
        for(int j=0;j<a;j++)cin>>te[j];
        for(int j=0;j<a;j++)cin>>b,edges[{min(te[j],te[(j+1)%a]),max(te[j],te[(j+1)%a])}].first=b,edges[{min(te[j],te[(j+1)%a]),max(te[j],te[(j+1)%a])}].second.push_back(i);
    }
    vector<pair<int,pii>> edge;
    for(auto x:edges){
        if(sz(x.second.second)==1)edge.push_back({x.second.first,{x.second.second[0],m}});
        else edge.push_back({x.second.first,{x.second.second[0],x.second.second[1]}});
    }
    sort(edge.begin(),edge.end());
    one.reset(m-1),two.reset(m);
    int onecost=0,twocost=0;
    for(auto x:edge){
        if(x.second.second!=m)if(one.uni(x.second.first,x.second.second))onecost+=x.first;
        if(two.uni(x.second.first,x.second.second))twocost+=x.first;
    }
    printf("%d\n",min(onecost,twocost));
    return 0;
}