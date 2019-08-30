#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli x,y,z;
    int n;
    cin>>x>>y>>z>>n;
    lli buy[n];
    for(int i=0;i<n;i++)cin>>buy[i];
    sort(buy,buy+n);
    lli ans=0;
    for(int i=0;i<n;i++){
    	if(z>0)ans=max(ans,z+x/(lli)(n+1-i)*y);
    	z-=buy[i];
    }
    if(z>0)ans=max(ans,z+x*y);
    printf("%lli\n",ans);
    return 0;
}