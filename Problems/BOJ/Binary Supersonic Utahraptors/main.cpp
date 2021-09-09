#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,a;
    cin>>n>>m>>k;
    int acnt[2]={0,0},bcnt[2]={0,0};
    for(int i=0;i<n;i++){
        cin>>a;
        acnt[a]++;
    }
    for(int i=0;i<m;i++){
        cin>>a;
        bcnt[a]++;
    }
    printf("%d\n",abs(acnt[0]-bcnt[1]));
    return 0;
}