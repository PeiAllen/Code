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
    pair<lli,vector<lli>> arr[n];
    for(int i=0;i<n;i++){
		int a;
		cin>>a;
		lli in;
		for(int j=0;j<a;j++){
			cin>>in;
			arr[i].second.push_back(in);
		}
		sort(arr[i].second.begin(),arr[i].second.end(),greater<int>());
		arr[i].first=(a>1?arr[i].second[0]-arr[i].second[1]:LLONG_MAX);
    }
    priority_queue<pair<lli,pair<int,int>>> q;
    sort(arr,arr+n);
    lli sum=0;
    for(int i=0;i<n;i++){
		sum+=arr[i].second[0];
    }
    q.push({sum,{0,0}});
    for(int i=0;i<k;i++){
		auto te=q.top();
		q.pop();
		printf("%lli ",te.first);
		if(te.second.second+1<arr[te.second.first].second.size()){
			q.push({te.first-arr[te.second.first].second[te.second.second]+arr[te.second.first].second[te.second.second+1],{te.second.first,te.second.second+1}});
		}
		if(te.second.first+1<n&&arr[te.second.first+1].second.size()>1){
			q.push({te.first-arr[te.second.first+1].second[0]+arr[te.second.first+1].second[1],{te.second.first+1,1}});
		}
    }
    return 0;
}