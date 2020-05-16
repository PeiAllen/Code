#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=301;
int gr[MAXN];
pii dsu[MAXN];
int ind[MAXN];
int cnt[33];
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
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    set<int> roots;
    for(int i=1;i<=n;i++){
        cin>>gr[i];
        roots.insert(i);
        dsu[i]={i,1};
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        roots.erase(find(a)),roots.erase(find(b));
        uni(a,b);
        roots.insert(find(a));
    }
    int am=1;
    int in=0;
    for(int cur:roots){
        ind[cur]=in++;
    }
    for(int i=1;i<=n;i++)ind[i]=ind[find(i)];
    for(int i=0;i<sz(roots);i++)am*=4;
    int x,y,z;
    while(q--) {
        cin>>x>>y>>z;
        vector<vector<int>> ans;
        for (int i = 0; i < am; i++) {
            vector<int> bit;
            for(int j=1;j<=k;j++)cnt[j]=0;
            int cur = i;
            for (int j = 0; j < sz(roots); j++) {
                bit.push_back(cur % 4);
                cur /= 4;
            }
            vector<int> topr(n+1);
            for(int j=1;j<=n;j++){
                topr[j]=bit[ind[j]];
                if(bit[ind[j]]==0)cnt[gr[j]]++;
                else if(bit[ind[j]]==1)cnt[gr[j]+1]++;
                else if(bit[ind[j]]==2)cnt[gr[j]*2]++;
                else cnt[gr[j]^15]++;
            }
            if(abs(cnt[x]-cnt[y])==z)ans.push_back(topr);
        }
        if(sz(ans)){
            sort(ans.begin(),ans.end());
            printf("YES\n");
            for(int i=1;i<=n;i++)printf("%d ",ans[0][i]);
            printf("\n");
        }
        else printf("NO\n");
    }
    return 0;
}