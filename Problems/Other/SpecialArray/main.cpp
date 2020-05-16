#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli oddam=0,evenam=1;
    for(int i=1;i<=n;i++){// same as dp[i]=dp[i-1]+dp[i-2] since dp[i-2] is sum of all opposite partiy other than dp[i-1] which we then also add.
        lli cur=(i%2?evenam:oddam);
        if(i%2)oddam+=cur;
        else evenam+=cur;
        printf("%lli %lli\n",oddam+evenam-1,cur);
    }// just fib, sum of first n fib is fib(n+2)-fib(2) and use matrix fastpow
    return 0;
}