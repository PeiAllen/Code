#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=2500;
int bit[MAXN+1];
int n,m;
vector<pii> rowranges[MAXN][MAXN];
vector<pii> colranges[MAXN][MAXN];
int preloc[MAXN];
int sufloc[MAXN];
pii deq[MAXN];
void update(int loc, int val){
	for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int sum(int loc){
	int ans=0;
	for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
	return ans;
}
long long count_rectangles(std::vector<std::vector<int>> a){
	n=a.size();
	m=a[0].size();
	for(int i=0;i<n;i++){
		int l=0,r=-1;
		for(int j=m-1;j>=0;j--){
			while(r>=l&&deq[r].second<=a[i][j])r--;
			if(r>=l)sufloc[j]=deq[r].first;
			else sufloc[j]=-1;
			deq[++r]={j,a[i][j]};
		}
		l=0,r=-1;
		for(int j=0;j<m;j++){
			while(r>=l&&deq[r].second<=a[i][j])r--;
			if(r>=l)preloc[j]=deq[r].first;
			else preloc[j]=-1;
			deq[++r]={j,a[i][j]};
			if(preloc[j]!=-1&&sufloc[j]!=-1){
				while(rowranges[i][preloc[j]+1].size()&&rowranges[i][preloc[j]+1].back().first==sufloc[j]-1)rowranges[i][preloc[j]+1].pop_back();
				rowranges[i][preloc[j]+1].emplace_back(sufloc[j]-1,1);
			}
		}
	}
	for(int i=0;i<m;i++){
		int l=0,r=-1;
		for(int j=n-1;j>=0;j--){
			while(r>=l&&deq[r].second<=a[j][i])r--;
			if(r>=l)sufloc[j]=deq[r].first;
			else sufloc[j]=-1;
			deq[++r]={j,a[j][i]};
		}
		l=0,r=-1;
		for(int j=0;j<n;j++){
			while(r>=l&&deq[r].second<=a[j][i])r--;
			if(r>=l)preloc[j]=deq[r].first;
			else preloc[j]=-1;
			deq[++r]={j,a[j][i]};
			if(preloc[j]!=-1&&sufloc[j]!=-1){
				while(colranges[preloc[j]+1][i].size()&&colranges[preloc[j]+1][i].back().first==sufloc[j]-1)colranges[preloc[j]+1][i].pop_back();
				colranges[preloc[j]+1][i].emplace_back(sufloc[j]-1,1);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=n-2;j>=0;j--){
			int l=0,r=0;
			while(l<rowranges[j][i].size()&&r<rowranges[j+1][i].size()){
				if(rowranges[j][i][l].first==rowranges[j+1][i][r].first){
					rowranges[j][i][l].second+=rowranges[j+1][i][r].second;
					l++;
				}
				else if(rowranges[j][i][l].first>rowranges[j+1][i][r].first){
					r++;
				}
				else l++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=m-2;j>=0;j--){
			int l=0,r=0;
			while(l<colranges[i][j].size()&&r<colranges[i][j+1].size()){
				if(colranges[i][j][l].first==colranges[i][j+1][r].first){
					colranges[i][j][l].second+=colranges[i][j+1][r].second;
					l++;
				}
				else if(colranges[i][j][l].first>colranges[i][j+1][r].first){
					r++;
				}
				else l++;
			}
		}
	}
	int cnt=0;
	auto f = [&] (const pii& a, const pii& b) {
		return a.second<b.second;
	};
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			sort(colranges[i][j].begin(),colranges[i][j].end(),f);
			int r=colranges[i][j].size();
			for(int k=(int)rowranges[i][j].size()-1;k>=0;k--){
				while(r>0&&colranges[i][j][r-1].second+j-1>=rowranges[i][j][k].first){
					r-=1;
					update(colranges[i][j][r].first+1,1);
				}
				cnt+=sum(rowranges[i][j][k].second+i);
			}
			for(int k=r;k<colranges[i][j].size();k++)update(colranges[i][j][k].first+1,-1);
		}
	return cnt;
}