#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    while(a!="halt"){
    	int last=-1;
    	int time=0;
    	for(int i=0;i<a.size();i++){
    		int te=a[i]-'a';
    		if(te>=18){
    			te-=1;
    			if(te==17)time+=1;
    		}
    		if(te==24){
    			te-=1;
    			time+=1;
    		}
    		if(te/3==last)time+=2;
    		time+=te%3+1;
    		last=te/3;
    	}
    	printf("%d\n",time);
    	cin>>a;
    }
    return 0;
}