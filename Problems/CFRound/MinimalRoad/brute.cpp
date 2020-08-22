#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=21;
vector<int> matrix[MAXN];
pii dsu[MAXN];
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
int ans[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;i++)ans[i]=n-1;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++)dsu[j]={j,1};
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))){
                cnt++;
                for(auto x:matrix[j]){
                    if(i&(1<<(x-1)))uni(j,x);
                }
            }
        }
        if(dsu[find(1)].second==cnt)for(int j=1;j<=n;j++){
            if(i&(1<<(j-1)))ans[j]=min(ans[j],cnt-1);
            else break;
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}