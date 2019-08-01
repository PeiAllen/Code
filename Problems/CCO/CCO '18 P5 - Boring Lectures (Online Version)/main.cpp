#include<bits/stdc++.h>

using namespace std;
int arr[1000001];
int n,k,q;
int comp(int a, int b){
	if(arr[a]==arr[b]){
		if(a<b)return b;
		return a;
	}
	if(arr[a]<arr[b])return b;
	return a;
}
struct node {
	int idx,data;
	node(int a = 0, int b=0) : data(a),idx(b){}
};
node maxtree[2000002];
	void mt(){
		for(int i=n*2-1;i>=1;i--){
			if(i<n) {
				maxtree[i].idx = comp(maxtree[i<<1].idx,maxtree[i<<1|1].idx);
			} else {
				maxtree[i].idx = i-n+1;
			}
		}
	}
	int query(int l, int r){
		int ansl=0;
		int ansr=0;
		for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){
			if(l&1)ansl=comp(ansl,maxtree[l++].idx);
			if(!(r&1))ansr=comp(maxtree[r--].idx,ansr);
		}
		return comp(ansl,ansr);
	}
	inline int querylocalmax(int loc){
		int ans=0;
		if(loc>1)ans=comp(ans,query(max(1,loc-k+1),loc-1));
		if(loc<n)ans=comp(ans,query(loc+1,min(n,loc+k-1)));
		return ans;
	}
	void ansmt(){
		for(int i=n*2-1;i>=1;i--){
			if(i<n) {
				maxtree[i].data = max(maxtree[i<<1].data, maxtree[i<<1|1].data);
			}
			else {
				int localidx = querylocalmax(i - n + 1);
				if (arr[localidx] <= arr[i - n + 1]) {
					maxtree[i].data = arr[localidx] + arr[i - n + 1];
				}
			}
		}
	}
	void ansupdate(int loc){
		int idx=n-1+loc;
		int localidx=querylocalmax(loc);
		if(arr[localidx]<=arr[loc])maxtree[idx].data=arr[localidx]+arr[loc];
		else maxtree[idx].data=0;
		for(idx>>=1;idx>=1;idx>>=1) {
			maxtree[idx].data = max(maxtree[idx<<1].data, maxtree[idx<<1|1].data);
			maxtree[idx].idx = comp(maxtree[idx<<1].idx,maxtree[idx<<1|1].idx);
		}
	}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	scanf("%d %d %d",&n,&k,&q);
	arr[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	mt();
	ansmt();
	int prevans=maxtree[1].data;
	printf("%d\n",maxtree[1].data);
	int a,b;
	while(q--){
		scanf("%d %d",&a,&b);
		a^=prevans;
		b^=prevans;
		arr[a]=b;
		ansupdate(a);
		if(a>1)ansupdate(query(max(1,a-k+1),a-1));
		if(a<n)ansupdate(query(a+1,min(n,a+k-1)));
		prevans=maxtree[1].data;
		printf("%d\n",maxtree[1].data);
	}
	return 0;
}