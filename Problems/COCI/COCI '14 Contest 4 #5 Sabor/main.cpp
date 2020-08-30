#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int col[MAXN];
vector<int> nodes;
void dfs(int loc){
    map<int,int> te;
    nodes.push_back(loc);
    for(int x:matrix[loc]){
        te[col[x]]++;
    }
    if(te[1]>=3)col[loc]=2;
    else col[loc]=1;
    te=map<int,int>();
    for(auto x:matrix[loc]){
        if(!col[x])dfs(x);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int am;
    int a,b;
    for(int i=0;i<5;i++){
        cin>>am;
        while(am--){
            cin>>a>>b;
            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++){
        if(!col[i]){
            nodes=vector<int>();
            dfs(i);
            for(int l=0;l<10;l++)for(auto x:nodes){
                map<int,int> te;
                for(int y:matrix[x]){
                    te[col[y]]++;
                }
                if(te[col[x]]>=3)col[x]=(col[x]==1?2:1);
                te=map<int,int>();
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%c",col[i]==1?'A':'B');
    printf("\n");
    return 0;
}