#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
typedef long long int lli;
lli mod=(1<<18);
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	int maxblocksize=sqrt(n);
	int maxval=0;
	vector<int> todel;
	lli preans[n/maxblocksize+2][n/maxblocksize+2];
	int arr[n];
	int precalc[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		precalc[i]=i/maxblocksize;
		maxval=max(maxval,arr[i]);
	}
	lli am[maxval+1]={};
	vector<int> locs[maxval+1];
	lli ans=0;
	for(int i=0;i<n;i++){
		if(am[arr[i]]==0)todel.push_back(arr[i]);
		ans+=2*am[arr[i]]+1;
		am[arr[i]]+=1;
		locs[arr[i]].push_back(i);
		if((i+1)%maxblocksize==0){
			preans[0][precalc[i]]=ans;
		}
	}
	for(int x:todel){
		am[x]=0;
	}
	todel.clear();
	ans=0;
	for(int i=maxblocksize;i<n;i+=maxblocksize){
		for(int j=i;j<n;j++){
			if(am[arr[j]]==0)todel.push_back(arr[j]);
			ans+=2*am[arr[j]]+1;
			am[arr[j]]+=1;
			if((j+1)%maxblocksize==0){
				preans[precalc[i]][precalc[j]]=ans;
			}
		}
		for(int x:todel){
			am[x]=0;
		}
		todel.clear();
		ans=0;
	}
	int l,r;
	while(q--){
		cin>>l>>r;
		l^=ans;
		r^=ans;
		int leftblock=l/maxblocksize+1;
		int rightblock=r/maxblocksize-1;
		if(leftblock<=rightblock)ans=preans[leftblock][rightblock];
		else ans=0;
		if(leftblock-1==rightblock+1){
			for(int i=l;i<=r;i++){
				if(am[arr[i]]==0){
					todel.push_back(arr[i]);
				}
				ans+=2*am[arr[i]]+1;
				am[arr[i]]+=1;
			}
		}
		else{
			for(int i=l;i<leftblock*maxblocksize;i++){
				if(am[arr[i]]==0){
					todel.push_back(arr[i]);
					if(rightblock>=leftblock)am[arr[i]]=lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),(rightblock+1)*maxblocksize)-lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),leftblock*maxblocksize);
				}
				ans+=2*am[arr[i]]+1;
				am[arr[i]]+=1;
			}
			for(int i=(rightblock+1)*maxblocksize;i<=r;i++){
				if(am[arr[i]]==0){
					todel.push_back(arr[i]);
					if(rightblock>=leftblock)am[arr[i]]=lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),(rightblock+1)*maxblocksize)-lower_bound(locs[arr[i]].begin(),locs[arr[i]].end(),leftblock*maxblocksize);
				}
				ans+=2*am[arr[i]]+1;
				am[arr[i]]+=1;
			}
		}
		for(int x:todel){
			am[x]=0;
		}
		todel.clear();
		ans%=mod;
		printf("%lli\n",ans);
	}
	return 0;
}

/*
7 1
1 2 2 2 1 3 4
0 6
 */