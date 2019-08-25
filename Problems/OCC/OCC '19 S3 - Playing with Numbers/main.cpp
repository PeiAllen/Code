#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
set<int> begins;
multiset<int,greater<int>> sizes;
void insertbegin(int loc){
	if(begins.count(loc))return;
	int before=*prev(begins.lower_bound(loc),1);
	int after=*begins.lower_bound(loc);
	sizes.erase(sizes.find(after-before));
	sizes.insert(loc-before);
	sizes.insert(after-loc);
	begins.insert(loc);
}
void erasebegin(int loc){
	if(!begins.count(loc))return;
	int before=*prev(begins.lower_bound(loc),1);
	int after=*begins.upper_bound(loc);
	sizes.erase(sizes.find(after-loc));
	sizes.erase(sizes.find(loc-before));
	sizes.insert(after-before);
	begins.erase(loc);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	int arr[n+1];
	arr[0]=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<arr[i-1]){
			if(begins.size()){
				sizes.insert(i-(*prev(begins.end(),1)));
			}
			begins.insert(i);
		}
	}
	sizes.insert(n+1-(*prev(begins.end(),1)));
	begins.insert(n+1);
	printf("%d\n",*sizes.begin());
	while(q--){
		int a,b;
		cin>>a>>b;
		arr[a]=b;
		if(arr[a]<arr[a-1])insertbegin(a);
		else erasebegin(a);
		if(a!=n) {
			if (arr[a + 1] < arr[a])insertbegin(a + 1);
			else erasebegin(a + 1);
		}
		printf("%d\n",*sizes.begin());
	}
	return 0;
}