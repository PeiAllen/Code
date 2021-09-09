#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=301;
bool matrix[MN][MN];
bool good[MN*MN];
bool changed[MN*MN];
pii edge[MN*MN];
void query(const vector<int> &a, const vector<int> &b){
    printf("? %d %d\n",SZ(a),SZ(b));
    for(auto x:a){
        printf("%d%c",x," \n"[x==a.back()]);
    }
    for(auto x:b){
        printf("%d%c",x," \n"[x==b.back()]);
    }
    fflush(stdout);
    int am=0,given;
    cin>>am;
    for(int i=0;i<am;i++){
        cin>>given;
        good[given]=true;
    }
}
void solve(const vector<int> &nodes, const vector<int> &edges){
    if(SZ(nodes)==1)return;
    int mid=(0+SZ(nodes)-1)/2;
    vector<int> leftedges,rightedges,tocheck;
    for(auto x:edges){
        if(edge[x].A<=nodes[mid]&&edge[x].B<=nodes[mid])leftedges.push_back(x);
        else if(edge[x].A>nodes[mid]&&edge[x].B>nodes[mid])rightedges.push_back(x);
        else tocheck.push_back(x);
    }
    query(vector<int>(nodes.begin(),nodes.begin()+mid+1),vector<int>(nodes.begin()+mid+1,nodes.end()));
    for(auto x:tocheck){
        if(!good[x]){
            changed[x]=true;
        }
    }
    solve(vector<int>(nodes.begin(),nodes.begin()+mid+1),leftedges);
    solve(vector<int>(nodes.begin()+mid+1,nodes.end()),rightedges);
}
vector<int> nodesin,edgesin;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>edge[i].A>>edge[i].B;
    }
    nodesin.resize(n),edgesin.resize(m);
    iota(nodesin.begin(),nodesin.end(),1);
    iota(edgesin.begin(),edgesin.end(),1);
    solve(nodesin,edgesin);
    printf("! ");
    for(int i=1;i<=m;i++)printf("%d",changed[i]);
    printf("\n");
    return 0;
}