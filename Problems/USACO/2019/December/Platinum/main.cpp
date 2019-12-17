#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+3;
vector<int> matrix[MAXN];
vector<int> eulertour;
pii locs[MAXN];
//lli colours[MAXN];
lli bit[2][MAXN];
int sizes[2];
void update(int ind, int loc, lli am){
	for(;loc<sizes[ind];loc+=loc&-loc)bit[ind][loc]+=am;
}
lli query(int ind, int loc){
	lli sum=0;
	for(;loc>0;loc-=loc&-loc)sum+=bit[ind][loc];
	return sum;
}
void dfs(int loc, int parent){
	locs[loc].first=sz(eulertour);
	eulertour.push_back(loc);
	for(int x:matrix[loc]){
		if(x!=parent)dfs(x,loc);
	}
	locs[loc].second=sz(eulertour)-1;
}
struct block{
	//lli sum;
	set<int> colours[MAXN];
	lli size;
	set<int> allcol;
	block(){
		//	sum=0;
		size=0;
		allcol={};
	}
};
vector<block> barr;
int curb[MAXN];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("snowcow.in","r",stdin);
	freopen("snowcow.out","w",stdout);
	int n,q;
	sc(n,q);
	int a,b;
	sizes[0]=n;
	int blocksize=max(1,(int)sqrt(0.5*n));
	sizes[1]=n/blocksize+1;
	barr.resize(n/blocksize+1);
	rep(i,1,n){
		sc(a,b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	rep(i,0,n){
		curb[i]=i/blocksize;
		if(i%blocksize==0)barr[i/blocksize].size=min(blocksize,n-i);
	}
	curb[n]=n/blocksize;
	dfs(1,0);
	int c;
	while(q--){
		sc(a,b);
		if(a==1){
			sc(c);
			int cur=locs[b].first;
			while(cur<=locs[b].second){
				if(cur%blocksize==0&&cur+blocksize-1<=locs[b].second){
					if(!barr[curb[cur]].allcol.count(c)) {
						barr[curb[cur]].allcol.insert(c);
						if(sz(barr[curb[cur]].colours[c])){
							if(sz(barr[curb[cur]].colours[c])!=barr[curb[cur]].size) {
								//barr[curb[cur]].sum += barr[curb[cur]].size - sz(barr[curb[cur]].colours[c]);
								update(1,curb[cur]+1,barr[curb[cur]].size - sz(barr[curb[cur]].colours[c]));
								for (int x:barr[curb[cur]].colours[c]){
									update(0,x+1,-1);
									//	colours[x] -= 1;
								}
							}
						}
						else{
//							barr[curb[cur]].sum += barr[curb[cur]].size;
							update(1,curb[cur]+1,barr[curb[cur]].size);
						}
					}
					cur+=blocksize;
				}
				else{
					if(!barr[curb[cur]].allcol.count(c)&&(!barr[curb[cur]].colours[c].count(cur))) {
						//		colours[cur]+=1;
						update(0,cur+1,1);
						barr[curb[cur]].colours[c].insert(cur);
						//	barr[curb[cur]].sum+=1;
						update(1,curb[cur]+1,1);
//						if(sz(barr[curb[cur]].colours[c])==barr[curb[cur]].size){
//							barr[curb[cur]].allcol.insert(c);
//							for(int x:barr[curb[cur]].colours[c])colours[x]-=1;
//							barr[curb[cur]].colours.erase(c);
//						}
					}
					cur+=1;
				}
			}
		}
		else{
			int cur=locs[b].first;
			lli ans=0;
			if(cur%blocksize){
				lli l=cur;
				lli r=((curb[cur])+1)*blocksize-1;
				ans+=query(0,r+1)-query(0,l);
				ans+=(lli)sz(barr[curb[cur]].allcol)*(r-l+1);
			}
			lli l=(cur-1<0?0:(curb[cur-1])+1);
			lli r=curb[locs[b].second+1]-1;
			if(r>=l){
				ans+=query(1,r+1)-query(1,l);
			}
			if((locs[b].second+1)%blocksize&&curb[cur]!=curb[locs[b].second]) {
				r = locs[b].second;
				l = curb[locs[b].second] * blocksize;
				ans+=query(0,r+1)-query(0,l);
				ans+=(lli)sz(barr[curb[cur]].allcol)*(r-l+1);
			}
//			while(cur<=locs[b].second) {
//				if(cur%blocksize==0&&cur+blocksize-1<=locs[b].second) {
//					ans+=barr[curb[cur]].sum;
//					cur+=blocksize;
//				}
//				else{
//					ans+=sz(barr[curb[cur]].allcol)+colours[cur];
//					cur+=1;
//				}
//			}

			prl(ans);
		}
	}
	return 0;
}
/*
5 4
1 2
1 3
3 4
3 5
1 4 1
1 5 1
1 1 1
2 1
 */