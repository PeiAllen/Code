#include<bits/stdc++.h>

using namespace std;
struct pa{
	int a,b,sor;
	pa(int x=0, int y=0, int z=0):a(x),b(y),sor(z){}
	bool operator<(const pa& rhs){
		return sor<rhs.sor;
	}
};
pa arr[301];
int n;
bool poss(){
	for(int i=0;i<n;i++){

	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int tests=1;tests<=t;tests++){
		cin>>n;
		int a,b;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			arr[i]=pa(a,b,i);
		}
		int amount=0;
		amount+=poss();
		while(next_permutation(arr,arr+n)){
			amount+=poss();
		}
		printf("Case #1: %d\n",amount);
	}
}