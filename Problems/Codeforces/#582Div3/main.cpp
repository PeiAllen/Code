#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    bool before[27][27]={};
    set<pii> bef;
    int pre[n+1]={};
	char let[26];
    for(int i=0;i<26;i++)before[i][i]=true;
    int in;
    for(int i=0;i<n;i++){
    	cin>>in;
    	bool cnt=false;
    	for(pii x:bef){
    		if(x.first==in)cnt=true;
    		if(before[in][x.first]){
    			pre[x.second]+=1;
    			pre[i+1]-=1;
    		}
    		before[x.first][in]=true;
    	}
    	if(!cnt)bef.insert({in,i});
    }
    bef.clear();
	for(int i=0;i<n;i++){
		cin>>in;
		bool cnt=false;
		for(pii x:bef){
			if(x.first==in)cnt=true;
			if(before[in][x.first]){
				pre[x.second]+=1;
				pre[i+1]-=1;
			}
			before[x.first][in]=true;
		}
		if(!cnt)bef.insert({in,i});
	}
	bef.clear();


    return 0;
}