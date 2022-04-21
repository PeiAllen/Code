#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
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
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    ll c;
    cin>>n>>m;
    vector<pair<ll,pii>> edges;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    int offset=m-(n-1)+1;
    int mid=sz(edges)/2;
    ll best=LLONG_MAX;
    for(int tilt=-offset;tilt<=offset;tilt++){
        int useval=mid+tilt;
        if(useval>=0&&useval<m){
            for(int i=1;i<=n;i++)dsu[i]={i,1};
            uni(edges[useval].second.first,edges[useval].second.second);
            ll curans=0;
            for(int lptr=useval-1,rptr=useval+1;lptr>=0||rptr<m;){
                if(rptr>=m||(lptr>=0&&abs(edges[lptr].first-edges[useval].first)<=abs(edges[rptr].first-edges[useval].first))){
                    if(uni(edges[lptr].second.first,edges[lptr].second.second)){
                        curans+=abs(edges[lptr].first-edges[useval].first);
                    }
                    lptr--;
                }
                else{
                    if(uni(edges[rptr].second.first,edges[rptr].second.second)){
                        curans+=abs(edges[rptr].first-edges[useval].first);
                    }
                    rptr++;
                }
            }
            best=max(best,curans);
        }
    }
    printf("%lli\n",best);
    return 0;
}