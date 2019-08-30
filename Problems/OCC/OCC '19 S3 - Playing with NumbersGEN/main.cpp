#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
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
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	registerGen(argc, argv, 1);
	rnd.setSeed(time(0));
	for(int cases=15;cases<20;cases++) {
		begins.clear();
		sizes.clear();
		ofstream o("subtask2case"+to_string(cases)+".in");
	    int n = 400000, q = 400000;
	    o<<n<<" "<<q<<"\n";
		int arr[n+1];
		arr[0]=INT_MAX;
		for(int i=1;i<n;i++){
			arr[i]=rnd.next((int)-1e9,(int)1e9);
			o<<arr[i]<<" ";
			if(arr[i]<arr[i-1]){
				if(begins.size()){
					sizes.insert(i-(*prev(begins.end(),1)));
				}
				begins.insert(i);
			}
		}
		arr[n]=rnd.next((int)-1e9,(int)1e9);
		o<<arr[n]<<"\n";
		if(arr[n]<arr[n-1]){
			if(begins.size()){
				sizes.insert(n-(*prev(begins.end(),1)));
			}
			begins.insert(n);
		}
		sizes.insert(n+1-(*prev(begins.end(),1)));
		begins.insert(n+1);
		ofstream o2("subtask2case"+to_string(cases)+".out");
		o2<<*sizes.begin()<<"\n";
		while(q--){
			int a=rnd.next(1,n),b=rnd.next((int)-1e9,(int)1e9);
			o<<a<<" "<<b<<"\n";
			arr[a]=b;
			if(arr[a]<arr[a-1])insertbegin(a);
			else erasebegin(a);
			if(a!=n) {
				if (arr[a + 1] < arr[a])insertbegin(a + 1);
				else erasebegin(a + 1);
			}
			o2<<*sizes.begin()<<"\n";
		}
		o.close();
		o2.close();
    }
    return 0;
}