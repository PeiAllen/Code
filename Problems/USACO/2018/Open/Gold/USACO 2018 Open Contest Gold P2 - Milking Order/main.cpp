#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<int> out[MN];
int deg[MN];
vector<int> obv[MN];
vector<int> ord;
int n,m;
bool work(int am){
    for(int i=1;i<=n;i++)out[i]=vector<int>(),deg[i]=0;
    ord=vector<int>();
    priority_queue<int,vector<int>,greater<>> q;
    for(int i=0;i<am;i++){
        for(int j=0;j<sz(obv[i])-1;j++){
            deg[obv[i][j+1]]++;
            out[obv[i][j]].push_back(obv[i][j+1]);
        }
    }
    for(int i=1;i<=n;i++)if(deg[i]==0)q.push(i);
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        ord.push_back(cur);
        for(auto x:out[cur]){
            deg[x]--;
            if(deg[x]==0)q.push(x);
        }
    }
    return sz(ord)==n;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int a;
    for(int i=0;i<m;i++){
        cin>>a;
        obv[i].resize(a);
        for(int j=0;j<a;j++)cin>>obv[i][j];
    }
    int lo=0,hi=m;
    while(lo!=hi){
        int mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    work(lo);
    for(auto x:ord)printf("%d ",x);
    printf("\n");
    return 0;
}