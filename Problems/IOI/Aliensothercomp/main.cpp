#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int maxphotos;
vector<pll> segments;
long double dp[100001];
long double precalc[1100000];
long double donebefore[100009];
int deq[100009];
int cnt[100001];
inline long double calc(int a, int b){//a>b
	return (long double)((long double)dp[b]-precalc[max((lli)0,segments[b].second-segments[b+1].first+1)]-(long double)dp[a]+precalc[max((lli)0,segments[a].second-segments[a+1].first+1)]-precalc[(segments[a+1].first-1)]+precalc[(segments[b+1].first-1)])/(long double)(2*(segments[b+1].first-1)-2*(segments[a+1].first-1));
}
long long run(long double constant){
	int le=0;
	int ri=-1;
	deq[++ri]=0;
	for(int i=1;i<segments.size();i++){
		while(ri-le>=1&&donebefore[le]<=segments[i].second)le++;
		long double te=constant+dp[deq[le]]+precalc[segments[i].second-segments[deq[le]+1].first+1]-precalc[max((lli)0,segments[deq[le]].second-segments[deq[le]+1].first+1)];
		dp[i]=te;
		cnt[i]=cnt[deq[le]]+1;
		if(i!=segments.size()-1) {
			while (ri - le >= 1 && donebefore[ri - 1] >= (donebefore[ri] = calc(i, deq[ri])))ri--;
			if (ri - le < 1)donebefore[ri] = calc(i, deq[ri]);
			deq[++ri] = i;
		}
	}
	if(cnt[segments.size()-1]<=maxphotos)return round(dp[segments.size()-1]-constant*(long double)cnt[segments.size()-1]);
	else return -1;
}
long long take_photos(int n, int m, int k, int* r, int* c){
	maxphotos=k;
	for(int i=0;i<1100000;i++)precalc[i]=pow((long double)i,(long double)2);
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
	long double lo=0;
	long double hi=1e16;
	long double acc=1e2;
	while(hi!=lo){
		long double mid=floor((lo+hi)/2);
		if(run(mid/acc)!=-1)hi=mid;
		else lo=mid+1;
	}
	lli res=run(hi/acc);
	lli cntam=cnt[segments.size()-1];
	if(hi==0)return res;
	run((hi-1)/acc);
	lli res2=round(dp[segments.size()-1]-((hi-1)/acc)*(long double)cnt[segments.size()-1]);
	lli cntam2=cnt[segments.size()-1];
	lli diff=(res2-res)/(cntam2-cntam);
	return res+diff*((lli)k-cntam);
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