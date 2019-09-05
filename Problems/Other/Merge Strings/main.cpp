#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
bool dp[52][52][52][52];
bool done[52][52][52][52];
int ans=0;
string a,b;
bool recu(int ia, int ja, int ib, int jb){
	if(done[ia][ja][ib][jb])return dp[ia][ja][ib][jb];
	dp[ia][ja][ib][jb]=false;
	if(ia>ja&&ib>jb)return dp[ia][ja][ib][jb]=true;
	else{
		if(ia<=ja&&a[ia]==a[ja])dp[ia][ja][ib][jb]|=recu(ia+1,ja-1,ib,jb);
		if(ib<=jb&&b[ib]==b[jb])dp[ia][ja][ib][jb]|=recu(ia,ja,ib+1,jb-1);
		if(ia<=ja&&ib<=jb) {
			if (a[ja] == b[ib])dp[ia][ja][ib][jb] |= recu(ia,ja - 1,ib + 1,jb);
			if (a[ia] == b[jb])dp[ia][ja][ib][jb] |= recu(ia + 1,ja,ib,jb - 1);
		}
	}
	if(dp[ia][ja][ib][jb])ans=max(ans,ja-ia+1+jb-ib+1);
	done[ia][ja][ib][jb]=true;
	return dp[ia][ja][ib][jb];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	cin>>a>>b;
    	a="0"+a;
    	b="0"+b;
	    memset(done,false,sizeof(done));
		ans=0;
		for(int ia=1;ia<a.size();ia++){
			for(int ja=ia;ja<a.size();ja++){
				for(int ib=1;ib<b.size();ib++){
					for(int jb=ib;jb<b.size();jb++){
						if(!done[ia][ja][ib][jb])recu(ia,ja,ib,jb);
					}
				}
			}
		}
		printf("%d\n",ans);
    }
    return 0;
}
//dp[l][r][l2][r2]= can make boolean substring with a(l,r) and b(l2,r2)
//dp[l][r][l2][r2]=dp[l-1][r]