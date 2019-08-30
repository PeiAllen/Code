#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

struct comp{
	bool operator()(const vector<lli>& lhs, const vector<lli>& rhs)const {
		for(int i=1;i<min(lhs.size(),rhs.size());i++){
			lli ldiff=lhs[i-1]-lhs[i];
			lli rdiff=rhs[i-1]-rhs[i];
			if(ldiff!=rdiff)return ldiff<rdiff;
		}
		return lhs.size()>rhs.size();
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	vector<lli> arr[n];
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		lli in;
		for(int j=0;j<a;j++){
			cin>>in;
			arr[i].push_back(in);
		}
		sort(arr[i].begin(),arr[i].end(),greater<lli>());
	}
	priority_queue<pair<lli,pair<int,int>>> q;
	sort(arr,arr+n,comp());
	lli sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i][0];
	}
	q.push({sum,{0,0}});
	while(k--){
		auto te=q.top();
		q.pop();
		printf("%lli ",te.first);
		if(te.second.second+1<arr[te.second.first].size()){
			q.push({te.first-arr[te.second.first][te.second.second]+arr[te.second.first][te.second.second+1],{te.second.first,te.second.second+1}});
		}
		if(te.second.first+1<n&&arr[te.second.first+1].size()>1){
			q.push({te.first-arr[te.second.first+1][0]+arr[te.second.first+1][1],{te.second.first+1,1}});
			if(te.second.second==1&&te.second.first>0){
				q.push({te.first-arr[te.second.first+1][0]+arr[te.second.first+1][1]-arr[te.second.first][1]+arr[te.second.first][0],{te.second.first+1,1}});
			}
		}
	}
	return 0;
}