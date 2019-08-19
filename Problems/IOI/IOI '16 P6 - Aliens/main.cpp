#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
long long bsize;
int maxphotos;
long long layersparse[20][1000001];
long long querysparse(long long a, long long b){
	long long k=log2(b-a+1);
	return min(layersparse[k][a],layersparse[k][b-(1<<k)+1]);
}
long long run(long long constant){//brute
	long long dp[bsize+1];
	long long cnt[bsize+1];
	long long photosize[bsize+1];
	photosize[0]=0;
	cnt[0]=0;
	dp[0]=0;
	for(long long i=1;i<=bsize;i++){
		dp[i]=LLONG_MAX;
		for(long long j=0;j<i;j++){
			long long taketo=querysparse(j+1,i);
			long long totake=pow(max((long long)0,i-taketo+1),2);
			if(taketo<=j)totake-=pow(min(photosize[j],(j-taketo+1)),2);
			long long te=dp[j]+totake+(totake?constant:0);
			if(te<dp[i]){
				photosize[i]=max((long long)0,i-taketo+1);
				dp[i]=te;
				cnt[i]=cnt[j]+(totake?1:0);
			}
		}
	}
	if(cnt[bsize]>maxphotos)return -1;
	else return dp[bsize]-cnt[bsize]*constant;
}
long long take_photos(int n, int m, int k, int* r, int* c){
	maxphotos=k;
	bsize=m;
	for(int i=1;i<=m;i++)layersparse[0][i]=INT_MAX;
	for(int i=0;i<n;i++){
		layersparse[0][max(r[i]+1,c[i]+1)]=min(layersparse[0][max(r[i]+1,c[i]+1)],(long long)min(r[i]+1,c[i]+1));
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=m+1-(1<<i);j++){
			layersparse[i][j]=min(layersparse[i-1][j],layersparse[i-1][j+(1<<(i-1))]);
		}
	}
	long long lo=0;
	long long hi=pow((long long)m,2)+20000;
	while(lo!=hi){
		long long mid=(lo+hi)/2;
		if(run(mid)!=-1)hi=mid;
		else lo=mid+1;
	}
	return run(lo);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}