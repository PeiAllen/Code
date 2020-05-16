#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=201;
lli arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int a,b,c;
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            sort(arr+b,arr+c+1);
        }
        else sort(arr+b,arr+c+1,greater<>());
    }
    for(int i=1;i<=n;i++){
        printf("%lli",arr[i]);
        if(i!=n)printf(" ");
        else printf("\n");
    }
    return 0;
}