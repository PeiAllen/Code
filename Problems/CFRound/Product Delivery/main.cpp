#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1,ML=1e6;
int ans[MN];
vector<int> costs;
int mc;
multiset<int> marating[MN];
struct seg{
    int t[2*MN];
    void update(int ind, int le, int ri, int loc){
        if(loc<le||loc>ri)return;
        if(le==ri){
            t[ind]=*marating[le].rbegin();
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind]=max(t[left],t[right]);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
void DC(int le, int ri, vector<pair<pii,pair<pii,pii>>> events){
    vector<pair<pii,pair<pii,pii>>> left,right;
    int mid=(le+ri)/2;
    vector<int> costlocs;
    for(auto x:events){
        if(x.first.first!=3){
            if(x.first.first==1)costlocs.push_back(x.second.second.first),marating[x.second.second.first].insert(x.second.second.second);
            else marating[x.second.second.first].erase(marating[x.second.second.first].find(x.second.second.second));
            tree.update(0,0,mc,x.second.second.first);
            if(!(le>=x.second.first.first&&ri<=x.second.first.second)){
                if (x.second.first.first <= mid)left.push_back(x);
                if (x.second.first.second>mid)right.push_back(x);
            }
        }
        else{
            if(le>=x.second.first.first&&ri<=x.second.first.second){
                ans[x.first.second]=max(ans[x.first.second],tree.query(0,0,mc,0,x.second.second.first));
            }
            else {
                if (x.second.first.first <= mid)left.push_back(x);
                if (x.second.first.second>mid)right.push_back(x);
            }
        }
    }
    sort(costlocs.begin(),costlocs.end()),costlocs.erase(unique(costlocs.begin(),costlocs.end()),costlocs.end());
    for(auto x:costlocs)marating[x]=multiset<int>(),marating[x].insert(0),tree.update(0,0,mc,x);
    costlocs=vector<int>();
    for(auto x:events){
        if(x.first.first!=3){
            if(le>=x.second.first.first&&ri<=x.second.first.second){
                if(x.first.first==1)costlocs.push_back(x.second.second.first),marating[x.second.second.first].insert(x.second.second.second);
                else marating[x.second.second.first].erase(marating[x.second.second.first].find(x.second.second.second));
                tree.update(0,0,mc,x.second.second.first);
            }
        }
        else{
            if(!(le>=x.second.first.first&&ri<=x.second.first.second)){
                ans[x.first.second]=max(ans[x.first.second],tree.query(0,0,mc,0,x.second.second.first));
            }
        }
    }
    sort(costlocs.begin(),costlocs.end()),costlocs.erase(unique(costlocs.begin(),costlocs.end()),costlocs.end());
    for(auto x:costlocs)marating[x]=multiset<int>(),marating[x].insert(0),tree.update(0,0,mc,x);
    if(sz(left))DC(le,mid,left);
    if(sz(right))DC(mid+1,ri,right);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q,a,b,c,d,e;
    cin>>q;
    int querycnt=0;
    vector<pair<pii,pair<pii,pii>>> arr;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(a==1){
            cin>>c>>d>>e;
            costs.push_back(e);
            arr.push_back({{1,-1},{{max(1,b-c),min(ML,b+c)},{e,d}}});
        }
        else if(a==2){
            arr.push_back(arr[b-1]);
            arr.back().first.first=2;
        }
        else{
            cin>>c>>d;
            costs.push_back(d);
            arr.push_back({{3,querycnt++},{{b,c},{d,0}}});
        }
    }
    sort(costs.begin(),costs.end()),costs.erase(unique(costs.begin(),costs.end()),costs.end());
    mc=sz(costs)-1;
    for(int i=0;i<=mc;i++)marating[i].insert(0);
    for(auto &&x:arr)x.second.second.first=lower_bound(costs.begin(),costs.end(),x.second.second.first)-costs.begin();
    DC(1,ML,arr);
    for(int i=0;i<querycnt;i++)printf("%d\n",ans[i]);
    return 0;
}