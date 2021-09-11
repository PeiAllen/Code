#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=51;
vector<int> adj[MN];
int arr[MN];
vector<int> poss;
int dfs(int loc, int parent){
    int ma=arr[loc];
    for(auto x:adj[loc]){
        if(x!=parent){
            if(loc==1)poss.push_back(dfs(x,loc));
            else ma=max(ma,arr[loc]+dfs(x,loc));
        }
    }
    return ma;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("gold_mine_chapter_1_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i],adj[i]=vector<int>();
        for(int i=1;i<n;i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        poss=vector<int>();
        dfs(1,0);
        sort(poss.begin(),poss.end(),greater<>());
        int sum=arr[1];
        for(int i=0;i<min(SZ(poss),2);i++)sum+=poss[i];
        printf("Case #%d: %d\n",cs,sum);
    }
    return 0;
}