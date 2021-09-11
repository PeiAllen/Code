#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXB=30,MAXN=1e5+1;
int val[MAXB][2];
pair<string,int> gates[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>gates[i].first>>gates[i].second;
    }
    for(int i=0;i<=29;i++){
        val[i][0]=0,val[i][1]=(1<<i);
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                if(gates[j].first=="OR")val[i][k]|=(gates[j].second&(1<<i));
                else if(gates[j].first=="XOR")val[i][k]^=(gates[j].second&(1<<i));
                else val[i][k]&=(gates[j].second&(1<<i));
            }
        }
    }
    pii ans={0,0};//not-restricted,restricted;
    for(int i=0;i<=29;i++){
        pii te={0,0};
        te.first=ans.first+max(val[i][0],val[i][1]);
        if(m&(1<<i))te.second=max(ans.first+val[i][0],ans.second+val[i][1]);
        else te.second=ans.second+val[i][0];
        ans=te;
    }
    printf("%d\n",ans.second);
    return 0;
}