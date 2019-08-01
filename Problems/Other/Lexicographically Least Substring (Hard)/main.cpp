#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mo=1000000007;
lli prefixhash[1000001];
lli co[26];
lli mut=31;
lli divmods[1000001];
lli fastpow(lli a, lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i){
			ans=(ans*a)%mo;
		}
		a=(a*a)%mo;
	}
	return ans;
}
lli maker(lli a){
	while(a<0)a+=mo;
	return a;
}
lli gethash(int l, int r){
	if(r<l)return -1;
	return (maker(prefixhash[r]-prefixhash[l-1])*divmods[l-1])%mo;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	string a;
	int k;
	cin>>a>>k;
	iota(co,co+26,1);
	lli p=1;
	divmods[0]=1;
	for(int i=1;i<=a.size();i++){
		prefixhash[i]=(prefixhash[i-1]+(co[a[i-1]-'a']*p))%mo;
		p=(p*mut)%mo;
		divmods[i]=fastpow(p,mo-2);
	}
	int mi=1;
	for(int i=2;i+k-1<=a.size();i++){
		int le=0;
		int ri=k;
		while(le!=ri){
			int mid=(le+ri)/2+1;
			if(gethash(mi,mi+mid-1)==gethash(i,i+mid-1)){
				le=mid;
			}
			else{
				ri=mid-1;
			}
		}
		if(a[i+le-1]<a[mi+le-1])mi=i;
	}
	cout<<a.substr(mi-1,k);
    return 0;
}