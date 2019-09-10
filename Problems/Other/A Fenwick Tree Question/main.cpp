#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=1e5+1;
const int MAXB=30;
int bit[MAXB][MAXN];
int arr[MAXN];
int n,q;
void update(int b, int loc, int am){
	for(;loc<=n;loc+=loc&-loc)bit[b][loc]+=am;
}
int query(int b, int loc){
	int sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[b][loc];
	return sum;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		for(int j=1;j<=MAXB;j++){
			if((1<<(j-1))&arr[i])update(j,i,1);
		}
	}
	int a,b,c;
	while(q--){
		cin>>a>>b>>c;
		if(a==1){
			for(int j=1;j<=MAXB;j++){
				if((1<<(j-1))&arr[b])update(j,b,-1);
			}
			arr[b]=c;
			for(int j=1;j<=MAXB;j++){
				if((1<<(j-1))&arr[b])update(j,b,1);
			}
		}
		else if(a==2){
			lli ans=0;
			lli mut=1;
			lli size=c-b+1;
			for(int i=1;i<=MAXB;i++){
				lli zerocnt=size-(query(i,c)-query(i,b-1));
				ans+=((size)*(size-1)-(zerocnt)*(zerocnt-1))/2*mut;
				mut*=2;
			}
			printf("%lli\n",ans);
		}
		else if(a==3){
			lli ans=0;
			lli mut=1;
			for(int i=1;i<=MAXB;i++){
				lli onecnt=query(i,c)-query(i,b-1);
				ans+=(onecnt)*(onecnt-1)/2*mut;
				mut*=2;
			}
			printf("%lli\n",ans);
		}
		else{
			lli ans=0;
			lli mut=1;
			lli size=c-b+1;
			for(int i=1;i<=MAXB;i++){
				lli onecnt=query(i,c)-query(i,b-1);
				ans+=(onecnt)*(size-onecnt)*mut;
				mut*=2;
			}
			printf("%lli\n",ans);
		}
	}
	return 0;
}