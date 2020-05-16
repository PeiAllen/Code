#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string a;
    cin>>n>>a;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)cout<<a;
        cout<<"\n";
    }
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++)cout<<a;
        cout<<"\n";
    }
    return 0;
}