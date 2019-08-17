#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,m;
	cin>>n>>m;
	lli arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	lli am[n]={};
	lli ream=0;
	int deq[2*n+1];
	int le=0;
	int ri=-1;
	lli flipam=0;
	lli totam=0;
	set<lli> done;
	int last=0;
	for(int i=0;i<2*n;i++){
		lli dist=((arr[i%n]<=arr[last]&&(i%n<=last))?(m-abs(arr[i%n]-arr[last])):abs(arr[i%n]-arr[last]));
		ream+=totam*dist-flipam*2*dist;
		int tedist=0;
		if(le<=ri)tedist=((arr[i%n]<=arr[deq[le]]&&(i%n<=deq[le]))?(m-abs(arr[i%n]-arr[deq[le]])):abs(arr[i%n]-arr[deq[le]]));
		while(le<=ri&&tedist>m-tedist){
			ream-=tedist;
			ream+=m-tedist;
			le++;
			flipam+=1;
			if(le<=ri)tedist=((arr[i%n]<=arr[deq[le]]&&(i%n<=deq[le]))?(m-abs(arr[i%n]-arr[deq[le]])):abs(arr[i%n]-arr[deq[le]]));
		}
		am[i%n]+=ream;
		if(done.count(i%n)){
			totam-=1;
			flipam-=1;
		}
		else{
			deq[++ri]=i%n;
			totam+=1;
			done.insert(i%n);
		}
		last=i%n;
	}
	lli ans=LLONG_MAX;
	for(int i=0;i<n;i++){
		ans=min(ans,am[i]);
	}
	printf("%lli\n",ans);
	return 0;
}

/*
2 10
1 2
1 1000
1000
2 1000
1000 1000
 */