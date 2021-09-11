#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+3;
int dfsorder[MN],bfsorder[MN],dfsind[MN],bfsind[MN];
double val[MN];
int forced[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dfsorder[i];
        dfsind[dfsorder[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>bfsorder[i];
        bfsind[bfsorder[i]]=i;
        if(i>=2){
            if(dfsind[bfsorder[i]]>dfsind[bfsorder[i-1]])val[i]=0.5;
            else val[i]=1;
        }
    }
    double ans=1.5;
    for(int i=2;i<=n;i++){
        if(bfsind[dfsorder[i]]>bfsind[dfsorder[i-1]]+1){
            forced[bfsind[dfsorder[i-1]]+1]++;
            forced[bfsind[dfsorder[i]]+1]--;
        }
    }
    for(int i=2;i<=n;i++){
        forced[i]+=forced[i-1];
        if(val[i]==1)ans+=val[i];
        else if(!forced[i])ans+=0.5;
    }
    printf("%.3f\n",ans);
    return 0;
}