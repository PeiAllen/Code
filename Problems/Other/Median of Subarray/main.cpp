#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli bit[200002];
int n;
lli start(int loc){
	lli sum=0;
	for(;loc>0;loc-=(loc&-loc))sum+=bit[loc];
	return sum;
}
void update(int loc){
	for(;loc<=2*n+1;loc+=(loc&-loc))bit[loc]+=1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int l;
    cin>>n>>l;
    int arr[n+1];
    arr[0]=0;
    lli ans=0;
    update(n+1);
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	arr[i]=(arr[i]>=l?1:-1);
    	arr[i]+=arr[i-1];
    	ans+=start(arr[i]+n+1);
    	update(arr[i]+n+1);
    }
    printf("%lli\n",ans);
    return 0;
}