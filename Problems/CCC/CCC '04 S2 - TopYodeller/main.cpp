#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	pair<int,int> slavesofwilliam[n];
	int ch[n];
	int worst[n];
	for(int i=0;i<n;i++){
		slavesofwilliam[i]={0,i};
		worst[i]=1;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)cin>>ch[j];
		for(int j=0;j<n;j++){
			slavesofwilliam[j].first-=ch[slavesofwilliam[j].second];
		}
		sort(slavesofwilliam,slavesofwilliam+n);
		int place=1;
		worst[slavesofwilliam[0].second]=max(worst[slavesofwilliam[0].second],place);
		for(int j=1;j<n;j++){
			if(slavesofwilliam[j].first!=slavesofwilliam[j-1].first)place+=1;
			worst[slavesofwilliam[j].second]=max(worst[slavesofwilliam[j].second],place);
		}
	}
	printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n",slavesofwilliam[0].second+1,-slavesofwilliam[0].first,worst[slavesofwilliam[0].second]);
	for(int i=1;i<n;i++){
		if(slavesofwilliam[i].first==slavesofwilliam[i-1].first)printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n",slavesofwilliam[i].second+1,-slavesofwilliam[i].first,worst[slavesofwilliam[i].second]);
		else break;
	}
	return 0;
}