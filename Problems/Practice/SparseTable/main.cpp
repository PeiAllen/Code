#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+1;
int sparse[17][MAXN];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>sparse[0][i];
    for(int i=1;i<log2(n);i++){
        for(int j=0;j<=n-(1<<i);j++){
            sparse[i][j]=max(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        a-=1,b-=1;
        int k=log2(b-a+1);
        printf("%d\n",max(sparse[k][a],sparse[k][b-(1<<k)+1]));
    }
    return 0;
}