#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=750001;
int n,q;
pair<ll,int> arr[MAXN];
ll ans[MAXN];
pii query[MAXN];
int sparse[20][MAXN];
vector<pair<int,pair<int,ll>>> todo[MAXN];
map<ll,int> am;
struct line{
    ll enval,slope;
    int en;
    line(int x, ll b, ll m){
        en=x,enval=b,slope=m;
    }
    bool operator<(const int& rhs) const{
        return en<rhs;
    }
    ll calc(int x){
        return enval-slope*ll(en-x);
    }
};
struct func{
    deque<line> arr;
    ll offset;
    func(){
        arr={},offset=0;
    }
    func(const deque<line>& a, ll b){
        arr=a,offset=b;
    }
    ll calc(int x){
        return offset+lower_bound(arr.begin(),arr.end(),x)->calc(x);
    }
};
vector<func> solver;
int notused[MAXN];
int nl=0,nr=-1;
int mh(int a, int b){
    if(arr[a]>arr[b])return a;
    return b;
}
void makesparse(){
    iota(sparse[0],sparse[0]+n,0);
    for(int i=1;i<20;i++){
        for(int j=0;j<=n-(1<<i);j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getmax(int l, int r){
    int k=log2(r-l+1);
    return mh(sparse[k][l],sparse[k][r-(1<<k)+1]);
}
int dfs(int l, int r){
    if(r<l)return -1;
    if(l==r){
        if(nl<=nr){
            int cur=notused[nl++];
            solver[cur]=func({line(r, arr[r].first, arr[r].first)}, 0);
            for (auto x:todo[r])ans[x.second.first] = min(ans[x.second.first], solver[cur].calc(x.first) + x.second.second);
            return cur;
        }
        else {
            solver.push_back(func({line(r, arr[r].first, arr[r].first)}, 0));
            for (auto x:todo[r])ans[x.second.first] = min(ans[x.second.first], solver.back().calc(x.first) + x.second.second);
            return sz(solver) - 1;
        }
    }
    int maxind=getmax(l,r);
    int le=dfs(l,maxind-1),ri=dfs(maxind+1,r);
    if(ri==-1){
        solver[le].arr.push_back(line(r,(maxind-1>=l?solver[le].calc(maxind-1):0)+arr[maxind].first*ll(r-maxind+1)-solver[le].offset,arr[maxind].first));
        for(auto x:todo[maxind])ans[x.second.first]=min(ans[x.second.first],solver[le].calc(x.first)+x.second.second);
        return le;
    }
    solver[ri].offset+=arr[maxind].first*ll(maxind-l+1);
    line te=line(r,(maxind-1>=l?solver[le].calc(maxind-1):0)+arr[maxind].first*ll(r-maxind+1),arr[maxind].first);
    int left=maxind;
    while(sz(solver[ri].arr)&&te.calc(solver[ri].arr[0].en)<=solver[ri].arr[0].enval+solver[ri].offset)left=solver[ri].arr[0].en,solver[ri].arr.pop_front();
    if(!sz(solver[ri].arr))solver[ri].arr.push_front(line(te.en,te.enval-solver[ri].offset,te.slope));
    else{
        int right=solver[ri].arr[0].en-1;
        while(left!=right){
            int mid=(left+right+1)/2;
            if(te.calc(mid)<=solver[ri].arr[0].calc(mid)+solver[ri].offset)left=mid;
            else right=mid-1;
        }
        solver[ri].arr.push_front(line(left,te.calc(left)-solver[ri].offset,te.slope));
    }
    if(le==-1){
        for(auto x:todo[maxind])ans[x.second.first]=min(ans[x.second.first],solver[ri].calc(x.first)+x.second.second);
        return ri;
    }
    int cur;
    if(sz(solver[le].arr)>=sz(solver[ri].arr)){
        for(auto x:solver[ri].arr)solver[le].arr.push_back(line(x.en,x.enval+solver[ri].offset-solver[le].offset,x.slope));
        solver[ri]=func();
        notused[++nr]=ri;
        cur=le;
    }
    else{
        for(int i=sz(solver[le].arr)-1;i>=0;i--)solver[ri].arr.push_front(line(solver[le].arr[i].en,solver[le].arr[i].enval+solver[le].offset-solver[ri].offset,solver[le].arr[i].slope));
        solver[le]=func();
        notused[++nr]=le;
        cur=ri;
    }
    for(auto x:todo[maxind])ans[x.second.first]=min(ans[x.second.first],solver[cur].calc(x.first)+x.second.second);
    return cur;
}
void solve(){
    makesparse();
    solver.reserve(n);
    nl=0,nr=-1;
    for(int i=0;i<q;i++){
        int maxind=getmax(query[i].first,query[i].second);
        if(maxind==query[i].second)ans[i]=min(ans[i],arr[maxind].first*ll(query[i].second-query[i].first+1));
        else todo[getmax(maxind+1,query[i].second)].push_back({query[i].second,{i,arr[maxind].first*ll(maxind-query[i].first+1)}});
    }
    dfs(0,n-1);
    solver=vector<func>();
    for(int i=0;i<n;i++)todo[i]=vector<pair<int,pair<int,ll>>>();
}
vector<long long> minimum_costs(vector<int> H, vector<int> L, vector<int> R){
    n=sz(H),q=sz(L);
    fill(ans,ans+q,LLONG_MAX);
    for(int i=0;i<n;i++)arr[i]={H[i],am[H[i]]++};
    for(int i=0;i<q;i++)query[i]={L[i],R[i]};
    solve();
    reverse(arr,arr+n);
    for(int i=0;i<q;i++)query[i]={n-1-R[i],n-1-L[i]};
    solve();
    return vector<ll>(ans,ans+q);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(auto x:minimum_costs({2,4,3,5},{0,1},{2,3}))printf("%lli\n",x);
    return 0;
}