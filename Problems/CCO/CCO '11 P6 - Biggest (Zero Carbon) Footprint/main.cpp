#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
int deq[MN];
vector<int> trees[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,t;
    cin>>n>>m>>t;
    int a,b;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        trees[a].push_back(b);
    }
    for(int i=0;i<=n;i++)trees[i].push_back(m),sort(trees[i].begin(),trees[i].end(),greater<>());
    int ans=0;
    for(int i=0;i<m;i++){
        int l=0,r=-1;
        for(int j=0;j<=n;j++){
            while(trees[j].back()<=i)trees[j].pop_back();
            int height=trees[j].back()-i;
            int prevheight=m-i;
            while(l<=r&&trees[deq[r]].back()-i>=height)ans=max(ans,prevheight*(j-deq[r])),prevheight=trees[deq[r]].back()-i,r--;
            ans=max(ans,prevheight*(j-(l<=r?deq[r]:0)));
            deq[++r]=j;
        }
        int prevheight=m-i;
        while(l<=r)ans=max(ans,prevheight*(n-deq[r])),prevheight=trees[deq[r]].back()-i,r--;
        ans=max(ans,prevheight*n);
    }
    printf("%d\n",ans);
    return 0;
}