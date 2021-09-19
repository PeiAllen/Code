#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int n;
vector<int> query(int loc){
    printf("? %d\n",loc);
    vector<int> ret(n+1);
    cin>>ret[1];
    if(ret[1]==-1)exit(0);
    for(int i=2;i<=n;i++){
        cin>>ret[i];
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    cin>>n;
    vector<int> col=query(1);
    int count[2]={0,0};
    for(int i=1;i<=n;i++){
        count[col[i]%2]++;
    }
    int use=(count[1]<=count[0]);
    vector<pii> edges;
    for(int i=1;i<=n;i++){
        if(col[i]%2==use) {
            vector<int> dist = query(i);
            for(int j=1;j<=n;j++){
                if(dist[j]==1)edges.push_back({i,j});
            }
        }
    }
    printf("!\n");
    for(auto x:edges)printf("%d %d\n",x.first,x.second);
    return 0;
}