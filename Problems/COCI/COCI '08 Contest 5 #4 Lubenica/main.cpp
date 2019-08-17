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
    for(int i=0;i<n;i++)cin>>arr[i];
    set<int> se;
    vector<lli> am;
    int cur=0;
	lli thrown=0;
    for(int i=0;i<n;i++){
    	if(arr[0][i]=='1'){
    		cur+=(1<<i);
    		thrown+=1;
    	}
    }
    while(!se.count(cur)){
    	se.insert(cur);
    	am.push_back(thrown);
    	int ch[n]={};
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
    	}
    }
	se.insert(cur);
	am.push_back(thrown);
    printf("%lli\n",h/am.size()*am.back()+(h%am.size()?am[(h%am.size())-1]:0));
    return 0;
}