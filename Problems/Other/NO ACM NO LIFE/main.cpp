#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=301;
vector<int> matrix[MN];
int label[MN];
int parent[MN],depth[MN];
int numoflabel[MN];
bool gone[MN];
void dfs(int loc, int par){
    depth[loc]=depth[par]+1;
    parent[loc]=par;
    for(auto x:matrix[loc])if(x!=par)dfs(x,loc);
}
int getnodecnt(int loc, int par, int dis, int val){
    if(dis==1)return val<loc;
    int sum=1;
    for(auto x:matrix[loc])if(x!=par)sum+=getnodecnt(x,loc,dis-1,val);
    return sum;
}
vector<int> getpath(int a, int b){
    vector<int> le={},ri={};
    while(a!=b){
        if(depth[a]>depth[b])le.push_back(a),a=parent[a];
        else ri.push_back(b),b=parent[b];
    }
    le.push_back(a);
    le.insert(le.end(),ri.rbegin(),ri.rend());
    return le;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n;i++)matrix[i]=vector<int>(),numoflabel[i]=0;
        int a,b;
        for(int i=1;i<n;i++){
            cin>>a>>b;
            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }
        dfs(1,0);
        vector<int> compress;
        for(int i=1;i<=n;i++)cin>>label[i],compress.push_back(label[i]);
        sort(compress.begin(),compress.end()),compress.erase(unique(compress.begin(),compress.end()),compress.end());
        for(int i=1;i<=n;i++)label[i]=lower_bound(compress.begin(),compress.end(),label[i])-compress.begin();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                vector<int> path=getpath(i,j);
                gone[label[i]]=true;
                int cnt=1;
                        int nodecnt=sz(path)-2;
                            if(!gone[label[j]])cnt++,gone[label[j]]=true;
                    for(int x=1;x<sz(path)-1;x++){
                        int val=0,dis=min(x,sz(path)-1-x);
                        if(x==dis)val=max(val,i);
                        if(sz(path)-1-x==dis)val=max(val,j);
                        if(!gone[label[path[x]]])cnt++,gone[label[path[x]]]=true;
                        for(auto y:matrix[path[x]]){
                        if(y!=path[x-1]&&y!=path[x+1]){
                            nodecnt+=getnodecnt(y,path[x],dis,val);
                        }
                    }
                }
                if(nodecnt>=k-2)numoflabel[nodecnt]+=cnt;
                for(auto x:path)gone[label[x]]=false;
            }
        }
        double ans=0;
        double prob=double(k*(k-1))/double((n-k+1)*(n-k+2));
        for(int i=n-1;i>=k-2;i--){
            prob=prob/double(i+1)*double(i+1-(k-2));
            ans+=prob*double(numoflabel[i]);
        }
        printf("%.9f\n",ans);
    }
    return 0;
}