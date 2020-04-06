#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> arr[MAXN];
int dp[MAXN];
pii deq[MAXN];
int l=0,r=-1;
int sparse[18][MAXN];
int query(int a, int b){
    int k=log2(b-a+1);
    return min(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        sort(arr[i].begin(),arr[i].end());
        sparse[0][i-1]=(sz(arr[i])?arr[i][0]:INT_MAX);
    }
    for(int i=1;i<=log2(n);i++){
        for(int j=0;j<=n-(1<<i);j++){
            sparse[i][j]=min(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        if(!sz(arr[i]))dp[i]=dp[i-1];
        while(r>=l&&deq[l].second<i)l++;
        if(r>=l){
            int le=deq[l].first;
            if(query(le-1,i-1-1)>=i){
                dp[i]=max(dp[i],(dp[le-1]==-1?-1:dp[le-1]+1));
            }
        }
        else dp[i]=max(dp[i],(dp[i-1]==-1?-1:dp[i-1]+1));
        if(sz(arr[i])){
            if((!(r>=l))||deq[r].second<arr[i].back()){
                deq[++r]={i,arr[i].back()};
            }
        }D
    }
    printf("%d\n",dp[n]);
    return 0;
}