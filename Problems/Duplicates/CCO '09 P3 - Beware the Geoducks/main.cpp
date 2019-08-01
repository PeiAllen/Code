#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
template <typename T = int>
struct edge{
    int dest;
    T dist;
    edge(int a, T b):dest(a),dist(b){}
    bool operator<(const edge& rhs)const{
        return dist>rhs.dist;
    }
};
vector<edge<>> matrix[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int v,e,s,m,g,t;
    cin>>v>>e>>s>>m>>g>>t;
    int a,b,c;
    for(int i=0;i<e;i++){
		cin>>a>>b>>c;
		matrix[a].push_back({b,c});
		matrix[b].push_back({a,c});
    }
    for(int i=0;i<s;i++){

    }
    return 0;
}