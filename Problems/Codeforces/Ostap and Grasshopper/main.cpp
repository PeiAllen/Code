#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<int> matrix[101];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a,b;
    for(int i=0;i<n-1;i++){
    	cin>>a>>b;
    	matrix[a].push_back(b);
    	matrix[b].push_back(a);
    }

    return 0;
}