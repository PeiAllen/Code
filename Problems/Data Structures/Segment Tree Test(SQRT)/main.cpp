#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int blocksize;
struct block{
	int min,gcd,gcdam;
	vector<int> arr;
	block(){
		min=0;
		gcd=0;
		gcdam=0;
	}
};
int gcd(int a, int b){
	if(!a)return b;
	return gcd(b%a,a);
}
vector<block> arr;
void calc(int loc){
	int mi=INT_MAX;
	int gc=0;
	int gcam=0;
	for(int x:arr[loc].arr){
		mi=min(mi,x);
		int te=gcd(gc,x);
		if(te!=gc){
			gc=te;
			gcam=0;
		}
		if(x==gc)gcam+=1;
	}
	arr[loc].min=mi;
	arr[loc].gcd=gc;
	arr[loc].gcdam=gcam;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	blocksize=sqrt(n);
	int loc=-1;
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		if(i%blocksize==0){
			if(i!=0){
				calc(loc);
			}
			loc++;
			arr.push_back(block());
		}
		arr[loc].arr.push_back(in);
	}
	calc(loc);
	char a;
	int b,c;
	while(m--){
		cin>>a>>b>>c;
		if(a=='C'){
			b-=1;
			int wblock=b/blocksize;
			arr[wblock].arr[b-wblock*blocksize]=c;
			calc(wblock);
		}
		else if(a=='M'){
			b-=1;
			c-=1;
			int lblock=b/blocksize;
			int rblock=c/blocksize;
			int mi=INT_MAX;
			if(lblock==rblock){
				for(int i=b-lblock*blocksize;i<=c-rblock*blocksize;i++){
					mi=min(mi,arr[lblock].arr[i]);
				}
			}
			else {
				for (int i = b - lblock * blocksize; i < arr[lblock].arr.size(); i++) {
					mi = min(mi, arr[lblock].arr[i]);
				}
				for (int i = lblock + 1; i < rblock; i++) {
					mi = min(mi, arr[i].min);
				}
				for (int i = 0; i <= c - rblock * blocksize; i++) {
					mi = min(mi, arr[rblock].arr[i]);
				}
			}
			printf("%d\n",mi);
		}
		else if(a=='G'){
			b-=1;
			c-=1;
			int lblock=b/blocksize;
			int rblock=c/blocksize;
			int gc=0;
			if(lblock==rblock){
				for(int i=b-lblock*blocksize;i<=c-rblock*blocksize;i++){
					gc = gcd(gc, arr[lblock].arr[i]);
				}
			}
			else {
				for (int i = b - lblock * blocksize; i < arr[lblock].arr.size(); i++) {
					gc = gcd(gc, arr[lblock].arr[i]);
				}
				for (int i = lblock + 1; i < rblock; i++) {
					gc = gcd(gc, arr[i].gcd);
				}
				for (int i = 0; i <= c - rblock * blocksize; i++) {
					gc = gcd(gc, arr[rblock].arr[i]);
				}
			}
			printf("%d\n",gc);
		}
		else{
			b-=1;
			c-=1;
			int lblock=b/blocksize;
			int rblock=c/blocksize;
			int gc=0;
			int gcam=0;
			if(lblock==rblock){
				for(int i=b-lblock*blocksize;i<=c-rblock*blocksize;i++){
					int te = gcd(gc, arr[lblock].arr[i]);
					if (te != gc) {
						gc = te;
						gcam = 0;
					}
					if (arr[lblock].arr[i] == gc)gcam += 1;
				}
			}
			else {
				for (int i = b - lblock * blocksize; i < arr[lblock].arr.size(); i++) {
					int te = gcd(gc, arr[lblock].arr[i]);
					if (te != gc) {
						gc = te;
						gcam = 0;
					}
					if (arr[lblock].arr[i] == gc)gcam += 1;
				}
				for (int i = lblock + 1; i < rblock; i++) {
					int te = gcd(gc, arr[i].gcd);
					if (te != gc) {
						gc = te;
						gcam = 0;
					}
					if (arr[i].gcd == gc)gcam += arr[i].gcdam;
				}
				for (int i = 0; i <= c - rblock * blocksize; i++) {
					int te = gcd(gc, arr[rblock].arr[i]);
					if (te != gc) {
						gc = te;
						gcam = 0;
					}
					if (arr[rblock].arr[i] == gc)gcam += 1;
				}
			}
			printf("%d\n",gcam);
		}
	}
	return 0;
}