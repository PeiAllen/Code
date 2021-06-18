#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1,limit=6,MV=(1<<18);
pll arr[MN];
pll old[MN];
map<ll,vector<pair<ll,int>>> locs;
vector<vector<int>> compressed;
int lp[MN],rp[MN];
int bit[MN],col[MN];
vector<ll> xcoords;
void update(int loc, int val){
    for(;loc<sz(xcoords);loc+=loc&-loc){
        bit[loc]+=val;
    }
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc){
        sum+=bit[loc];
    }
    return sum;
}
int get(int val){
    int i=0,cur=0;
    for(int jump=MV;jump>=1;jump>>=1){
        if(i+jump<sz(xcoords)&&cur+bit[i+jump]<val)i+=jump,cur+=bit[i];
    }
    return i+1;
}
ll getdist(int a, int b){
    return (old[a].first-old[b].first)*(old[a].first-old[b].first)+(old[a].second-old[b].second)*(old[a].second-old[b].second);
}
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    int rt=find(dsu[a].first);
    if(rt!=dsu[a].first)dsu[a].second=dsu[a].second^dsu[dsu[a].first].second,dsu[a].first=rt;
    return rt;
}
int rel(int a){
    find(a);
    if(a==dsu[a].first)return 0;
    return dsu[a].second;
}
bool uni(int a, int b){
    if(a==b)return false;
    int ap=find(a),bp=find(b);
    if(ap==bp){
        if(rel(a)==rel(b))return true;
        return false;
    }
    if(dsu[ap].second<dsu[bp].second){
        swap(a,b),swap(ap,bp);
    }
    dsu[ap].second+=dsu[bp].second;
    dsu[bp]={ap,(rel(a)==rel(b)?1:0)};
    return false;
}
int n;
vector<pair<ll,pii>> edges;
ll getdist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
ll closesttriangle(vector<pair<pll,int>> a){
    sort(a.begin(),a.end());
    set<pair<ll,int>> points;
    int l=0;
    ll ans=LLONG_MAX;
    for(int i=0;i<sz(a);i++){
        while(a[l].first.first<a[i].first.first-sqrtl(ans))points.erase({a[l].first.second,l}),l++;
        vector<pair<pll,ll>> temp;
        for(auto it=points.lower_bound({a[i].first.second-sqrtl(ans),-1});it!=points.upper_bound({a[i].first.second+sqrtl(ans),INT_MAX});it++){
            ll te=getdist(a[i].first,a[it->second].first);
            if(te<ans){
                edges.push_back({te,{a[i].second,a[it->second].second}});
                temp.push_back({a[it->second].first,te});
            }
        }
        for(int j=0;j<sz(temp);j++){
            for(int k=j+1;k<sz(temp);k++){
                ans=min(ans,max({temp[j].second,temp[k].second,getdist(temp[j].first,temp[k].first)}));
            }
        }
        points.insert({a[i].first.second,i});
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<pair<pll,int>> points;
    for(int i=1;i<=n;i++){
        dsu[i]={i,1};
        cin>>arr[i].first>>arr[i].second;

        locs[arr[i].first].push_back({arr[i].second,i});
    }
    sort(arr+1,arr+n+1,[&](const auto &lhs, const auto &rhs){
        return lhs.second<rhs.second;
    });
    compressed.push_back({});
    xcoords.push_back(INT_MIN);
    for(auto x:locs){
        compressed.push_back({});
        compressed.back().resize(sz(x.second));
        xcoords.push_back(x.first);
    }
    for(int i=1;i<=n;i++){
        points.push_back({arr[i],i});
        old[i]=arr[i];
        arr[i].first=lower_bound(xcoords.begin(),xcoords.end(),arr[i].first)-xcoords.begin();
    }
    ll dist=closesttriangle(points);
    sort(edges.begin(),edges.end());
    for(auto x:edges){
        if(x.first>=dist)break;
        if(uni(x.second.first,x.second.second)){
            printf("%lli\n",x.first);
            return 0;
        }
    }
    printf("%lli\n",dist);
    return 0;
}