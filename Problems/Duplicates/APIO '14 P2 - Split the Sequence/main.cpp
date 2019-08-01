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
int le=100001;
int ri=100000;
int flip=0;
int points[100001];
int overcomepoint(int a, int b, int splits){//a>b
	int lo=1;
	int hi=n-1;
	while(lo!=hi){
		int mid=(lo+hi)/2;
		if((arr[mid]-arr[a-1])*(arr[n]-arr[mid])+dp[flip][a-1]>=(arr[mid]-arr[b-1])*(arr[n]-arr[mid])+dp[flip][b-1]){
			hi=mid;
		}
		else{
			lo=mid+1;
		}
	}
	if(lo==n-1&&(arr[lo]-arr[a-1])*(arr[n]-arr[lo])+dp[flip][a-1]<(arr[lo]-arr[b-1])*(arr[n]-arr[lo])+dp[flip][b-1])return n;
	return lo;
}
void calcbest(int splits, int loc){
	int te;
	while(ri-le>=1&&points[le]>=(te=overcomepoint(loc,best[le],splits))){
		le++;
	}
	if(ri-le==0)te=overcomepoint(loc,best[le],splits);
	best[--le]=loc;
	points[le]=te;
	while(ri-le>=1&&points[ri-1]<=loc){
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
		ded[(flip+1)%2][i-1]=false;
		for(int j=i;j<n;j++){
			dp[(flip+1)%2][j]=dp[(flip+1)%2][j-1];
			calcbest(i,j);
			lli temp=(arr[j]-arr[best[ri]-1])*(arr[n]-arr[j])+dp[flip][best[ri]-1];
			if(temp>=dp[(flip+1)%2][j]){
				ded[(flip+1)%2][j]=false;
				dp[(flip+1)%2][j]=temp;
				if(ded[flip][best[ri]-1]){
					from[i][j]=from[i-1][best[ri]-1];
				}
				else from[i][j]=best[ri]-1;
			}
			else{
				ded[(flip+1)%2][j]=true;
				if(ded[(flip+1)%2][j-1])from[i][j]=from[i][j-1];
				else from[i][j]=j-1;
			}
		}
		flip=(flip+1)%2;
		le=100001;
		ri=100000;
	}
	printf("%lli\n",dp[flip][n-1]);
	stack<int> st;
	int cur;
	if(ded[flip][n-1])cur=from[k][n-1];
	else cur=n-1;
	for(int i=k;i>0;i--){
		st.push(cur);
		cur = from[i][cur];
	}
	while(st.size()){
		printf("%d ",max(1,st.top()));
		st.pop();
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