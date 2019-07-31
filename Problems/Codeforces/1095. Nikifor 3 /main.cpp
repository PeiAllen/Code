#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
    	string a;
    	cin>>a;
    	int cnt[9]={ };
    	for(int i=0;i<a.size();i++){
    		cnt[a[i]-'0']+=1;
    	}
    	cnt[1]-=1;
    	cnt[2]-=1;
    	cnt[3]-=1;
    	cnt[4]-=1;
    	int mo=0;
    	string ans="";
    	for(int i=9;i>=0;i--){
    		for(int j=0;j<cnt[i];j++){
    			mo=mo*10+i;
    			mo%=7;
    			ans+=to_string(i);
    		}
    	}
    	mo=7-mo;
    	mo%=7;
		string te="1234";
		do{
			if(stoi(te)%7==mo){
				cout<<ans<<te<<"\n";
				break;
			}
		}while(next_permutation(te.begin(),te.end()));
    }
    return 0;
}

//1234->1,8
//1243->2

