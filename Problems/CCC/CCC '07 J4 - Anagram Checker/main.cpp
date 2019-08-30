#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    map<char,int> ma;
    for(char x:a)ma[x]+=1;
    for(char x:b)ma[x]-=1;
    for(auto x:ma){
    	if(x.first!=' '&&x.second!=0){
    		printf("Is not an anagram.\n");
    		return 0;
    	}
    }
    printf("Is an anagram.");
    return 0;
}