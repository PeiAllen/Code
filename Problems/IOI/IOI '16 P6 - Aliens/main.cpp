#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int maxphotos;
vector<pll> segments;
long long run(long long constant){//brute
	long long dp[segments.size()]={};
	int cnt[segments.size()]={};
	for(int i=1;i<segments.size();i++){
		dp[i]=LLONG_MAX;
		 for(int j=0;j<i;j++){
		 	lli te=constant+dp[j]+(lli)pow(segments[i].second-segments[j+1].first+1,2)-(lli)pow(max((lli)0,segments[j].second-segments[j+1].first+1),2);
			if(te<dp[i]){
				dp[i]=te;
				cnt[i]=cnt[j]+1;
			}
		 }
	}
	if(cnt[segments.size()-1]<=maxphotos)return dp[segments.size()-1]-constant*cnt[segments.size()-1];
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
	long long lo=0;
	long long hi=pow((long long)m,2);
	while(lo!=hi){
		long long mid=(lo+hi)/2;
		if(run(mid)!=-1)hi=mid;
		else lo=mid+1;
	}
	return run(lo);
}
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    int l[5]={0, 4, 4, 4, 4};
//    int r[5]={3, 4, 6, 5, 6};
//    printf("%lli\n",take_photos(5, 7, 2, l, r));
//    return 0;
//}