#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<vector<int>> loops;
int arr[101];
bool done[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    bool issorted=true;
    int last=0;
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	if(arr[i]>last)last=arr[i];
    	else issorted=false;
    }
    for(int i=1;i<=n;i++){
    	if(!done[i]){
    		loops.push_back({i});
    		int cur=arr[i];
    		while(cur!=i){
    			done[cur]=true;
    			loops[loops.size()-1].push_back(cur);
    			cur=arr[cur];
    		}
    	}
    }
    if(issorted){
    	printf("0\n");
    	return 0;
    }
    int cyclecnt=0;
    vector<int> toch;
    for(auto x:loops){
    	for(auto y:x){
    		toch.push_back(y);
    	}
    	if(x.size()>1)cyclecnt+=1;
    }
    if(cyclecnt==1){
    	printf("1\n");
	    for(auto x:loops){
	    	if(x.size()>1) {
	    		printf("%d ",x.size());
			    for (auto y:x) {
				    printf("%d ",y);
			    }
		    }
	    }
	    return 0;
    }
    printf("2\n");
    printf("%d ",toch.size());
    int arr2[n+1];
    for(int i=0;i<toch.size();i++){
		arr2[toch[(i+1)%(int)toch.size()]]=arr[toch[i]];
		printf("%d ",toch[i]);
    }
    printf("\n");
	int og=loops[0][0];
	vector<int> top;
	top.push_back(og);
	int cur=arr2[og];
	while(cur!=og){
		top.push_back(cur);
		cur=arr2[cur];
	}
	printf("%d ",top.size());
	for(int x:top)printf("%d ",x);
    return 0;
}