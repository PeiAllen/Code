#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXL=1e6+1;
struct seg{
    struct node{
        int data,left,right;
        node(){
            data=0,left=-1,right=-1;
        }
    };
    vector<node> t;
    seg(){
        t={node()};
    }
    void clear(){
        t=vector<node>();
        t={node()};
    }
    int update(int ind, int le, int ri, int loc, int val){
        if(ind==-1){
            ind=sz(t);
            t.push_back(node());
        }
        t[ind].data+=val;
        if(le==ri)return ind;
        int mid=(le+ri)/2;
        if(loc<=mid){int te=update(t[ind].left,le,mid,loc,val);t[ind].left=te;}
        else{int te=update(t[ind].right,mid+1,ri,loc,val);t[ind].right=te;}
        return ind;
    }
    int query(int ind, int le, int ri, int l, int r){
        if(ind==-1||l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        int mid=(le+ri)/2;
        return query(t[ind].left,le,mid,l,r)+query(t[ind].right,mid+1,ri,l,r);
    }
}tree;
map<ll,pair<vector<pii>,vector<pii>>> ops;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        tree.clear(),ops=map<ll,pair<vector<pii>,vector<pii>>>();
        string s;
        cin>>s;
        int n;
        ll x,y;
        cin>>x>>y>>n;
        char a;
        ll am;
        for(int i=0;i<n;i++){
            cin>>a>>am;
            if(a=='U'){
                if(am>1)ops[x].second.push_back({y+1,y+am-1});
                y+=am;
            }
            else if(a=='D'){
                if(am>1)ops[x].second.push_back({y-am+1,y-1});
                y-=am;
            }
            else if(a=='R'){
                ops[x].first.push_back({y,1});
                ops[x+am+1].first.push_back({y,-1});
                x+=am;
            }
            else{
                ops[x+1].first.push_back({y,-1});
                ops[x-am].first.push_back({y,1});
                x-=am;
            }
        }
        cin>>x>>y>>n;
        for(int i=0;i<n;i++){
            cin>>a>>am;
            if(a=='U'){
                if(am>1)ops[x].second.push_back({y+1,y+am-1});
                y+=am;
            }
            else if(a=='D'){
                if(am>1)ops[x].second.push_back({y-am+1,y-1});
                y-=am;
            }
            else if(a=='R'){
                ops[x].first.push_back({y,1});
                ops[x+am+1].first.push_back({y,-1});
                x+=am;
            }
            else{
                ops[x+1].first.push_back({y,-1});
                ops[x-am].first.push_back({y,1});
                x-=am;
            }
        }
        ll ans=0;
        for(auto cur:ops){
            for(auto toup:cur.second.first)tree.update(0,0,MAXL,toup.first,toup.second);
            for(auto toq:cur.second.second)ans+=tree.query(0,0,MAXL,toq.first,toq.second);
        }
        printf("%lli\n",ans);
    }
    return 0;
}