#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"

#include <bits/stdc++.h>
#include "factories.h"
using namespace std;
struct pa{
	int dest;
	long long dist;
	pa(int a=0, long long b=0):dest(a),dist(b){}
};
struct tri{
	int dest,parent;
	long long dist;
	tri(int a=0, long long b=0, int c=0):dest(a),dist(b),parent(c){}
};
vector<pa> matrix[500000];
int matrix2[500000];
long long ancdist[500000][19];
int ancri[500000];
bool cent[500000];
int subtreesize[500000];
long long dist[500000];
int rev[500000];
int revri;
long long mi2;
int cur2;
int loc2;
tri st[500000];
int sts=500000;
inline void dfssize(int loc, int parent){
	subtreesize[loc]=1;
	for(pa x:matrix[loc]){
		if(parent^x.dest&&!cent[x.dest]){
			dfssize(x.dest,loc);
			subtreesize[loc]+=subtreesize[x.dest];
		}
	}
}
inline int decompsubtree(int loc, int parent, int size){
	for(pa x:matrix[loc]){
		if(x.dest^parent&&!cent[x.dest]&&subtreesize[x.dest]>size){
			return decompsubtree(x.dest,loc,size);
		}
	}
	return loc;
}
inline int decompfulltree(int loc){
	dfssize(loc,-1);
	if(subtreesize[loc]==1){
		cent[loc]=true;
		ancri[loc]++;
		return loc;
	}
	int next=decompsubtree(loc,-1,subtreesize[loc]/2);
	cent[next]=true;
	st[--sts]=tri(next,0,-1);
	while(sts<=499999){
		tri cur=st[sts++];
		ancdist[cur.dest][ancri[cur.dest]++]=cur.dist;
		for(pa x:matrix[cur.dest]){
			if(x.dest^cur.parent&&!cent[x.dest]){
				st[--sts]=tri(x.dest,cur.dist+x.dist,cur.dest);
			}
		}
	}
	for(pa x:matrix[next]){
		if(!cent[x.dest]){
			matrix2[decompfulltree(x.dest)]=next;
		}
	}
	return next;
}
void Init(int N, int A[], int B[], int D[]){
	for(int i=0;i<N-1;i++){
		matrix[A[i]].push_back(pa(B[i],(long long)D[i]));
		matrix[B[i]].push_back(pa(A[i],(long long)D[i]));
	}
	decompfulltree(1);
	memset(dist,-1,sizeof(dist));
}
long long Query(int S, int X[], int T, int Y[]){
	mi2=LLONG_MAX;
	if(S<T){

		for(int i=0;i<S;i++){
			cur2=X[i];
			loc2=X[i];
			for(int ind=ancri[loc2]-1;ind>=0;ind--) {
				if (dist[loc2]^-1) {
					dist[loc2] = min(dist[loc2], ancdist[cur2][ind]);
				} else {
					rev[revri++]=loc2;
					dist[loc2] = ancdist[cur2][ind];
				}
				loc2 = matrix2[loc2];
			}
		}
		for(int i=0;i<T;i++){
			cur2=Y[i];
			loc2=Y[i];
			for(int ind=ancri[loc2]-1;ind>=0;ind--) {
				if(dist[loc2]^-1) {
					mi2 = min(mi2, ancdist[cur2][ind]+ dist[loc2]);
				}
				loc2 = matrix2[loc2];
			}
		}
	}
	else{
		for(int i=0;i<T;i++){
			cur2=Y[i];
			loc2=Y[i];
			for(int ind=ancri[loc2]-1;ind>=0;ind--) {
				if (dist[loc2]^-1) {
					dist[loc2] = min(dist[loc2], ancdist[cur2][ind]);
				} else {
					rev[revri++]=loc2;
					dist[loc2] = ancdist[cur2][ind];
				}
				loc2 = matrix2[loc2];
			}
		}
		for(int i=0;i<S;i++){
			cur2=X[i];
			loc2=X[i];
			for(int ind=ancri[loc2]-1;ind>=0;ind--) {
				if(dist[loc2]^-1) {
					mi2 = min(mi2, ancdist[cur2][ind]+ dist[loc2]);
				}
				loc2 = matrix2[loc2];
			}
		}
	}
	for(;revri>=0;revri--){
		dist[rev[revri]]=-1;
	}
	revri++;
	return mi2;
}