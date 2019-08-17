#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,h;
	cin>>n>>h;
	string arr[n];
	int ch[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	map<int,int> se;
	vector<lli> am;
	am.push_back(0);
	int cur=0;
	lli thrown=0;
	for(int i=0;i<n;i++){
		ch[i]=0;
		if(arr[0][i]=='1'){
			cur+=(1<<i);
			thrown+=1;
		}
	}
	while(!se.count(cur)){
		se[cur]=am.size();
		am.push_back(thrown);
		for(int i=0;i<n;i++){
			bool odd=(cur&(1<<i));
			for(int j=0;j<n;j++){
				if(arr[i][j]=='1'){
					ch[j]+=(odd?1:2);
				}
			}
		}
		cur=0;
		for(int i=0;i<n;i++){
			thrown+=ch[i];
			if(ch[i]%2){
				cur+=(1<<i);
			}
			ch[i]=0;
		}
	}
	int othloc=se[cur]+1;
	am.push_back(thrown);
	if(h<othloc)printf("%lli\n",am[h]);
	else{
		int rotsiz=am.size()-othloc;
		lli ans=am[othloc-1];
		h-=othloc-1;
		printf("%lli\n",ans+h/rotsiz*(am.back()-am[othloc-1])+(h%rotsiz?am[h%rotsiz+othloc-1]-am[othloc-1]:0));
	}
	return 0;
}