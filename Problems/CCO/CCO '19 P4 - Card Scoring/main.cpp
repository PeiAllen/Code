#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000001;
double dp[MAXN];
int cardnum[MAXN];
double k;
int n;
vector<int> best[MAXN];
int arr[MAXN];
vector<int> cardspots[MAXN];
int cards[MAXN];
double precalc[MAXN];
double calc(int j, int i){
	return precalc[cardnum[i]-cardnum[j]+1]+dp[j-1];
}
double overcomepoint(int a, int b, int card){
	int l=(lower_bound(cardspots[card].begin(),cardspots[card].end(),b)-cardspots[card].begin())+1;
	int r=cardspots[card].size();
	while(l!=r){
		int mid=(l+r)/2;
		if(calc(a,cardspots[card][mid-1])>=calc(b,cardspots[card][mid-1])){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(r==cardspots[card].size()&&calc(a,cardspots[card].back())<calc(b,cardspots[card].back())){
		return n+1;
	}
	else{
		return cardspots[card][l-1];
	}
}
void beststart(int i, int card){
	while(best[card].size()>=2&&overcomepoint(best[card].back(),i,card)>=overcomepoint(best[card][best[card].size()-2],best[card].back(),card)){
		best[card].pop_back();
	}
	best[card].push_back(i);
	while(best[card].size()>=2&&overcomepoint(best[card][best[card].size()-2],best[card].back(),card)<=i){
		best[card].pop_back();
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>k>>n;
    k/=2;
    for(int i=1;i<=n;i++){
    	precalc[i]=pow((double)i,k);
    }
    for(int i=1;i<=n;i++){
		cin>>arr[i];
		cardnum[i]=++cards[arr[i]];
		cardspots[arr[i]].push_back(i);
    }
	for(int i=1;i<=n;i++){
		beststart(i,arr[i]);
		dp[i]=calc(best[arr[i]].back(),i);
	}
	printf("%f",dp[n]);
    return 0;
}

/*
pow((cardnum[i]-cardnum[a]),k)+dp[a]>pow((cardnum[i]-cardnum[b]),k)+dp[b] && a<b then a will always be better



 */