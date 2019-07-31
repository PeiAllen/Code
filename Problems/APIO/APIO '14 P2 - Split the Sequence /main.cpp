#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
char _buf[1048577], *_pbuf = _buf;

int readint() {
	int c, o = 0;
	while ((c = getchar()) < '0');
	do {o = (o<<3)+(o<<1) + (c - '0');} while ((c = getchar()) >= '0');
	return o;
}
lli arr[100001];
int n,k;
lli dp[2][100001];
int from[201][100001];
bool ded[2][100001];
int best[100001];
long double point[100001];
int le=100001;
int ri=100000;
int flip=0;
int op=1;
inline long double overcomepoint(int a, int b, int splits){//a>b
	return (((long double)(arr[n]*(arr[a-1]-arr[b-1])+dp[flip][b-1]-dp[flip][a-1]))/(long double)(arr[a-1]-arr[b-1]));
}
bool overcome(int a, int b, int c,int splits){//a>b>c
	long double te=overcomepoint(a,b,splits);
	long double te2=overcomepoint(b,c,splits);
	if(te<=te2)return true;
//	if(n*k<=1000000) {
	int loc = lower_bound(arr + 1, arr + n + 1, ceil(te)) - arr;
	if (arr[loc - 1] <= te2)return true;
//	}
	return false;
}
void calcbest(int splits, int loc){
	long double te;
	if(n*k<10000000){
		while(ri-le>=1&&overcome(loc,best[le],best[le+1],splits)){
			le++;
		}
		best[--le]=loc;
	}
	else {
		while (ri - le >= 1 && point[le] >= (te = overcomepoint(loc, best[le], splits))) {
			le++;
		}
		best[--le]=loc;
		if(ri-le<=1){
			te=overcomepoint(loc,best[le+1],splits);
		}
		point[le]=te;
	}
	while(ri-le>=1&&(arr[loc]-arr[best[ri]-1])*(arr[n]-arr[loc])+dp[flip][best[ri]-1]<=(arr[loc]-arr[best[ri-1]-1])*(arr[n]-arr[loc])+dp[flip][best[ri-1]-1]){
		ri--;
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	n=readint();
	k=readint();
	for(int i=1;i<=n;i++){
		arr[i]=(lli)readint();
		arr[i]+=arr[i-1];
	}
	for(int i=1;i<=k;i++){
		ded[op][i-1]=false;
		for(int j=i;j<n;j++){
			dp[op][j]=dp[op][j-1];
			calcbest(i,j);
			lli temp=(arr[j]-arr[best[ri]-1])*(arr[n]-arr[j])+dp[flip][best[ri]-1];
			if(temp>=dp[op][j]){
				ded[op][j]=false;
				dp[op][j]=temp;
				if(ded[flip][best[ri]-1]){
					from[i][j]=from[i-1][best[ri]-1];
				}
				else from[i][j]=best[ri]-1;
			}
			else{
				ded[op][j]=true;
				if(ded[op][j-1])from[i][j]=from[i][j-1];
				else from[i][j]=j-1;
			}
		}
		flip=op;
		op=(flip+1)%2;
		le=100001;
		ri=100000;
	}
	printf("%lli\n",dp[flip][n-1]);
	int fin[k+1];
	int cur;
	if(ded[flip][n-1])cur=from[k][n-1];
	else cur=n-1;
	for(int i=k;i>0;i--){
		fin[i]=cur;
		cur = from[i][cur];
	}
	for(int i=1;i<=k;i++){
		printf("%d ",max(1,fin[i]));
	}
	return 0;
}
//52,60
//dp[i-1][j-1] is constant
//arr[j]-arr[l-1] increases
//(arr[i]-arr[a-1])*(arr[n]-arr[i])+dp[splits-1][a-1].ans>=(arr[i]-arr[b-1])*(arr[n]-arr[i])+dp[splits-1][b-1].ans for a>b
//-arr[i]^2+arr[i](arr[a-1]+arr[n])-arr[a-1]*arr[n]+dp[splits-1][a-1]>=-arr[i]^2+arr[i](arr[b-1]+arr[n])-arr[b-1]*arr[n]+dp[splits-1][b-1]
//arr[i]>=(-arr[b-1]*arr[n]+dp[splits-1][b-1]+arr[a-1]*arr[n]-dp[splits-1][a-1])/(arr[a-1]-arr[b-1])
//-arr[i]^2+arr[i](arr[a-1]+arr[n])-arr[a-1]*arr[n]+dp[splits-1][a-1]>=-arr[i]^2+arr[i](arr[b-1]+arr[n])-arr[b-1]*arr[n]+dp[splits-1][b-1]
//arr[i](arr[a-1]+arr[n])-arr[a-1]*arr[n]+dp[splits-1][a-1]>=arr[i](arr[b-1]+arr[n])-arr[b-1]*arr[n]+dp[splits-1][b-1]
//arr[i](arr[a-1]-arr[b-1])>=-arr[b-1]*arr[n]+dp[splits-1][b-1]+arr[a-1]*arr[n]-dp[splits-1][a-1]
//arr[i]>=(-arr[b-1]*arr[n]+dp[splits-1][b-1]+arr[a-1]*arr[n]-dp[splits-1][a-1])/(arr[a-1]-arr[b-1])
/*
(arr[i]-arr[a-1])*(arr[n]-arr[i])+dp[splits-1][a-1].ans>=(arr[i]-arr[b-1])*(arr[n]-arr[i])+dp[splits-1][b-1].ans
-arr[i]^2+arr[i](arr[n]+arr[a-1])-arr[a-1]*arr[n]+dp[splits-1][a-1]>=-arr[i]^2+arr[i](arr[n]+arr[b-1])-arr[b-1]*arr[n]+dp[splits-1][b-1]
arr[i](arr[n]+arr[a-1])-arr[a-1]*arr[n]+dp[splits-1][a-1]>=arr[i](arr[n]+arr[b-1])-arr[b-1]*arr[n]+dp[splits-1][b-1]
arr[i](arr[n]+arr[a-1]-arr[n]-arr[b-1])>=-arr[b-1]*arr[n]+dp[splits-1][b-1]+arr[a-1]*arr[n]-dp[splits-1][a-1]
arr[i](arr[a-1]-arr[b-1])>=arr[n](arr[a-1]-arr[b-1])+dp[splits-1][b-1]-dp[splits-1][a-1]
arr[i]>=arr[n](arr[a-1]-arr[b-1])+dp[splits-1][b-1]-dp[splits-1][a-1]/(arr[a-1]-arr[b-1])
(((long double)(arr[n]*(arr[a-1]-arr[b-1])+dp[splits-1][b-1].ans-dp[splits-1][a-1].ans))/(long double)(arr[a-1]-arr[b-1]))
 */