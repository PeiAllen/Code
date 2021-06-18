#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<pii> solve(vector<int> &nodes,const vector<int>& dist){
    sort(nodes.begin(),nodes.end(),[&](const auto &lhs, const auto &rhs){
        return dist[lhs]<dist[rhs];
    });
    vector<pii> res;
    map<int,int> opposite;
    for(auto x:nodes){
        if(sz(opposite)==0){
            res.push_back({dist[x],1});
            opposite[dist[x]]=x;
            continue;
        }
        int tedist=getDistance(x,opposite.rbegin()->second);
        if(opposite.count((dist[x]+opposite.rbegin()->first-tedist)/2)){
            res.push_back({opposite.rbegin()->first-tedist,0});
        }
        else{
            res.push_back({dist[x],1});
            opposite[dist[x]]=x;
        }
    }
    return res;
}
void findLocation(int n, int first, int location[], int stype[]){
    vector<int> dist(n,0);
    for(int i=1;i<n;i++)dist[i]=getDistance(0,i);
    int closest=min_element(dist.begin()+1,dist.end())-dist.begin();
    vector<int> dist2(n,0);
    dist2[0]=dist[closest];
    for(int i=1;i<n;i++){
        if(i==closest)dist2[i]=0;
        else dist2[i]=getDistance(closest,i);
    }
    location[0]=first,location[closest]=first+dist[closest];
    stype[0]=1,stype[closest]=2;
    vector<int> left,right;
    for(int i=1;i<n;i++){
        if(dist[i]-dist[closest]==dist2[i]){
            if(i!=closest)left.push_back(i);
        }
        else right.push_back(i);
    }
    vector<pii> te=solve(right,dist);
    for(int i=0;i<sz(right);i++){
        location[right[i]]=te[i].first+location[0];
        stype[right[i]]=1+te[i].second;
    }
    te=solve(left,dist2);
    for(int i=0;i<sz(left);i++){
        location[left[i]]=location[closest]-te[i].first;
        stype[left[i]]=2-te[i].second;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}