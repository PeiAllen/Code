#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
int am[MN];
vector<int> blocks[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    int a,b;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        blocks[a].push_back(b);
        am[a]++;
    }
    for(int i=0;i<n+k;i++)dsu[i]={i,1};
    for(int i=1;i<=n;i++){
        am[i]+=am[i-1]+1;
        blocks[i].push_back(0);
        sort(blocks[i].begin(),blocks[i].end());
        int prev=0;
        for(int j=0;j<sz(blocks[i]);j++){
            while(prev+1<sz(blocks[i-1])&&blocks[i-1][prev+1]<(j==sz(blocks[i])-1?m+1:blocks[i][j+1])){
                if(blocks[i-1][prev+1]>blocks[i][j]+1)uni(am[i-2]+prev,am[i-1]+j);
                prev++;
            }
            if(i-1>0&&max(blocks[i-1][prev],blocks[i][j])+1<(j==sz(blocks[i])-1?m+1:blocks[i][j+1])){
                uni(am[i-2]+prev,am[i-1]+j);
            }
        }
    }
    int c,d;
    while(q--){
        cin>>a>>b>>c>>d;
        if(find(am[a-1]+lower_bound(blocks[a].begin(),blocks[a].end(),b)-blocks[a].begin()-1)==find(am[c-1]+lower_bound(blocks[c].begin(),blocks[c].end(),d)-blocks[c].begin()-1))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}