#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t=5;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        for(int i=2;i<n;i++){
            if(n%i==0)cnt++;
        }
        if(cnt==2||cnt==1)printf("semiprime\n");
        else printf("not\n");
    }
    return 0;
}