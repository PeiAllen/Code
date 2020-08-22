#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int n,d;
int ans=0;
int dfs(int loc){
    vector<int> dists;
    for(auto x:matrix[loc])dists.push_back(dfs(x));
    sort(dists.begin(),dists.end(),greater<>());
    while(sz(dists)>=2&&dists.back()+dists[sz(dists)-2]<d)dists.pop_back(),ans--;
    if(sz(dists)==0||dists.back()>=d){
        ans++;
        return 1;
    }
    return dists.back()+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>d;
    int a;
    for(int i=1;i<n;i++){
        cin>>a;
        matrix[a].push_back(i);
    }
    dfs(0);
    printf("%d\n",ans);
    return 0;
}