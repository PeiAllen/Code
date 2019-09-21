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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
long long count_rectangles(std::vector<std::vector<int>> a){
	int n=a.size();
	int m=a[0].size();
	vector<int> rowranges[n][m];
	vector<int> colranges[n][m];
	rep(i,0,n){
		int preloc[m];
		int sufloc[m];
		pii deq[m];
		int l=0,r=-1;
		rep(j,0,n){
			while(r>=l&&deq[r].second<=a[i][j])r--;
			if(r>=l)preloc[j]=deq[r].first;
			else preloc[j]=-1;
			deq[++r]={j,a[i][j]};
		}
		l=0,r=-1;
		rep(j,n,0){
			while(r>=l&&deq[r].second<=a[i][j])r--;
			if(r>=l)sufloc[j]=deq[r].first;
			else sufloc[j]=-1;
			deq[++r]={j,a[i][j]};
		}
		rep(j,0,n){
			if(preloc[j]!=-1&&sufloc[j]!=-1){
				rowranges[i][preloc[j]+1].push_back(sufloc[j]-1);
			}
		}
	}
	rep(i,0,m){
		int preloc[n];
		int sufloc[n];
		pii deq[n];
		int l=0,r=-1;
		rep(j,0,m){
			while(r>=l&&deq[r].second<=a[j][i])r--;
			if(r>=l)preloc[j]=deq[r].first;
			else preloc[j]=-1;
			deq[++r]={j,a[j][i]};
		}
		l=0,r=-1;
		rep(j,m,0){
			while(r>=l&&deq[r].second<=a[j][i])r--;
			if(r>=l)sufloc[j]=deq[r].first;
			else sufloc[j]=-1;
			deq[++r]={j,a[j][i]};
		}
		rep(j,0,m){
			if(preloc[j]!=-1&&sufloc[j]!=-1){
				colranges[preloc[j]+1][i].push_back(sufloc[j]-1);
			}
		}
	}
	rep()
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}