#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
pair<pii,int> ups[MN];
pii dsu[2*MN];
int getval(int a){
    if(dsu[a].first==a)return 0;
    return dsu[a].second;
}
int find(int a){
    if(dsu[a].first==a)return a;
    int te=find(dsu[a].first);
    dsu[a].second^=getval(dsu[a].first);
    dsu[a].first=te;
    return te;
}
bool uni(int a, int b, int val){
    int ap=find(a),bp=find(b);
    if(ap==bp&&(getval(a)^getval(b))!=val)return false;
    if(ap==bp)return true;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].second=getval(a)^getval(b)^val;
    dsu[bp].first=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    string c;
    vector<int> nodes;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        ups[i]={{a,b},(c=="odd")};
        nodes.push_back(a-1),nodes.push_back(b);
    }
    sort(nodes.begin(),nodes.end()),nodes.erase(unique(nodes.begin(),nodes.end()),nodes.end());
    for(int i=0;i<sz(nodes);i++)dsu[i]={i,1};
    for(int i=0;i<m;i++){
        a=lower_bound(nodes.begin(),nodes.end(),ups[i].first.first-1)-nodes.begin(),b=lower_bound(nodes.begin(),nodes.end(),ups[i].first.second)-nodes.begin();
        if(!uni(a,b,ups[i].second)){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",m);
    return 0;
}