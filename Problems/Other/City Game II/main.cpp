#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
pii deqmi[1001];
int lmi,rmi;
pii deqma[1001];
int lma,rma;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int h,w,n;
	cin>>h>>w>>n;
	int arr[h][w];
	int mi[h][w];
	int ma[h][w];
	for(int i=0;i<h;i++){
		lmi=0,rmi=-1,lma=0,rma=-1;
		for(int j=0;j<w;j++){
			cin>>arr[i][j];
			while(lmi<=rmi&&deqmi[rmi].first>=arr[i][j])rmi--;
			while(lmi<=rmi&&deqmi[lmi].second<=j-n)lmi++;
			deqmi[++rmi]={arr[i][j],j};
			while(lma<=rma&&deqma[rma].first<=arr[i][j])rma--;
			while(lma<=rma&&deqma[lma].second<=j-n)lma++;
			deqma[++rma]={arr[i][j],j};
			mi[i][j]=deqmi[lmi].first;
			ma[i][j]=deqma[lma].first;
		}
	}
	int ans=INT_MAX;
	for(int i=n-1;i<w;i++){
		lmi=0,rmi=-1,lma=0,rma=-1;
		for(int j=0;j<h;j++){
			while(lmi<=rmi&&deqmi[rmi].first>=mi[j][i])rmi--;
			while(lmi<=rmi&&deqmi[lmi].second<=j-n)lmi++;
			deqmi[++rmi]={mi[j][i],j};
			while(lma<=rma&&deqma[rma].first<=ma[j][i])rma--;
			while(lma<=rma&&deqma[lma].second<=j-n)lma++;
			deqma[++rma]={ma[j][i],j};
			if(j>=n-1){
				ans=min(ans,deqma[lma].first-deqmi[lmi].first);
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}