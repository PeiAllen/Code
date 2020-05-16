#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1001;
vector<int> matrix[MAXN];
int dist[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.in","r",stdin);
    int l,house,dest;
    cin>>l>>house>>dest;
    int n;
    cin>>n;
    for(int i=1;i<=l;i++)dist[i]=-1;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        matrix[a].push_back(b);
    }
    dist[house]=0;
    queue<int> q;
    q.push(house);
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(int x:matrix[cur]){
            if(dist[x]==-1){
                dist[x]=dist[cur]+1;
                q.push(x);
            }
        }
    }
    printf("%d\n",dist[dest]);
    return 0;
}