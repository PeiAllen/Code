#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=101;
vector<int> dp[2];

int arr[MN],val[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int cur=1;
    for(int i=1;i<=n;i++)cin>>arr[i];
    string te;
    vector<vector<string>> tetransitions;
    vector<vector<int>> transitions;
    unordered_map<string,int> index;
    vector<string> ord;
    int ind=0;
    for(int i=1;i<=8;i++)te.push_back('0'+i);
    do{
        dp[0].push_back(0);
        ord.push_back(te);
        index[te]=ind;
        tetransitions.push_back({});
        for(int j=1;j<=8;j++){
            string ne(1,'0'+j);
            char og='0'+j;
            for(int k=0;k<7;k++){
                char tecur=te[k]-(te[k]>te.back());
                ne.push_back(tecur+(tecur>=og));
            }
            tetransitions.back().push_back(ne);
        }
        ind++;
    }while(next_permutation(te.begin(),te.end()));
    dp[1].resize(sz(dp[0]));
    for(auto x:tetransitions){
        transitions.push_back({});
        for(auto y:x){
            transitions.back().push_back(index[y]);
        }
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
        for(int x=0;x<sz(dp[cur]);x++){
            int add=0;
            for(int j=i-1;j>=max(1,i-7);j--){
                if(ord[x][7-(i-j)]>ord[x].back()){
                    if(j>=i-arr[i])add+=val[i];
                }
                else{
                    if(j+arr[j]>=i)add+=val[j];
                }
            }
            int best=0;
            for(auto y:transitions[x]){
                best=max(best,dp[!cur][y]);
            }
            dp[cur][x]=best+add;
        }
        cur=!cur;
    }
    int best=0;
    for(auto x:dp[!cur]){
        best=max(best,x);
    }
    printf("%d\n",best);
    return 0;
}