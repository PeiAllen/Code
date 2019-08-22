#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int maxphotos;
vector<pll> segments;
long double dp2[100001];
long double precalc[1100000];
double donebefore[100009];
int deq[100009];
int cnt[100001];
inline double calc(int a, int b){//a>b
	return (double)( (double)dp2[b]-precalc[max((lli)0,segments[b].second-segments[b+1].first+1)]- (double)dp2[a]+precalc[max((lli)0,segments[a].second-segments[a+1].first+1)]-precalc[(segments[a+1].first-1)]+precalc[(segments[b+1].first-1)])/ (double)(2*(segments[b+1].first-1)-2*(segments[a+1].first-1));
}
long long run(long double constant){

	dp2[0]=0;

	int le=0;
	int ri=-1;
	deq[++ri]=0;
	for(int i=1;i<segments.size();i++){
		while(ri-le>=1&&donebefore[le]<segments[i].second)le++;
		long double te=constant+dp2[deq[le]]+precalc[segments[i].second-segments[deq[le]+1].first+1]-precalc[max((lli)0,segments[deq[le]].second-segments[deq[le]+1].first+1)];
		dp2[i]=te;
		cnt[i]=cnt[deq[le]]+1;
		if(i!=segments.size()-1) {
			while (ri - le >= 1 && donebefore[ri - 1] >= (donebefore[ri] = calc(i, deq[ri])))ri--;
			if (ri - le < 1)donebefore[ri] = calc(i, deq[ri]);
			deq[++ri] = i;
		}
	}
	if(cnt[segments.size()-1]<=maxphotos)return roundl(dp2[segments.size()-1]-constant*cnt[segments.size()-1]);
	else return -1;
}
lli dp[4001][4001];
long long calc2(int a, int b, int k){//a>b
	return (long long)((long long)dp[k-1][b]-pow(max((lli)0,segments[b].second-segments[b+1].first+1),2)-(long long)dp[k-1][a]+pow(max((lli)0,segments[a].second-segments[a+1].first+1),2)-pow((segments[a+1].first-1),2)+pow((segments[b+1].first-1),2))/(long long)(2*(segments[b+1].first-1)-2*(segments[a+1].first-1));
}
long long run2(long long constant){//brute
	memset(dp,0,sizeof(dp));
	for(int i=1;i<segments.size();i++)dp[0][i]=1e12;
	for(int k=1;k<=maxphotos;k++) {
		int le=0;
		int ri=-1;
		deq[++ri]=0;
		for (int i = 1; i < segments.size(); i++) {
			dp[k][i] = dp[k-1][i];
			while(ri-le>=1&&calc2(deq[le+1],deq[le],k)<=segments[i].second)le++;
			lli te=dp[k-1][deq[le]]+pow(segments[i].second-segments[deq[le]+1].first+1,2)-pow(max((lli)0,segments[deq[le]].second-segments[deq[le]+1].first+1),2);
			dp[k][i]=min(dp[k][i],te);
			if(i!=segments.size()-1){
				while(ri-le>=1&&calc2(deq[ri],deq[ri-1],k)>=calc2(i,deq[ri],k))ri--;
				deq[++ri]=i;
			}
		}
	}
	return dp[maxphotos][segments.size()-1];
//	if(cnt[segments.size()-1]<=maxphotos)return dp[segments.size()-1]-constant*(long long)cnt[segments.size()-1];
//	else return -1;
}
long long take_photos(int n, int m, int k, int* r, int* c){
	maxphotos=k;
	for(int i=0;i<=m+1000;i++)precalc[i]=pow((lli)i,2);
	pll tesegments[n];
	for(int i=0;i<n;i++){
		tesegments[i]={min(r[i],c[i]),-max(r[i],c[i])};
	}
	sort(tesegments,tesegments+n);
	segments.push_back({-1,-1});
	for(pii x:tesegments){
		if(!segments.size()||segments.back().second<-x.second){
			segments.push_back({x.first,-x.second});//now all in increasing order
		}
	}
	if(n<=4000){
		return run2(2);
	}
	long double lo=0;
	long double hi=1e14;
	long double acc=1e-8;
	while(hi-lo>=acc){
		long long mid=(lo+hi)/2;
		if(run(mid)!=-1)hi=mid;
		else lo=mid;
	}
	return run(ceil(hi/acc)*acc);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	int l[n];
	int r[n];
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	printf("%lli\n",take_photos(n,m,k, l, r));
	return 0;
}
//dp[a]+(segments[i].second-segments[a+1].first+1)^2-max((lli)0,segments[a].second-segments[a+1].first+1)^2<=dp[b]+(segments[i].second-segments[b+1].first+1)^2-max((lli)0,segments[b].second-segments[b+1].first+1)^2 &&a>b a is better forever
//(segments[i].second-segments[a+1].first+1)^2-(segments[i].second-segments[b+1].first+1)^2<=dp[b]-max((lli)0,segments[b].second-segments[b+1].first+1)^2-dp[a]+max((lli)0,segments[a].second-segments[a+1].first+1)^2
//segments[i].second^2-2*segments[i].second*(segments[a+1].first+1)+(segments[a+1].first+1)^2-segments[i].second^2-2*segments[i].second*(segments[b+1].first+1)-(segments[b+1].first+1)^2<=dp[b]-max((lli)0,segments[b].second-segments[b+1].first+1)^2-dp[a]+max((lli)0,segments[a].second-segments[a+1].first+1)^2
//-2*segments[i].second*(segments[a+1].first+1)+2*segments[i].second*(segments[b+1].first+1)<=dp[b]-max((lli)0,segments[b].second-segments[b+1].first+1)^2-dp[a]+max((lli)0,segments[a].second-segments[a+1].first+1)^2-(segments[a+1].first+1)^2+(segments[b+1].first+1)^2
//segments[i].second(2*(segments[b+1].first+1)-(segments[a+1].first+1)*2)<=dp[b]-max((lli)0,segments[b].second-segments[b+1].first+1)^2-dp[a]+max((lli)0,segments[a].second-segments[a+1].first+1)^2-(segments[a+1].first+1)^2+(segments[b+1].first+1)^2
//segments[i].second>=(dp[b]-max((lli)0,segments[b].second-segments[b+1].first+1)^2-dp[a]+max((lli)0,segments[a].second-segments[a+1].first+1)^2-(segments[a+1].first+1)^2+(segments[b+1].first+1)^2)/(2*(segments[b+1].first+1)-(segments[a+1].first+1)*2)