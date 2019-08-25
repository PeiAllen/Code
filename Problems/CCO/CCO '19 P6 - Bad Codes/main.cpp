#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<string> arr;
vector<pii> matrix[2501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string in;
    int pre[n];
    pre[0]=0;
    for(int i=0;i<n;i++){
    	cin>>in;
    	arr.push_back(in);
    	if(i)pre[i]=pre[i-1]+arr[i-1].size();
    }
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[i].size();j++){
			for(int l=0;l<n;l++){
				if(l!=i){
					int loc=0;
					while(loc<arr[l].size()&&j+loc<arr[i].size()&&arr[l][loc]==arr[i][j+loc]){
						loc++;
					}
					if(j+loc==arr[i].size()){
						if(loc==arr[l].size()){
							matrix[j+pre[i]].push_back({-1,loc});
						}
						else{
							matrix[j+pre[i]].push_back({pre[l]+loc,loc});
						}
					}
					else if(loc==arr[l].size()){
						matrix[j+pre[i]].push_back({pre[i]+j+loc,loc});
					}
				}
			}
		}
	}
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		priority_queue<pii> q;
		int dist[pre[n-1]+arr[n-1].size()];
		q.push({pre[i],0});
		dist[pre[i]]=0;
		while(!q.empty()){
			pii cur=q.top();
			q.pop();
			if(cur.first=-1){
				ans=min(ans,cur.second);
				break;
			}
			if(cur.second<=dist[cur.first]){
				for(pii x:matrix[cur.first]){
					pii te={x.first,cur.second+x.second};
					if(dist[te.first]>te.second){
						dist[te.first]=te.second;
						q.push(te);
					}
				}
			}
		}
	}
	if(ans==INT_MAX)printf("-1\n");
	else printf("%d\n",ans);
    return 0;
}