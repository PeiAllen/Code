#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<pair<int,pii>> queries;
const int MAXN=2e5+1;
int val[MAXN],et[MAXN],en[MAXN];
vector<int> matrix[MAXN];
int eloc=1;
void dfs(int loc){
    et[loc]=eloc++;
    for(auto x:matrix[loc])dfs(x);
    en[loc]=eloc-1;
}
struct node{
    set<int> data;
    node* ch[2];
    node(){
        data={};
        ch[0]=NULL,ch[1]=NULL;
    }
    void insert(int loc, int bit){
        data.insert(et[loc]);
        if(bit>=0) {
            int ne = !!(val[loc] & (1 << bit));
            if (!ch[ne])ch[ne] = new node();
            ch[ne]->insert(loc, bit - 1);
        }
    }
    int query(int cur, int bit, int l, int r){
        if(bit==-1)return 0;
        int want=!(cur&(1<<bit));
        if(ch[want]){
            auto it=ch[want]->data.lower_bound(l);
            if(it!=ch[want]->data.end()&&*it<=r)return (1<<bit)+ch[want]->query(cur,bit-1,l,r);
        }
        return ch[!want]->query(cur,bit-1,l,r);
    }
}vals;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    string a;
    int x,y;
    int nodeind=2;
    for(int i=0;i<q;i++){
        cin>>a>>x>>y;
        if(a[0]=='A'){
            queries.push_back({0,{nodeind,y}});
            matrix[x].push_back(nodeind);
            val[nodeind]=val[x]^y;
            nodeind++;
        }
        else queries.push_back({1,{x,y}});
    }
    dfs(1);
    vals.insert(1,30);
    for(int i=0;i<q;i++){
        if(queries[i].first==0)vals.insert(queries[i].second.first,30);
        else printf("%d\n",vals.query(val[queries[i].second.first],30,et[queries[i].second.second],en[queries[i].second.second]));
    }
    return 0;
}