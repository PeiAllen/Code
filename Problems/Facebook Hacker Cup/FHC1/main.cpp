#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	freopen("/Users/allen/CLionProjects/FHC1/in.txt","r",stdin);
	freopen("/Users/allen/CLionProjects/FHC1/out.txt","w",stdout);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		int h,s,k;
		cin>>h>>s>>k;
		bool wh[h][s];
		char in;
		for(int i=0;i<h;i++){
			for(int j=0;j<s;j++){
				cin>>in;
				wh[i][j]=(in=='B');
			}
		}

	}
    return 0;
}