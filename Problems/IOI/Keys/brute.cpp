#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c) {
    int n=sz(r),m=sz(u);
    for(int i=0;i<n;i++)dsu[i]={i,1};
    for(int i=0;i<m;i++){
        uni(u[i],v[i]);
    }
    vector<int> reach(n);
    for(int i=0;i<n;i++){
        reach[i]=(r[i]==0?dsu[find(i)].second:1);
    }
    int mi=*min_element(reach.begin(),reach.end());
    for(int i=0;i<n;i++)reach[i]=reach[i]==mi;
    return reach;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int nn,mm;
    cin>>nn>>mm;
    vector<int> kkeys(nn),ledge(mm),redge(nn),cedge(nn);
    for(int i=0;i<nn;i++){
        cin>>kkeys[i];
    }
    for(int i=0;i<mm;i++){
        cin>>ledge[i]>>redge[i]>>cedge[i];
    }
    auto te=find_reachable(kkeys,ledge,redge,cedge);
    for(auto x:te)printf("%d ",x);
    return 0;
}