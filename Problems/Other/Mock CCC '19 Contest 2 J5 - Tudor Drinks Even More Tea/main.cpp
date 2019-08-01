#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d<b){
		swap(b,d);
		swap(a,c);
	}
	vector<int> use;
	bool nprime[b+1]={};
	for(int i=2;i<=b;i++){
		if(!nprime[i]){
			bool in=false;
			for(int j=i;j<=b;j+=i){
				if(j>=a&&j<=b)in=true;
				nprime[j]=true;
			}
			if(in)use.push_back(i);
		}
	}
	bool
	for(int x:use){

	}
    return 0;
}