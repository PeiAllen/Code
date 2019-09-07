#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
long long bit[200001];
int n;
void update(int loc, long long am){
	for(;loc<=n;loc+=loc&-loc)bit[loc]+=am;
}
long long query(int loc){
	int ans=0;
	for(;loc>0;loc-=loc&-loc){
		ans+=bit[loc];
	}
	return ans;
}
long long count_swaps(std::vector<int> S){
	n=S.size();
	queue<int> locs[S.size()+1][2];
	long long swaps=0;
	for(int i=0;i<n;i++){
		int wh=(S[i]>0);
		if(locs[abs(S[i])][!wh].size()){
			int oth=locs[abs(S[i])][!wh].front();
			locs[abs(S[i])][!wh].pop();
			int torem=query(i+1)-query(oth+1);
			swaps+=i-oth-1+(wh==0)-torem;
			update(oth+1,-1);
			update(i+1,1);
		}
		else locs[abs(S[i])][wh].push(i);
	}
	return swaps;
}

//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    vector<int> a={-2, 2, 2, -2, -2, 2};
//	printf("%lli\n",count_swaps(a));
//    return 0;
//}