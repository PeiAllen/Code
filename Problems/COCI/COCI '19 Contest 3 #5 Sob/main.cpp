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
    int n,m;
    cin>>n>>m;
    n--;
    while(n>=0){
        int cnt=1;
        while((m&n)!=n)m++,cnt++;
        for(int i=0;i<cnt;i++){
            printf("%d %d\n",n-i,m-i);
        }
        m++;
        n-=cnt;
    }
    return 0;
}