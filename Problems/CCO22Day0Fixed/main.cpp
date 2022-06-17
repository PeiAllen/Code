#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,g;
    char c;
    cin>>n>>g;
    map<int,int> cnt;
    for(int i=1;i<=g;i++){
        vector<vector<bool>> grid(n,vector<bool>(n));
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                cin>>c;
                grid[a][b]=(c=='R');
            }
        }
        for(int a=0;a<n-1;a++){
            for(int b=0;b<n-1;b++){
                if(grid[a][b]){
                    grid[a][b]=!grid[a][b];
                    grid[a+1][b]=!grid[a+1][b];
                    grid[a][b+1]=!grid[a][b+1];
                    grid[a+1][b+1]=!grid[a+1][b+1];
                }
            }
        }
        int val=0;
        for(int b=0;b<n;b++){
            val+=grid[n-1][b];
            val*=2;
        }
        for(int a=n-2;a>=0;a--){
            val+=grid[a][n-1];
            val*=2;
        }
        cnt[val]++;
    }
    int ans=0;
    for(auto x:cnt){
        ans+=x.second*(x.second-1)/2;
    }
    printf("%d\n",ans);
    return 0;
}