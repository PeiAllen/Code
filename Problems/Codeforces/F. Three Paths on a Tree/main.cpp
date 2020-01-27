#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=2e5+1;
pair<pii,int> maxdown[MAXN][2];
pii maxup[MAXN];
vector<int> matrix[MAXN];
int best=0;
vector<int> ans;
void dfs(int loc, int parent){
    vector<pair<pii,int>> giv={{{0,loc},loc},{{0,loc},loc}};
    for(int x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc);
            giv.push_back({{maxdown[x][0].first.first,x},maxdown[x][0].second});
        }
    }
    sort(giv.begin(),giv.end(),greater<pair<pii,int>>());
    maxdown[loc][0]={{giv[0].first.first+1,giv[0].first.second},giv[0].second},maxdown[loc][1]={{giv[1].first.first+1,giv[1].first.second},giv[1].second};
}
void calcup(int loc, int parent){
    vector<pii> touse;
    if(maxup[parent].first>(maxdown[parent][0].first.second==loc?maxdown[parent][1].first.first:maxdown[parent][0].first.first)){
        maxup[loc]={maxup[parent].first+1,maxup[parent].second};
    }
    else{
        maxup[loc]={(maxdown[parent][0].first.second==loc?maxdown[parent][1].first.first:maxdown[parent][0].first.first)+1,maxdown[parent][0].first.second==loc?maxdown[parent][1].second:maxdown[parent][0].second};
    }
    if(maxup[loc].second==0)maxup[loc].second=1;
    touse.push_back({maxup[loc].first-1,maxup[loc].second});
    for(int x:matrix[loc]){
        if(x!=parent){
            calcup(x,loc);
            touse.push_back({maxdown[x][0].first.first,maxdown[x][0].second});
        }
    }
    sort(touse.begin(),touse.end(),greater<pii>());
    int te=0;
    vector<int> nodes;
    for(int i=0;i<min(3,(int)touse.size());i++){
        te+=touse[i].first;
        nodes.push_back(touse[i].second);
    }
    if(te>best) {
        if ((int)nodes.size() == 2) {
            best=te;
            ans={nodes[0],nodes[1],loc};
        }
        else if ((int)nodes.size()==3) {
            best=te;
            ans=nodes;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0);
    calcup(1,0);
    printf("%d\n",best);
    for(int x:ans)printf("%d ",x);
    return 0;
}