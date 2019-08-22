#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int maxphotos;
vector<pll> segments;
double dp[100001];
double calc(int a, int b){//a>b
	return (double)((double)dp[b]-pow(max((lli)0,segments[b].second-segments[b+1].first+1),2)-(double)dp[a]+pow(max((lli)0,segments[a].second-segments[a+1].first+1),2)-pow((segments[a+1].first-1),2)+pow((segments[b+1].first-1),2))/(double)(2*(segments[b+1].first-1)-2*(segments[a+1].first-1));
}
long long run(double constant){
	int cnt[segments.size()]={};
	dp[0]=0;
	int deq[segments.size()+2];
	int le=0;
	int ri=-1;
	deq[++ri]=0;
	for(int i=1;i<segments.size();i++){
		while(ri-le>=1&&calc(deq[le+1],deq[le])<=segments[i].second)le++;
		double te=constant+dp[deq[le]]+pow(segments[i].second-segments[deq[le]+1].first+1,2)-pow(max((lli)0,segments[deq[le]].second-segments[deq[le]+1].first+1),2);
		dp[i]=te;
		cnt[i]=cnt[deq[le]]+1;
		while(ri-le>=1&&calc(deq[ri],deq[ri-1])>=calc(i,deq[ri]))ri--;
		deq[++ri]=i;
	}
	if(cnt[segments.size()-1]<=maxphotos)return ceil(dp[segments.size()-1]-constant*(double)cnt[segments.size()-1]);
	else return -1;
}
long long take_photos(int n, int m, int k, int* r, int* c){
	maxphotos=k;
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
	double lo=0;
	double hi=1e28;
	double acc=1e9;
	while(lo!=hi){
		double mid=floor((lo+hi)/2);
		if(run(mid/acc)!=-1)hi=mid;
		else lo=mid+1;
	}
	return run(hi/acc);
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