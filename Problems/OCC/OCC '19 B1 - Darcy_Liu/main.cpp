#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	string a;
	cin>>a;
	if(a.size()<9){
		printf("other user\n");
		return 0;
	}
	string fi="darcy";
	string se="liu";
	for(int i=0;i<5;i++){
		if(a[i]>='A'&&a[i]<='Z')a[i]=tolower(a[i]);
		if(a[i]!=fi[i]){
			printf("other user\n");
			return 0;
		}
	}
	for(int i=a.size()-3;i<a.size();i++){
		if(a[i]>='A'&&a[i]<='Z')a[i]=tolower(a[i]);
		if(a[i]!=se[i-(int)a.size()+3]){
			printf("other user\n");
			return 0;
		}
	}
	for(int i=5;i<a.size()-3;i++){
		if(a[i]!='_'){
			printf("other user\n");
			return 0;
		}
	}
	if(a.size()-8==1)printf("real\n");
	else printf("fake\n");
    return 0;
}