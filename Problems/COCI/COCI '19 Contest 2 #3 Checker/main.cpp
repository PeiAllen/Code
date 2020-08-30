#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
int col[MAXN],ne[MAXN];
pair<pii,int> edges[MAXN];
int cnt[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>n;
    string a;
    cin>>a;
    for(int i=1;i<=n;i++)col[i]=a[i-1]-'0',ne[i]=(i%n)+1;
    for(int i=0;i<n-3;i++){
        cin>>edges[i].first.first>>edges[i].first.second>>edges[i].second;
        if(edges[i].first.first>edges[i].first.second)swap(edges[i].first.first,edges[i].first.second);
        cnt[edges[i].first.first]++;
        cnt[edges[i].first.second]++;
    }
    sort(edges,edges+n-3,[&](auto lhs, auto rhs){
        return min(lhs.first.second-lhs.first.first,n-(lhs.first.second-lhs.first.first))<min(rhs.first.second-rhs.first.first,n-(rhs.first.second-rhs.first.first));
    });
    bool colour=true;
    for(int i=0;i<n-3;i++){
        if(edges[i].first.second-edges[i].first.first>n-(edges[i].first.second-edges[i].first.first))swap(edges[i].first.first,edges[i].first.second);
        if(cnt[ne[edges[i].first.first]]){
            printf("neispravna triangulacija\n");
            return 0;
        }
        if(ne[ne[edges[i].first.first]]!=edges[i].first.second){
            printf("neispravna triangulacija\n");
            return 0;
        }
        set<int> cols={edges[i].second,col[edges[i].first.first],col[ne[edges[i].first.first]]};
        if(sz(cols)!=3)colour=false;
        col[edges[i].first.first]=edges[i].second;
        ne[edges[i].first.first]=edges[i].first.second;
        cnt[edges[i].first.first]--,cnt[edges[i].first.second]--;
    }
    if(colour)printf("tocno\n");
    else printf("neispravno bojenje\n");
    return 0;
}