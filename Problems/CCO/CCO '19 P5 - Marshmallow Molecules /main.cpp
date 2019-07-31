#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    set<int> marsh[n+1];
    int a,b;
    for(int i=0;i<m;i++){
		cin>>a>>b;
		marsh[a].insert(b);
    }
    lli ans=0;
	for(int i=1;i<=n;i++){
		ans+=marsh[i].size();
		if(marsh[i].size()) {
			int next = *marsh[i].upper_bound(i);
			if(marsh[next].size()>marsh[i].size()){
				marsh[next].insert(marsh[i].begin(),marsh[i].end());
			}
			else{
				marsh[i].insert(marsh[next].begin(),marsh[next].end());
				marsh[i].swap(marsh[next]);
			}
			marsh[next].erase(next);
		}
	}
	printf("%lli\n",ans);
    return 0;
}