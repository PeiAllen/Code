#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=150001;
struct seg2{
    set<pll> t[2*MN];
    void update(int ind, int le, int ri, int loc, pll val){
        if(loc>ri||loc<le)return;
        auto it=t[ind].lower_bound({val.first,LLONG_MIN});
        if(it==t[ind].end()||it->second<val.second){
            if(it!=t[ind].end()&&it->first==val.first){
                it++;
            }
            while(it!=t[ind].begin()&&prev(it,1)->second<=val.second){
                t[ind].erase(prev(it,1));
            }
            t[ind].insert(val);
        }
        if(le==ri)return;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
    }
    ll query(int ind, int le, int ri, int l, int r, ll z){
        if(l>ri||r<le||l>r)return LLONG_MIN;
        if(le>=l&&ri<=r){
            auto it=t[ind].lower_bound(pll{z,LLONG_MIN});
            return (it==t[ind].end()?LLONG_MIN:it->second);
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r,z),query(right,mid+1,ri,l,r,z));
    }
}tree2;
vector<ll> yvalues;
struct seg{
    struct node{
        ll largestz;
        set<pll> other;
        node(){
            largestz=-1,other=set<pll>();
        }
    }t[2*MN];
    void update(int ind, int le, int ri, int l, int r, ll z){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].largestz=max(t[ind].largestz,z);
            auto it=t[ind].other.lower_bound({z,0});
            if(it!=t[ind].other.begin())tree2.update(0,0,sz(yvalues)-1,lower_bound(yvalues.begin(),yvalues.end(),prev(it,1)->second)-yvalues.begin(),{z,z+prev(it,1)->second});
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,z),update(right,mid+1,ri,l,r,z);
    }
    void update(int ind, int le, int ri, int loc, pll yz){
        if(loc>ri||loc<le)return;
        if(t[ind].largestz>yz.second)tree2.update(0,0,sz(yvalues)-1,lower_bound(yvalues.begin(),yvalues.end(),yz.first)-yvalues.begin(),{t[ind].largestz,yz.first+t[ind].largestz});
        auto it=t[ind].other.lower_bound({yz.second,LLONG_MAX});
        if(it==t[ind].other.begin()||prev(it,1)->second<yz.first){
            if(it!=t[ind].other.begin()&&prev(it,1)->first==yz.second){
                t[ind].other.erase(prev(it,1));
            }
            while(it!=t[ind].other.end()&&it->second<=yz.first){
                it++;
                t[ind].other.erase(prev(it,1));
            }
            t[ind].other.insert({yz.second,yz.first});
        }
        if(le==ri)return;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,yz),update(right,mid+1,ri,loc,yz);
    }
}tree;
pair<ll,pll> arr[MN];
map<ll,vector<pair<int,pll>>> ord;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].second.first>>arr[i].first>>arr[i].second.second;
    }
    sort(arr+1,arr+n+1);
    vector<pair<ll,int>> gates;
    for(int i=1;i<=n;i++){
        if(i==1||arr[i].first!=arr[i-1].first){
            gates.push_back({arr[i].first,i});
            yvalues.push_back(arr[i].first);
        }
        ord[arr[i].second.first].push_back({i,{arr[i].first,arr[i].second.second}});
    }
    gates.push_back({LLONG_MAX,n+1});
    ll ans=LLONG_MIN;
    for(auto x:ord){
        for(auto y:x.second){
            ll res=tree2.query(0,0,sz(yvalues)-1,lower_bound(yvalues.begin(),yvalues.end(),y.second.first)-yvalues.begin()+1,sz(yvalues)-1,y.second.second+1);
            if(res!=LLONG_MIN)ans=max(ans,res+x.first);
        }
        for(auto y:x.second){
            tree.update(0,1,n,lower_bound(gates.begin(),gates.end(),pair<ll,int>{y.second.first,INT_MAX})->second,n,y.second.second);
            tree.update(0,1,n,y.first,y.second);
        }
    }
    if(ans==LLONG_MIN)printf("-1\n");
    else printf("%lli\n",ans);
    return 0;
}