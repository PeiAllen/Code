#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
typedef long long int lli;
int mod=262143;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	int maxblocksize=64;
	int maxval=0;
	int numblock=n/maxblocksize+2;
	int preans[numblock][numblock];
	int arr[n];
	int precalc[n];
	int leftb[numblock];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		precalc[i]=i/maxblocksize;
		maxval=max(maxval,arr[i]);
	}
	for(int i=0;i<numblock;i++){
		leftb[i]=i*maxblocksize;
	}
	int am[maxval+1]={};
	int lastused[maxval+1]={};
	vector<int> locs[maxval+1];
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=2*am[arr[i]]+1;
		am[arr[i]]+=1;
		locs[arr[i]].push_back(i);
		if((i+1)%maxblocksize==0){
			ans&=mod;
			preans[0][precalc[i]]=ans;
		}
	}
	memset(am,0,sizeof(am));
	ans=0;
	int cnt=2;
	for(int i=maxblocksize;i<n;i+=maxblocksize){
		for(int j=i;j<n;j++){
			ans+=2*am[arr[j]]+1;
			am[arr[j]]+=1;
			if((j+1)%maxblocksize==0){
				ans&=mod;
				preans[precalc[i]][precalc[j]]=ans;
			}
		}
		memset(am,0,sizeof(am));
		cnt+=1;
		ans=0;
	}
	int l,r;
	while(q--){
		cin>>l>>r;
		l^=ans;
		r^=ans;
		int leftblock=precalc[l]+1;
		int rightblock=precalc[r]-1;
		if(leftblock<=rightblock)ans=preans[leftblock][rightblock];
		else ans=0;
		ans&=mod;
		if(leftblock-1==rightblock+1){
			for(int i=l;i<=r;i++){
				if(lastused[arr[i]]!=cnt)am[arr[i]]=0;
				ans+=2*am[arr[i]]+1;
				am[arr[i]]+=1;
				lastused[arr[i]]=cnt;
			}
		}
		else{
			for(int i=l;i<leftb[leftblock];i++){
				if(lastused[arr[i]]!=cnt){
					if(rightblock>=leftblock)am[arr[i]]=lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),leftb[rightblock+1])-lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),leftb[leftblock]);
					else am[arr[i]]=0;
				}
				ans+=2*am[arr[i]]+1;
				am[arr[i]]+=1;
				lastused[arr[i]]=cnt;
			}
			for(int i=leftb[rightblock+1];i<=r;i++){
				if(lastused[arr[i]]!=cnt){
					if(rightblock>=leftblock)am[arr[i]]=lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),leftb[rightblock+1])-lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),leftb[leftblock]);
					else am[arr[i]]=0;
				}
				ans+=2*am[arr[i]]+1;
				am[arr[i]]+=1;
				lastused[arr[i]]=cnt;
			}
		}
		cnt+=1;
		ans&=mod;
		printf("%d\n",ans);
	}
	return 0;
}

/*
7 1
1 2 2 2 1 3 4
0 6
 */