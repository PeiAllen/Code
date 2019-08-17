#include <bits/stdc++.h>
#define ll long long
#define MN 1001
#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f
#define pb push_back
using namespace std;

int main() {
	int n,q;cin>>n>>q;
	int arr [n+1], ml [n+1], mr [n+1], fl [n+1], fr [n+1];
	memset(ml,0,sizeof(ml));
	memset(mr,0,sizeof(mr));
	memset(fl,0,sizeof(fl));
	memset(fr,0,sizeof(fr));
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int mx = 0;
	int freq = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i]>mx){mx=arr[i];freq=0;}
		ml[i]=mx;
		if(arr[i]==mx)freq++;
		fl[i]=freq;
	}
	mx=0;
	freq = 0;
	for(int i = n;i>0;i--){
		if(arr[i]>mx){mx=arr[i];freq=0;}
		mr[i]=mx;
		if(arr[i]=mx)freq++;
		fr[i]=freq;
	}
	while(q--){
		int a,b;cin>>a>>b;
		int m = max(ml[a-1],mr[b+1]);
		int cnt;
		if(ml[a-1]==mr[b+1])cnt = fl[a-1] + fr[b+1];
		else if (ml[a-1]>mr[b+1])cnt = fl[a-1];
		else if (ml[a-1]<mr[b+1])cnt = fr[b+1];
		cout<<m<<' '<<cnt<<'\n';
	}
	return 0;
}