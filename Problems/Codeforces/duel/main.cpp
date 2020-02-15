#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        for(int i=1;i<n;i++){
            printf("%d %d\n",i,i+1);
        }
        printf("%d %d\n",1,n);

    }
    return 0;
}