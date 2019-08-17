#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
set<int> ans;
void findfactorsets(int curval, int curfactcheckst, int value){
	ans.insert(value+curval-1);
	int high=sqrt(curval);
	for(int i=curfactcheckst;i<=high;i++){
		if(curval%i==0){
			findfactorsets(curval/i,i,value+i-1);
		}
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    findfactorsets(n,2,0);
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
    return 0;
}