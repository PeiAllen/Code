#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+2;
int bad[MN];
int am[MN];
int needed[MN];
vector<pii> queries;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,m,a,b,c;
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(c==1)queries.push_back({a,b});
        else bad[a]++,bad[b+1]--;
    }
    vector<int> locations;
    for(int i=1;i<=n;i++){
        bad[i]+=bad[i-1];
        if(bad[i])am[i]=0;
        else am[i]=1,locations.push_back(i);
        am[i]+=am[i-1];
    }
    sort(queries.begin(),queries.end());
    int rightmostcover=0;
    vector<pii> te;
    for(auto x:queries){
        if(rightmostcover>=x.second)continue;
        te.push_back(x);
    }
    queries=te;
    int ptr=0;
    int amneeded=0;
    rightmostcover=0;
    for(int i=0;i<sz(locations);i++){
        while(ptr<sz(queries)&&queries[ptr].second<locations[i]){
            if(queries[ptr].first>rightmostcover)amneeded++,rightmostcover=queries[ptr].second;
            ptr++;
        }
        needed[i]+=amneeded;
    }
    int ptr=0;
    int amneeded=0;
    rightmostcover=0;
    for(int i=sz(locations)-1;i>=0;i--){
        while(ptr<sz(queries)&&queries[ptr].second<locations[i]){
            if(queries[ptr].first>rightmostcover)amneeded++,rightmostcover=queries[ptr].second;
            ptr++;
        }
        needed[i]+=amneeded;
    }
    return 0;
}