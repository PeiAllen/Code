#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
pii matrix[MAXN];
int swaps=0;
pii dfs(int loc, int depth){
    if(loc==-1)return {depth,depth};
    pii l=dfs(matrix[loc].first,depth+1);
    pii r=dfs(matrix[loc].second,depth+1);
    if(swaps==-1)return {-1,-1};
    if(abs(max(l.second,r.second)-min(l.first,r.first))>1){
        swaps=-1;
        return {-1,-1};
    }
    if(l.second!=l.first&&r.second!=r.first){
        swaps=-1;
        return {-1,-1};
    }
    if(l.second!=l.first){
        if(r.first==l.second)swaps++;
    }
    else if(r.second!=r.first){
        if(l.first==r.first)swaps++;
    }
    else{
        if(l.first<r.first)swaps++;
    }
    return {min(l.first,r.first),max(l.second,r.second)};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>matrix[i].first>>matrix[i].second;
    }
    dfs(1,0);
    printf("%d\n",swaps);
    return 0;
}