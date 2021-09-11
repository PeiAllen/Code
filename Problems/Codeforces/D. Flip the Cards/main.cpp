#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
pii deck[MN];
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=INT_MAX,lazy=0;
        }
        void apply(int v){
            if(v)data=INT_MAX;
            lazy|=v;
        }
    };
    node t[5*MN];
    int offset=0;
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy);
        t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int loc, int val){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind].data=min(t[ind].data,(val==INT_MAX?INT_MAX:val-offset));
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc,val),update(right,mid+1,ri,loc,val);
        t[ind].data=min(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return INT_MAX;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
    void clear(){
        offset=0;
        t[0].apply(1);
    }
}tree[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    pii range={0,2*n};
    vector<pair<pii,int>> vals;
    for(int i=0;i<n;i++){
        cin>>deck[i].first>>deck[i].second;
        range.first=max(range.first,min(deck[i].first,deck[i].second));
        range.second=min(range.second,max(deck[i].first,deck[i].second)-1);
        vals.push_back({{min(deck[i].first,deck[i].second),max(deck[i].first,deck[i].second)},deck[i].first<deck[i].second});
    }
    if(range.first>range.second){
        printf("-1\n");
        return 0;
    }
    sort(vals.begin(),vals.end());
    int a=INT_MAX,b=INT_MAX;
    for(int i=0;i<n;i++){
        if(vals[i].first.second<a){
            a=vals[i].first.second;
        }
        else if(vals[i].first.second<b){
            b=vals[i].first.second;
        }
        else{
            printf("-1\n");
            return 0;
        }
    }
    int lastval=INT_MAX;
    tree[0].update(0,1,2*n+1,2*n+1,0);
    tree[1].update(0,1,2*n+1,2*n+1,0);
    for(int i=0;i<n;i++){
        int val1=tree[!vals[i].second].query(0,1,2*n+1,vals[i].first.second+1,2*n+1),val2=tree[vals[i].second].query(0,1,2*n+1,vals[i].first.second+1,2*n+1);
        if(val1!=INT_MAX)val1+=tree[!vals[i].second].offset;
        if(val2!=INT_MAX)val2+=tree[vals[i].second].offset;
        tree[!vals[i].second].offset++;
        if(lastval<vals[i].first.second)tree[vals[i].second].clear(),tree[!vals[i].second].clear();
        if(val1!=INT_MAX)tree[vals[i].second].update(0,1,2*n+1,lastval,val1);
        if(val2!=INT_MAX)tree[!vals[i].second].update(0,1,2*n+1,lastval,val2+1);
        lastval=vals[i].first.second;
    }
    printf("%d\n",min(tree[0].t[0].data,tree[1].t[0].data));
    return 0;
}