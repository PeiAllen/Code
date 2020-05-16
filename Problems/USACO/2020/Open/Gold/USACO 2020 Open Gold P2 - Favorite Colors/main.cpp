#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
set<int> matrix[MAXN];
int dsu[MAXN];
int find(int a){
    if(dsu[a]==a)return a;
    return dsu[a]=find(dsu[a]);
}
void mergechildren(int loc){
    if(sz(matrix[loc])<=1)return;
    int cur=find(*matrix[loc].begin());
    auto store=matrix[loc];
    auto pt=store.begin();
    pt++;
    while(pt!=store.end()){
        int te=find(*pt);
        pt++;
        if(te==cur)continue;
        if(sz(matrix[te])>sz(matrix[cur]))swap(te,cur);
        dsu[te]=cur;
        matrix[cur].insert(matrix[te].begin(),matrix[te].end());
        matrix[te].clear();
    }
    store={};
    if(loc!=cur)matrix[loc]={cur};
    mergechildren(cur);
}
int col[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].insert(b);
    }
    for(int i=1;i<=n;i++)dsu[i]=i;
    for(int i=1;i<=n;i++)if(find(i)==i)mergechildren(i);
    int curcol=1;
    for(int i=1;i<=n;i++){
        int te=find(i);
        if(!col[te])col[te]=curcol++;
        col[i]=col[te];
        printf("%d\n",col[i]);
    }
    return 0;
}