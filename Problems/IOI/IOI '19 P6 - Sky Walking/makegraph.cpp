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
    vector<int> loc(n),height(n),lefttower(m),righttower(m),height2(m);
    int s,g;
    for(int i=0;i<n;i++){
        cin>>loc[i]>>height[i];
        printf("Segment %d %d %d %d\n",loc[i],0,loc[i],height[i]);
    }
    for(int i=0;i<m;i++){
        cin>>lefttower[i]>>righttower[i]>>height2[i];
        printf("Segment %d %d %d %d\n",loc[lefttower[i]],height2[i],loc[righttower[i]],height2[i]);
    }
    cin>>s>>g;
    return 0;
}