#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1,ML=__lg(MN)+1;
ll arr[MN];
pair<ll,int> sparse[ML][MN];
int n;
void ms(){
    for(int i=1;i<ML;i++){
        for(int j=0;j+(1<<i)<=n+1;j++){
            sparse[i][j]=min(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getmin(int l, int r){
    int k=__lg(r-l+1);
    return min(sparse[k][l],sparse[k][r-(1<<k)+1]).second;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k,l,r;
    cin>>n>>k>>l>>r;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-1],sparse[0][i]={arr[i],i};
    }
    ms();
    priority_queue<pair<ll,pair<int,pii>>> q;
    for(int i=l;i<=n;i++){
        pii range={max(0,i-r),i-l};
        q.push({arr[i]-arr[getmin(range.first,range.second)],{i,range}});
    }
    ll sum=0;
    for(int i=0;i<k;i++){
        auto cur=q.top();
        q.pop();
        sum+=cur.first;
        int loc=getmin(cur.second.second.first,cur.second.second.second);
        if(loc-1>=cur.second.second.first)q.push({arr[cur.second.first]-arr[getmin(cur.second.second.first,loc-1)],{cur.second.first,{cur.second.second.first,loc-1}}});
        if(loc+1<=cur.second.second.second)q.push({arr[cur.second.first]-arr[getmin(loc+1,cur.second.second.second)],{cur.second.first,{loc+1,cur.second.second.second}}});
    }
    printf("%lli\n",sum);
    return 0;
}