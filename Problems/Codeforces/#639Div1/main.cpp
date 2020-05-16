#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
bool canbe[MAXN];
int ind[MAXN];
bool inst[MAXN];
int low[MAXN];
stack<int> st;
int curind=1;
bool baf=false;
void scc(int loc){
    ind[loc]=curind++;
    low[loc]=ind[loc];
    inst[loc]=true;
    st.push(loc);
    for(int x:matrix[loc]){
        if(!ind[x]){
            scc(x);
            low[loc]=min(low[loc],low[x]);
        }
        else if(inst[x])low[loc]=min(low[loc],ind[x]);
    }
    if(low[loc]!=ind[loc]){
        baf=true;
    }
    else{
        while(1){
            int te=st.top();
            st.pop();
            inst[te]=false;
            if(te==loc)break;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    int good=n;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(!canbe[b])good--;
        canbe[b]=true;
        matrix[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!ind[i])scc(i);
    }
    if(baf){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",good);
    for(int i=1;i<=n;i++){
        if(canbe[i])printf("E");
        else printf("A");
    }
    return 0;
}