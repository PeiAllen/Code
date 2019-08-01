#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mo=998244353;
lli arr[101];
vector<lli> matrix[101];
lli ans=0;
lli K;
vector<vector<vector<lli>>> dfs(lli loc, lli parent){
	vector<vector<vector<lli>>> alltree(3);
	for(lli i=0;i<3;i++){
		alltree[i].resize(3);
		for(lli j=0;j<3;j++){
			alltree[i][j].resize(K);
		}
	}
	alltree[arr[loc]][!arr[loc]][1]=1;
	for(lli x:matrix[loc]){
		if(x!=parent){
			auto te=dfs(x,loc);
			for(lli i=0;i<3;i++){
				for (lli j = 0; j < 3; j++) {
					if (i > 0 || j > 0) {}
					for (lli num = i + j; num < K; num++) {
						for (lli k = 2 - i; k <= 2; k++) {
							for (lli k2 = 2 - j; k2 <= 2; k2++) {
								ans += (te[i][j][num] * (alltree[k][k2][K - num])) % mo;
								ans %= mo;
							}
						}
					}
				}
			}
			auto help=alltree;
			for(lli i=0;i<3;i++) {
				for (lli j = 0; j < 3; j++) {
					if(i>0||j>0) {
						for (lli num = i + j; num < K; num++) {
							for (lli k = 0; k <= 2; k++) {
								for (lli k2 = 0; k2 <= 2; k2++) {
									if (k > 0 || k2 > 0) {
										for (lli num2 = k + k2; num2 + num < K; num2++) {
											alltree[min((lli)2, i + k)][min((lli)2, j + k2)][num2 + num] += (te[i][j][num] * help[k][k2][num2]) % mo;
											alltree[min((lli)2, i + k)][min((lli)2, j + k2)][num2 + num] %= mo;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return alltree;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n>>K;
    char a;
    for (lli i = 1; i <= n; i++) {
		cin>>a;
		arr[i]=(a=='B');
    }
    lli x,y;
	for (lli i = 0; i < n-1; i++) {
		cin>>x>>y;
		matrix[x].push_back(y);
		matrix[y].push_back(x);
	}
	dfs(1,-1);
	printf("%lli\n",ans);
    return 0;
}