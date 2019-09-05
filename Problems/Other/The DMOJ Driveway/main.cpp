#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t,m;
    cin>>t>>m;
    string deq[t];
    int l=0;
    int r=-1;
    string a,b;
    for(int i=0;i<t;i++){
    	cin>>a>>b;
    	if(b=="in")deq[++r]=a;
    	else{
    		if(deq[r]==a)r--;
    		else if(deq[l]==a&&m){
    			l++;
    			m--;
    		}
    	}
    }
    for(int i=l;i<=r;i++){
    	cout<<deq[i]<<"\n";
    }
    return 0;
}