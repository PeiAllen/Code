#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=6e5+1;
vector<int> location;
struct seg{
    struct node{
        priority_queue<pii,vector<pii>,greater<>> left;
        priority_queue<pii> right;
    }t[2*MN];
    void update(int ind, int le, int ri, int l, int r, int val, int id, int time) {
        if (l > ri || r < le||l>r)return;
        if (le >= l && ri <= r) {
            if(id==0){
                if(!sz(t[ind].left)||val<t[ind].left.top().first||time>t[ind].left.top().second)t[ind].left.push({val,time});
            }
            else{
                if(!sz(t[ind].right)||val>t[ind].right.top().first||time>t[ind].right.top().second)t[ind].right.push({val,time});
            }
            return;
        }
        int mid = (le + ri) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        update(left, le, mid, l, r, val,id,time), update(right,mid+1,ri, l, r, val,id,time);
    }
    int query(int ind, int le, int ri, int loc, int time){
        if(loc<le||loc>ri)return 0;
        while(sz(t[ind].left)&&t[ind].left.top().second<=time)t[ind].left.pop();
        while(sz(t[ind].right)&&t[ind].right.top().second<=time)t[ind].right.pop();
        int teans=max((sz(t[ind].left)?location[loc]-t[ind].left.top().first:0),(sz(t[ind].right)?t[ind].right.top().first-location[loc]:0));
        if(le==ri)return teans;
        int mid = (le + ri) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        return max({teans,query(left,le,mid,loc,time),query(right,mid+1,ri,loc,time)});
    }
}tree;
vector<pair<pii,pii>> ups;
vector<pair<pii,pair<pii,pii>>> ops;//time,id,l,r,val,release
multiset<int> locs[MN];
map<pair<pii,pii>,vector<int>> combined;
int ans[MN];
int amv;
void updaterange(int l, int r, bool op, int time){
    if(l==INT_MIN&&r==INT_MAX)return;
    if(l==INT_MIN){
        pair<pii,pii> te={{0,upper_bound(location.begin(),location.end(),r)-location.begin()-1},{r,1}};
        if(op==0)combined[te].push_back(time);
        else ops.push_back({{combined[te].back(),te.second.second},{te.first,{te.second.first,time}}}),combined[te].pop_back();
    }
    else if(r==INT_MAX){
        pair<pii,pii> te={{lower_bound(location.begin(),location.end(),l)-location.begin(),amv},{l,0}};
        if(op==0)combined[te].push_back(time);
        else ops.push_back({{combined[te].back(),te.second.second},{te.first,{te.second.first,time}}}),combined[te].pop_back();
    }
    else {
        int mid = (l + r) / 2;
        pair<pii,pii> te={{lower_bound(location.begin(), location.end(), l) - location.begin(),
                                  upper_bound(location.begin(), location.end(), mid) - location.begin() - 1},{l,0}};
        if(op==0)combined[te].push_back(time);
        else ops.push_back({{combined[te].back(),te.second.second},{te.first,{te.second.first,time}}}),combined[te].pop_back();
        te={{lower_bound(location.begin(), location.end(), mid + 1) - location.begin(),
                    upper_bound(location.begin(), location.end(), r) - location.begin() - 1},{r,1}};
        if(op==0)combined[te].push_back(time);
        else ops.push_back({{combined[te].back(),te.second.second},{te.first,{te.second.first,time}}}),combined[te].pop_back();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,q;
    cin>>n>>k>>q;
    int a,b,c,d;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        location.push_back(a);
        ups.push_back({{c,0},{a,b}}),ups.push_back({{d+1,1},{a,b}});
    }
    for(int i=0;i<q;i++){
        cin>>a>>b;
        location.push_back(a);
        ops.push_back({{b,2},{{a,i},{0,0}}}),ups.push_back({{b,2},{a,i}});;
    }
    sort(ups.begin(),ups.end());
    sort(location.begin(),location.end()),location.erase(unique(location.begin(),location.end()),location.end());
    amv=sz(location)-1;
    int amaccess=0;
    for(auto x:ups){
        if(x.first.second==0){
            auto right=locs[x.second.second].lower_bound(x.second.first);
            int rightval=(right==locs[x.second.second].end()?INT_MAX:*right);
            int leftval=(right==locs[x.second.second].begin()?INT_MIN:*prev(right,1));
            updaterange(leftval,rightval,1,x.first.first);
            updaterange(leftval,x.second.first,0,x.first.first),updaterange(x.second.first,rightval,0,x.first.first);
            locs[x.second.second].insert(x.second.first);
            if(sz(locs[x.second.second])==1)amaccess++;
        }
        else if(x.first.second==1){
            auto loc=locs[x.second.second].lower_bound(x.second.first);
            int rightval=(next(loc,1)==locs[x.second.second].end()?INT_MAX:*next(loc,1));
            int leftval=(loc==locs[x.second.second].begin()?INT_MIN:*prev(loc,1));
            updaterange(leftval,x.second.first,1,x.first.first),updaterange(x.second.first,rightval,1,x.first.first);
            updaterange(leftval,rightval,0,x.first.first);
            locs[x.second.second].erase(loc);
            if(sz(locs[x.second.second])==0)amaccess--;
        }
        else{
            if(amaccess!=k)ans[x.second.second]=-1;
        }
    }
    sort(ops.begin(),ops.end());
    for(auto x:ops){
        if(x.first.second==2){
           if(ans[x.second.first.second]!=-1)ans[x.second.first.second]=tree.query(0,0,amv,lower_bound(location.begin(),location.end(),x.second.first.first)-location.begin(),x.first.first);
        }
        else tree.update(0,0,amv,x.second.first.first,x.second.first.second,x.second.second.first,x.first.second,x.second.second.second);
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}