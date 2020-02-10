#include <bits/stdc++.h>
using namespace std;
template<typename T>
int sz(T &a){return (int)a.size();}
const int MAXN=10001;
struct node{
    map<int,int> to;
    int len,link;
    node(int a, int b){
        len=a,link=b;
        to={};
    }
};
vector<node> sauto;
vector<int> order;
vector<int> from[MAXN];
int deg[MAXN];
int ways[MAXN];
pair<int,int> tops[MAXN];
int lastnode;
void addchar(int c){
    int cur=lastnode;
    int me=sz(sauto);
    sauto.push_back(node(sauto[cur].len+1,-1));
    while(cur!=-1&&!sauto[cur].to.count(c)){
        sauto[cur].to[c]=me;
        cur=sauto[cur].link;
    }
    if(cur==-1)sauto[me].link=0;
    else {
        int oth = sauto[cur].to[c];
        if (sauto[oth].len == sauto[cur].len + 1)sauto[me].link = oth;
        else {
            int clone = sz(sauto);
            sauto.push_back(node(sauto[cur].len + 1, sauto[oth].link));
            sauto[clone].to=sauto[oth].to;
            sauto[me].link = clone;
            sauto[oth].link = clone;
            while (cur != -1&&sauto[cur].to.count(c)&&sauto[cur].to[c]==oth) {
                sauto[cur].to[c] = clone;
                cur = sauto[cur].link;
            }
        }
    }
    lastnode=me;
}
void toposort(){
    queue<int> topop;
    for(int i=0;i<sz(sauto);i++)if(deg[i]==0){
        topop.push(i);
    }
    while(sz(topop)){
        int cur=topop.front();
        topop.pop();
        order.push_back(cur);
        for(int x:from[cur]){
            deg[x]-=1;
            if(deg[x]==0)topop.push(x);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        sauto={node(0,-1)};
        lastnode=0;
        for(char x:a)addchar(x-'a');
        int ans=0;
        for(int i=0;i<sz(sauto);i++)from[i].clear();
        for(int i=0;i<sz(sauto);i++){
            deg[i]=sz(sauto[i].to);
            for(auto x:sauto[i].to){
                from[x.second].push_back(i);
            }
        }
        order.clear();
        toposort();
        reverse(order.begin(),order.end());
        for(int i=0;i<sz(sauto);i++)ways[i]=0;
        ways[0]=1;
        for(int i=0;i<sz(sauto);i++){
            ans+=ways[order[i]];
            for(auto x:sauto[order[i]].to){
                ways[x.second]+=ways[order[i]];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}