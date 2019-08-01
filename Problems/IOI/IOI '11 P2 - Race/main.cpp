/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Allen
 *
 * Created on May 3, 2019, 8:59 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa {
	lli dest;
	lli dist;

	pa(lli a = 0, lli b = (lli)0) : dest(a), dist(b) {
	}
};
lli subtreesize[200001];
vector<pa> matrix[200001];
vector<lli> matrix2[200001];
bool cent[200001];
lli k;



lli iscentroid(lli loc, lli siz, lli parent) {
	for (pa i : matrix[loc]){
		if(!cent[i.dest]&&i.dest!=parent){
			if(subtreesize[i.dest]>siz/2){
				return i.dest;
			}
		}
	}
	return -1;
}

lli dfs(lli loc, lli parent) {
	lli sum = 0;
	for (pa x : matrix[loc]) {
		if (x.dest != parent&&!cent[x.dest]) {
			sum += dfs(x.dest, loc);
		}
	}
	subtreesize[loc] = sum;
	return sum+1;
}

lli decompsubtree(lli loc, lli siz, lli parent) {
	lli next = iscentroid(loc,siz,parent);
	if (next == -1) {
		return loc;
	}
	return decompsubtree(next,siz,loc);
}

lli decompfulltree(lli loc) {
	lli next = decompsubtree(loc,dfs(loc,-1),-1);
	cent[next]=true;
	for (pa i : matrix[next]) {
		if (!cent[i.dest]) {
			lli te = decompfulltree(i.dest);
			matrix2[te].push_back(next);
			matrix2[next].push_back(te);
		}
	}
	return next;
}

//void prllidfs(lli loc, lli parent){
//	prllif("%d ",loc);
//	for(lli i:matrix2[loc]){
//		if(i!=parent){
//			prllidfs(i,loc);
//		}
//	}
//}
lli minans=LLONG_MAX;
map<lli,lli> dists;
map<lli,lli> distste;
void dfscount(lli loc,lli parent,lli size, lli depth){
	if(size>k){
		return;
	}
	if(distste.count(size)){
		distste[size]=min(distste[size],depth);
	}
	else{
		distste[size]=depth;
	}
	if(size>=k){
		return;
	}
	for(pa i:matrix[loc]){
		if(!cent[i.dest]&&i.dest!=parent){
			dfscount(i.dest,loc,size+i.dist,depth+1);
		}
	}
}

void dfscentroid(lli loc){
	cent[loc]=true;
	dists.clear();
	dists[0]=0;
	for(pa i:matrix[loc]){
		if(!cent[i.dest]){
			dfscount(i.dest,loc,i.dist,1);
			for(auto x:distste){
				if(x.first<=k&&dists.count(k-x.first)){
					minans=min(minans,x.second+dists[k-x.first]);
				}
			}
			for(auto x:distste){
				if(dists.count(x.first)){
					dists[x.first]=min(dists[x.first],x.second);
				}
				else{
					dists[x.first]=x.second;
				}
			}
			distste.clear();
		}
	}
	for(lli i:matrix2[loc]){
		if(!cent[i]) {
			dfscentroid(i);
		}
	}
}

int best_path(int N, int K, int H[][2], int L[]){
	for (lli i = 0; i < N - 1; i++) {
		matrix[H[i][0]].push_back(pa((lli)H[i][1], (lli)L[i]));
		matrix[H[i][1]].push_back(pa((lli)H[i][0], (lli)L[i]));
	}
	k = (lli)K;
	lli loc=decompfulltree(0);
	memset(cent,false,sizeof(cent));
	dfscentroid(loc);
	return (minans==LLONG_MAX?-1:(int)minans);
}