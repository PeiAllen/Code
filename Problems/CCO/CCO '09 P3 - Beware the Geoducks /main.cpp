#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int matrix[101][101];
struct path{
	int who,loc,t;
	path(int a=0, int b=0,int c=0):who(a),loc(b),t(c)
	bool operator<(path & rhs)const{
		return t>rhs.t;
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int v,e,s,m,g,t;
    cin>>v>>e>>s>>m>>g>>t;
    int a,b,c;
    memset(matrix,-1,sizeof(matrix));
    for(int i=0;i<e;i++){
    	cin>>a>>b>>c;
    	matrix[a][b]=c;
    	matrix[b][a]=c;
    }
    vector<int> route[2];

    return 0;
}