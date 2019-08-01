#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
char _buf[1048577], *_pbuf = _buf;

int readint() {
	int c, o = 0;
	while ((c = getchar()) < '0');
	do {o = (o<<3)+(o<<1) + (c - '0');} while ((c = getchar()) >= '0');
	return o;
}
const int MAXN=100001;
lli popu[MAXN];
lli newstot[MAXN];
int centparent[MAXN];
vector<int> matrix[MAXN];
int subtreesize[MAXN];
bool centroid[MAXN];
int lca[17][MAXN];
lli prod[17][MAXN];
int n,q;
lli mod=1e9+7;
lli overcnt[MAXN];
int depth[MAXN];
lli inv[MAXN];
lli quickpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(int x:matrix[loc]){
		if(x!=parent&&!centroid[x]) {
			dfssize(x, loc);
			subtreesize[loc] += subtreesize[x];
		}
	}
}
int decompsubtree(int loc, int parent, int size){
	for(int x:matrix[loc]){
		if(x!=parent&&!centroid[x]){
			if(subtreesize[x]>size)return decompsubtree(x,loc,size);
		}
	}
	return loc;
}
int decompfulltree(int loc){
	dfssize(loc,-1);
	int root=decompsubtree(loc,-1,subtreesize[loc]/2);
	centroid[root]=true;
	for(int x:matrix[root]){
		if(!centroid[x]){
			centparent[decompfulltree(x)]=root;
		}
	}
	return root;
}
void dfs(int loc, int parent, int dep){
	lca[0][loc]=parent;
	prod[0][loc]=popu[loc];
	depth[loc]=dep;
	for(int x:matrix[loc])if(x!=parent)dfs(x,loc,dep+1);
}
void makelca(){//prod[loc][0], inclusive first, exclusive last
	for(int j=1;j<=16;j++){
		for(int i=1;i<=n;i++){
			if(lca[j-1][i]==-1){
				lca[j][i]=-1;
				prod[j][i]=0;
			}
			else{
				lca[j][i]=lca[j-1][lca[j-1][i]];
				prod[j][i]=prod[j-1][i]*prod[j-1][lca[j-1][i]]%mod;
			}
		}
	}
}
lli querylca(int a, int b){
	lli ans=1;
	if(depth[a]!=depth[b]){
		if(depth[a]<depth[b])swap(a,b);
		int diff=depth[a]-depth[b];
		for(lli j=0;j<=16;j++){
			if(diff&(1<<j)){
				ans=ans*prod[j][a]%mod;
				a=lca[j][a];
			}
		}
	}
	if(a==b)return ans*popu[b]%mod;
	for(int i=16;i>=0;i--){
		if(lca[i][a]!=lca[i][b]){
			ans=ans*prod[i][a]%mod;
			ans=ans*prod[i][b]%mod;
			a=lca[i][a];
			b=lca[i][b];
		}
	}
	return ((ans*popu[lca[0][a]]%mod)*popu[a]%mod)*popu[b]%mod;
}
lli fix(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    n=readint();
    q=readint();
    for(int i=1;i<=n;i++){
		popu[i]=readint();
		inv[i]=quickpow(popu[i],mod-2);
    }
    int a,b;
    for(int i=1;i<n;i++){
    	a=readint();
    	b=readint();
		matrix[a].push_back(b);
		matrix[b].push_back(a);
    }
    decompfulltree(1);
    dfs(1,-1,0);
    makelca();
    lli val;
    //if(n>1000)assert(0);
    while(q--){
    	a=readint();
    	b=readint();
    	if(a==1){
			val=(lli)readint();
			int loc=b;
			int last=0;
			int rot=0;
			while(loc>0){
				lli toadd=val*(querylca(b,loc)*inv[loc]%mod)%mod;
				newstot[loc]=(newstot[loc]+toadd)%mod;
				overcnt[last]=(overcnt[last]+toadd)%mod;
				last=loc;
				loc=centparent[loc];
			}
    	}
    	else{
			lli ans=newstot[b];
			int loc=centparent[b];
			int last=b;
			int rot=0;
			while(loc>0){
				ans=(ans+(querylca(b,loc)*inv[b]%mod)*fix(newstot[loc]-overcnt[last])%mod)%mod;
				last=loc;
				loc=centparent[loc];
			}
			printf("%lli\n",ans);
    	}
    }
    return 0;
}

/*
3 2
1 2 4
1 2
1 3
1 2 3
2 3



5 2
1 2 4 8 16
1 2
1 3
2 4
2 5
1 2 100
2 3
 */