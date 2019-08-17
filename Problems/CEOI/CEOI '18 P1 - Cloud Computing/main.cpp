#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
struct comp{
	lli rate,price;
	int cores;
	comp(int a=0, lli b=0, lli c=0):cores(a),rate(b),price(c){}
	bool operator<(const comp& rhs)const {
		if(rate==rhs.rate){
			return cores>rhs.cores;
		}
		return rate>rhs.rate;
	}
};
lli dp[2][100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<comp> orders;
    lli b,c;
    int a;
    for(int i=0;i<n;i++){
    	cin>>a>>b>>c;
		orders.push_back({a,b,-c});
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
    	cin>>a>>b>>c;
    	orders.push_back({-a,b,c});
    }
    sort(orders.begin(),orders.end());
    lli MINCOST=-(6e12+10);
	for(int j=1;j<=100000;j++){
		dp[0][j]=MINCOST;
	}
	int flip=1;
	int oth=0;
    for(int i=1;i<=orders.size();i++){
    	for(int j=0;j<=100000;j++){
			dp[flip][j]=dp[oth][j];
			int need=max(0,j-orders[i-1].cores);
			if(need>=0&&need<=100000)dp[flip][j]=max(dp[flip][j],dp[oth][need]+orders[i-1].price);
		}
    	oth=flip;
    	flip=(flip+1)%2;
    }
    lli ans=0;
    for(int i=0;i<=100000;i++){
    	ans=max(ans,dp[oth][i]);
    }
    printf("%lli\n",ans);
    return 0;
}