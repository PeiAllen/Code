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
const int MAXN=1001;
string arr[MAXN];
int righth[MAXN][2*MAXN];
int downlength[MAXN][2*MAXN];
int nexthashr[MAXN][2*MAXN];
int downh[MAXN][2*MAXN];
int nexthashd[MAXN][2*MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	rep(i,0,n)sc(arr[i]);
	rep(i,n,0){
		rep(j,2*n,0){
			if(arr[i][j]=='#'){
				righth[i][j]=1+righth[i][j+1];
				nexthashr[i][j]=j;
			}
			else nexthashr[i][j]=nexthashr[i][j+1];
		}
	}
	rep(i,n,0){
		rep(j,0,2*n){
			if(arr[i][j]=='#'){
				downh[i][j]=1+downh[i+1][j];
				nexthashd[i][j]=i;
			}
			else nexthashd[i][j]=nexthashd[i+1][j];
		}
	}
	rep(i,n,0){
		rep(j,1,2*n){
			if(arr[i][j-1]=='#'){
				downlength[i][j]=0;
			}
			else downlength[i][j]=1+(righth[i+1][j]==righth[i][j]?downlength[i+1][j]:0);
		}
	}
	int cnt=0;
	rep(i,1,n-1){
		rep(j,1,2*n-1){
			if(arr[i][j]=='#'&&arr[i-1][j]=='.'&&arr[i][j-1]=='.'&&arr[i-1][j-1]=='.'){
				int cur=righth[i][j];
				if(cur>=5&&(cur-3)%2==0){
					int m=(cur-3)/2;
					int downam=1+(int)ceil((double)2*m/(double)3);
					if(downlength[i][j]!=downam)continue;
					if(i+downam>=n||nexthashr[i+downam][j-1]<j+cur)continue;
					int mid=cur/2+j;
					if(nexthashr[i-1][j-1]!=mid)continue;
					if(mid+1>=2*n||nexthashr[i-1][mid+1]<j+cur)continue;
					int up=i-2-m/5;
					if(up<0||nexthashd[up][mid-1]!=i)continue;
					if(nexthashd[up][mid+1]!=i)continue;
					if(arr[up][mid]!='.')continue;
					if(downh[up+1][mid]!=downam+m/5+1)continue;
					cnt++;
				}
			}
		}
	}
	prl(cnt);
    return 0;
}