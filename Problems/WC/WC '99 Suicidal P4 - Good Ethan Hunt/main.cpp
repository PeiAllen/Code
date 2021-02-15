#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    while(m--){
        int n;
        cin>>n;
        int ten=n;
        while(__builtin_popcount(ten+1)>1)ten++;
        vector<int> ans={0};
        while(sz(ans)!=ten+1){
            vector<int> te;
            for(auto x:ans)te.push_back(x),te.push_back(x+sz(ans));
            ans=te;
        }
        for(int i=0;i<=ten;i++)if(ans[i]<=n)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}