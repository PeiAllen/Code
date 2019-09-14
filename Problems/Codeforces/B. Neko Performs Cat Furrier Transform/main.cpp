#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int x;
	sc(x);
	vector<int> moves;
	for(int i=19;i>=0;i--){
		if(!(x&(1<<i))){
			moves.push_back(i+1);
			x^=((1<<(i+1))-1);
		}
	}
	pr(moves.size(),"\n");
	for(int y:moves)pr(y,"");
    return 0;
}