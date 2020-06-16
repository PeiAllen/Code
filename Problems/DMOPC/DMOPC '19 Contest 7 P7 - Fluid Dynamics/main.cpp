#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int n,q;
int BS;
ll w;
long double calc(pll dp, ll loc){
    if(dp.first==-1)return LLONG_MAX;
    return ((long double)(w-loc*dp.second))/(long double)(-dp.first);
}
struct lichao{
    struct node{
        pll data;
        int left,right;
        node(){
            data={-1,-1};
            left=-1,right=-1;
        }
    };
    vector<node> t;
    lichao(){
        t={node()};
    }
    void del(){
        t=vector<node>();
        t.push_back(node());
    }
    int update(int ind, ll le, ll ri, pll val){
        if(val.first==-1)return ind;
        if(ind==-1){
            ind=sz(t);
            t.push_back(node());
        }
        ll mid=(le+ri)/2;
        bool lef=calc(val,le)<=calc(t[ind].data,le);
        bool mi=calc(val,mid)<=calc(t[ind].data,mid);
        if(mi)swap(val,t[ind].data);
        if(le==ri)return ind;
        if(lef!=mi){int newl=update(t[ind].left,le,mid,val);t[ind].left=newl;}
        else {int newr=update(t[ind].right,mid+1,ri,val);t[ind].right=newr;}
        return ind;
    }
    ll query(int ind, ll le, ll ri, ll loc){
        if(ind==-1)return LLONG_MAX;
        if(loc<le||loc>ri)return LLONG_MAX;
        if(le==ri)return calc(t[ind].data,loc);
        ll mid=(le+ri)/2;
        return min({(ll)calc(t[ind].data,loc),query(t[ind].left,le,mid,loc),query(t[ind].right,mid+1,ri,loc)});
    }
};
struct block{
    vector<pll> arr;
    lichao tree;
    block(){
        arr={};
        tree=lichao();
    }
};
vector<block> arr;
void insert(pll val){
    if(sz(arr)==0){
        arr.push_back(block());
        arr[0].arr.push_back(val);
        arr[0].tree.update(0,1,1e9,val);
        return;
    }
    int loc=-1;
    for(int i=0;i<sz(arr);i++){
        loc=i;
        if(arr[i].tree.query(0,1,1e9,val.first)<val.second)break;
    }
    bool done=false;
    for(int i=0;i<sz(arr[loc].arr)&&!done;i++){
        if(calc(arr[loc].arr[i],val.first)<val.second){
            arr[loc].arr.insert(arr[loc].arr.begin()+i,val);
            done=true;
        }
    }
    if(!done)arr[loc].arr.push_back(val);
    arr[loc].tree.update(0,1,1e9,val);
    if(sz(arr[loc].arr)>=2*BS){
        arr[loc].tree.del();
        arr.insert(arr.begin()+loc+1,block());
        arr[loc+1].arr.insert(arr[loc+1].arr.begin(),arr[loc].arr.begin()+BS,arr[loc].arr.end());
        arr[loc].arr.resize(BS);
        for(auto x:arr[loc].arr)arr[loc].tree.update(0,1,1e9,x);
        for(auto x:arr[loc+1].arr)arr[loc+1].tree.update(0,1,1e9,x);
    }
}
pll kth(int ind){
    int loc=sz(arr)-1;
    while(sz(arr[loc].arr)<ind)ind-=sz(arr[loc].arr),loc--;
    return arr[loc].arr[sz(arr[loc].arr)-ind];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q>>w;
    BS=sqrt(n+q);
    pll a;
    while(n--){
        cin>>a.first>>a.second;
        insert(a);
    }
    string type;
    while(q--){
        cin>>type;
        if(type[0]=='I'){
            cin>>a.first>>a.second;
            insert(a);
        }
        else{
            cin>>a.first;
            pll te=kth(a.first);
            printf("%lli %lli\n",te.first,te.second);
        }
    }
    return 0;
}
//(x*y+(v+x)*c)-(v*c+(x+v)*y)>=d
//x*y+(v+x)*c-v*c-(x+v)*y>=d
//y*(x-(x+v))+(v+x)*c-v*c>=d
//y*(-v)>=d-(v+x)*c+v*c
//y<=(d-xc)/(-v)
