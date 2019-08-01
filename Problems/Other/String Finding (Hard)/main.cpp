#include <bits/stdc++.h>
using namespace std;
int longpre[2000002];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    string x=t+"$"+s;
    int left=0;
    int right=-1;
	for(int i=1;i<x.size();i++){
		if(right<i){
			for(int j=i;j<x.size()&&x[j]==x[j-i];j++){
				longpre[i]++;
			}
			left=i;
			right=i+longpre[i]-1;
		}
		else{
			if(longpre[i-left]+i>right){
				longpre[i]=right-i+1;
				for(int j=right+1;j<x.size()&&x[j]==x[j-i];j++){
					longpre[i]++;
				}
				left=i;
				right=i+longpre[i]-1;
			}
			else{
				longpre[i]=longpre[i-left];
			}
		}
		if(longpre[i]==t.size()){
			printf("%d\n",i-t.size()-1);
			return 0;
		}
	}
	printf("-1\n");
    return 0;
}