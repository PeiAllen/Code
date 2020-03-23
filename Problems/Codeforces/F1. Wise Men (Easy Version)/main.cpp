#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
bool arr[15][15];
lli dp[16384][15][15];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        for(int j=0;j<n;j++){
            arr[i][j]=a[j]-'0';
        }
    }

    return 0;
}