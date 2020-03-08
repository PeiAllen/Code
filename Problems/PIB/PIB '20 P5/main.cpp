#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli arr[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++)cin>>arr[i][j],arr[i][j]+=arr[i][j-1];
    }
    vector<lli> ans;
    for(int i=0;i<n;i++){
        vector<lli> te;
        for(int j=0;j<n;j++){
            te.push_back(arr[j][i]);
        }
        sort(te.begin(),te.end());
        ans.push_back((n%2?te[n/2]:min(te[n/2],te[n/2-1])));
    }
    sort(ans.begin(),ans.end());
    printf("YES\n");
    for(int i=0;i<n;i++)printf("%lli ",-(n%2?ans[n/2]:min(ans[n/2],ans[n/2-1])));
    return 0;
}