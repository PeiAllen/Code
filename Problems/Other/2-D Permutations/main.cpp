#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=25000001;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i*j]+=1;
            arr[n*m-((n-i+1)*(m-j+1)-1)+1]-=1;
        }
    }
    for(int i=1;i<=n*m;i++)arr[i]+=arr[i-1];
    int q;
    cin>>q;
    int a;
    while(q--){
        cin>>a;
        printf("%d\n",arr[a]);
    }
    return 0;
}