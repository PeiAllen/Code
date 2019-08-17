#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
lli mod=998244353;
int slow(lli n, lli x, lli y){
    multiset<lli> nums;
    vector<lli> store;
    map<lli,lli> ma;
	store.push_back(x);
	store.push_back(y);
	lli prod=x*y%mod;
	nums.insert(x*y);
	while(n--){
		lli cur=*nums.begin();
		nums.erase(nums.begin());
		prod=prod*cur%mod;
		for(lli x:store){
			nums.insert(x*cur);
		}
		ma[cur]+=1;
		store.push_back(cur);
	}
	for(auto a:ma){
		printf("%lli %lli\n",a.first,a.second);
	}
	printf("%lli\n",prod);
    return 0;
}