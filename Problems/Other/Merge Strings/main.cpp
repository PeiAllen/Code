#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	string a,b;
    	cin>>a>>b;

    }
    return 0;
}
//dp[l][r][l2][r2]= can make boolean substring with a(l,r) and b(l2,r2)
//dp[l][r][l2][r2]=dp[l-1][r]