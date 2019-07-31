#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    map<string,int> cnt;
    string a;
    int ma=0;
    string b;
    while(n--){
		cin>>a;
		cnt[a]+=1;
		if(cnt[a]>ma){
			ma=cnt[a];
			b=a;
		}
    }
    cout<<b<<"\n";
    return 0;
}