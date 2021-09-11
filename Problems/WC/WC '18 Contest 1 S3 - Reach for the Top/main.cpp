#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e6+1,MV=1e9;
int bad[MN];
int dist[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int h,j,n;
    cin>>h>>j>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        bad[a]++;
        bad[b+1]--;
    }
    dist[0]=0;
    multiset<int> val;
    for(int i=1;i<=h+j+j;i++){
        dist[i]=MV;
        bad[i]+=bad[i-1];
    }
    if(!bad[j])val.insert(0);
    int ans=MV;
    for(int i=1;i<=h+j;i++){
        if(i-j>=0&&!bad[i])val.erase(val.find(dist[i-j]));
        if(!bad[i])dist[i]=min({dist[i],(i-j>=0?dist[i-j]+1:MV),(sz(val)?*val.begin()+2:MV)});
        if(!bad[i+j])val.insert(dist[i]);
        if(i>=h)ans=min(ans,dist[i]);
    }
    printf("%d\n",(ans==MV?-1:ans));
    return 0;
}