#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
vector<pair<int,lli>> matrix[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a;
    lli b;
    for(int i=2;i<=n+m;i++){
        cin>>a>>b;
        matrix[a].push_back({i,b});
    }
    return 0;
}

/*
2 5
1 1
1 1
1 1
1 50
2 100
2 100






 */