#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod=1e9+9;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	string a;
    	cin>>a;
		lli lh=0;
		lli rh=0;
		lli p=1;
		int ans=0;
		for(int l=0,r=(int)a.size()-1;l<r;l++,r--){
			lh=(lh+((a[l]-'`')*p%mod))%mod;
			rh=(rh*31%mod+(a[r]-'`'))%mod;
			if(lh==rh){
				ans+=2;
				lh=0;
				rh=0;
				p=1;
			}
			else p=(p*31)%mod;
		}
		if(lh||a.size()%2)ans+=1;
		printf("%d\n",ans);
    }
    return 0;
}