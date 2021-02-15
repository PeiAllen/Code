#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+2,MQ=2e5+1;
vector<pair<int,pii>> updates;
vector<int> ind;
vector<int> ups[MQ];
int psa[MN];
pair<pii,int> ops[MQ];
pair<pii,vector<pair<int,pii>>> cdq[MQ*2];
int ri=-1,le=0;
int n,q;
int bit[MN];
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    int a,b,c;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        ops[i]={{b,c},a};
        if(a==1)updates.push_back({b,{sz(ind),1}}),updates.push_back({c+1,{sz(ind),-1}}),ind.push_back(i),psa[b]++,psa[c+1]--;
    }
    sort(updates.begin(),updates.end());
    vector<pair<int,pii>> queries;
    for(int i=1;i<=min(n,sz(ind));i++){
        psa[i]+=psa[i-1];
        for(int j=i;j<=psa[i];j+=i)queries.push_back({i,{q+1,j}});
    }
    vector<pair<int,pii>> te(sz(updates)+sz(queries));
    merge(updates.begin(),updates.end(),queries.begin(),queries.end(),te.begin());
    cdq[++ri]={{0,sz(ind)-1},te};
    while(le<=ri){
        int mid=(cdq[le].first.first+cdq[le].first.second)/2;
        if(cdq[le].first.first==cdq[le].first.second){
            int val=0;
            for(auto x:cdq[le].second){
                if(x.second.first<=q)val+=x.second.second;
                else if(val>=x.second.second)ups[ind[cdq[le].first.first]].push_back(x.first);
            }
        }
        else{
            vector<pair<int,pii>> left,right;
            bool lego=false,rigo=false;
            int val=0;
            for(auto x:cdq[le].second){
                if(x.second.first<=q){
                    if(x.second.first<=mid)val+=x.second.second,left.push_back(x);
                    else right.push_back(x);
                }
                else{
                    if(val>=x.second.second)left.push_back(x),lego=true;
                    else right.push_back({x.first,{x.second.first,x.second.second-val}}),rigo=true;
                }
            }
            if(lego)cdq[++ri]={{cdq[le].first.first,mid},left};
            if(rigo)cdq[++ri]={{mid+1,cdq[le].first.second},right};
        }
        cdq[le]=pair<pii,vector<pair<int,pii>>>();
        le++;
    }
    for(int i=0;i<q;i++){
        if(ops[i].second==1)for(auto x:ups[i])update(x,1);
        else printf("%d\n",query(ops[i].first.second)-query(ops[i].first.first-1));
    }
    return 0;
}