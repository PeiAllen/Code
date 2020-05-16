#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXM=3e5+1;
const int MAXN=1e5+1;
pii dsu[MAXN];
int n,m,q;
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
void reset(){
    for(int i=1;i<=n;i++)dsu[i]={i,1};
}
pair<pii,pll> edges[MAXM];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("data.in","r",stdin);
    freopen("brute.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)cin>>edges[i].first.first>>edges[i].first.second>>edges[i].second.first>>edges[i].second.second;
    while(q--){
        reset();
        lli a,b;
        cin>>a>>b;
        for(int i=0;i<m;i++){
            if(edges[i].second.first>=a&&edges[i].second.second<=b){
                uni(edges[i].first.first,edges[i].first.second);
            }
        }
        if(dsu[find(1)].second==n)printf("YES\n");
        else printf("NO\n");
    }
//    for(int i=1;i<=m;i++){
//        reset();
//        bool done=false;
//        for(int j=1;j<=m;j++){
//            for(int k=0;k<m;k++){
//                if(edges[k].second.first>=i&&edges[k].second.second<=j)uni(edges[k].first.first,edges[k].first.second);
//            }
//            if(dsu[find(1)].second==n){
//                done=true;
//                printf("%d duri needs %d time\n",i,j);
//                break;
//            }
//        }
//        if(!done)printf("%d duri needs INT_MAX time\n",i);
//    }
    return 0;
}