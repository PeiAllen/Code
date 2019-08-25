#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    priority_queue<pair<lli,pair<int,int>>> q;
    vector<lli> arr[n];
    int a;
	for(int i=0;i<n;i++){
		cin>>a;
		int in;
		for(int j=0;j<a;j++){
			cin>>in;
			arr[i].push_back(in);
		}
		sort(arr[i].begin(),arr[i].end(),greater<int>());
	}
	for(int i=0;i<arr[0].size();i++){
		q.push({arr[1][0]+arr[0][i],{i,0}});
	}
	for(int i=0;i<k;i++){
		auto cur=q.top();
		q.pop();
		printf("%lli ",cur.first);
		if(cur.second.second+1<arr[1].size()){
			q.push({arr[1][cur.second.second+1]+arr[0][cur.second.first],{cur.second.first,cur.second.second+1}});
		}
	}
    return 0;
}