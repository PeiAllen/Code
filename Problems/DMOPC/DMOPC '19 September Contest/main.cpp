#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
int am[26];
bool used[1000];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	sc(n,k);
	string arr[n];
	for(int i=0;i<n;i++){
		sc(arr[i]);
		for(char x:arr[i])am[x-'a']+=1;
	}
	if(k==1){
		for(int i=0;i<n;i++)pr(arr[i]);
		return 0;
	}
	if((n-k+1)%2==0&&n<k)pr("-1");
	else for(int i=0;i<n+k-1;i++)pr("a");
//	for(int ke=0;ke<n;ke++){
//		for(int i=0;i<n;i++)used[i]=false;
//		used[ke]=true;
//		bool work=true;
//		string fin=arr[ke];
//		int am2[26];
//		for(int i=0;i<26;i++)am2[i]=am[i];
//		am2[arr[ke][0]-'a']-=1;
//		for(int j=1;j<n;j++){
//			bool done=false;
//			for(int i=0;i<n;i++){
//				if(!used[i]&&arr[i][0]==fin.back()&&am2[arr[i][0]-'a']%2==1){
//					done=true;
//					fin+=arr[i][1];
//					am2[arr[i][0]-'a']-=1;
//					used[i]=true;
//					break;
//				}
//			}
//			if(!done){
//				work=false;
//				break;
//			}
//		}
//		if(!work)continue;
//		pr(fin);
//		return 0;
//	}
//	pr("-1");
	return 0;
}