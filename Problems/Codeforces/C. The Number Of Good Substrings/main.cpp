#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	string a;
    	cin>>a;
    	int leadcnt=0;
    	int back=log2((int)a.size());
    	int cnt=0;
    	for(int i=0;i<a.size();i++){
    		int cur=0;
    		for(int j=0;j<min(back,i+1);j++){
    			cur=(1<<j)*(a[i-j]=='1');
    			if(j+1==cur)cnt+=1;
    		}
    		if(cur>min(back,i+1)&&cur<=min(back,i+1)+leadcnt)cnt+=1;
    		if(i>=back-1&&a[i-back+1]=='0')leadcnt++;
    		else leadcnt=0;
    	}
    	printf("%d\n",cnt);
    }
    return 0;
}