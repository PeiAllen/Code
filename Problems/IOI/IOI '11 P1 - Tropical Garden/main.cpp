#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=150001;
int matrix[2*MAXN];
bool gone[2*MAXN];
pii dist[2];
pii dp[2*MAXN];
map<int,int> specific;
vector<int> times[3][4*MAXN];
pii dfs(int loc){
    if(gone[loc])return dp[loc];
    gone[loc]=true;
    dp[loc]=dfs(matrix[loc]);
    if(dp[loc].first!=-1)dp[loc].first++;
    return dp[loc];
}
void answer(int a){
    printf("%d\n",a);
}
void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
    for(int i=0;i<2*N;i++)matrix[i]=-1,gone[i]=false,dp[i]={-1,-1};
    for(int i=0;i<M;i++){
        bool fav[2]={matrix[R[i][0]]==-1,matrix[R[i][1]]==-1};
        if(matrix[R[i][0]]==-1){
            matrix[R[i][0]]=(fav[1]?R[i][1]+N:R[i][1]);
        }
        else if(matrix[R[i][0]+N]==-1){
            matrix[R[i][0]+N]=(fav[1]?R[i][1]+N:R[i][1]);
        }
        if(matrix[R[i][1]]==-1){
            matrix[R[i][1]]=(fav[0]?R[i][0]+N:R[i][0]);
        }
        else if(matrix[R[i][1]+N]==-1){
            matrix[R[i][1]+N]=(fav[0]?R[i][0]+N:R[i][0]);
        }
    }
    for(int i=N;i<2*N;i++)if(matrix[i]==-1)matrix[i]=matrix[i-N];
    int cur=P;
    gone[P+N]=true;
    int dis=0;
    while(!gone[cur]){
        gone[cur]=true;
        cur=matrix[cur];
        dis++;
    }
    if(cur==P+N)dist[0]={dis,1};
    else if(cur==P)dist[0]={dis,0};
    else dist[0]={-1,-1};
    for(int i=0;i<2*N;i++)gone[i]=false;
    cur=P+N;
    dis=0;
    gone[P]=true;
    while(!gone[cur]){
        gone[cur]=true;
        cur=matrix[cur];
        dis++;
    }
    if(cur==P+N)dist[1]={dis,1};
    else if(cur==P)dist[1]={dis,0};
    else dist[1]={-1,-1};
    dp[P]={0,0};
    dp[P+N]={0,1};
    for(int i=0;i<2*N;i++)gone[i]=false;
    gone[P]=true,gone[N+P]=true;
    for(int i=0;i<2*N;i++){
        if(!gone[i]){
            dfs(i);
        }
    }
    set<pii> tosort;
    for(int i=0;i<N;i++){
        if(dp[i].second==-1)continue;
        if(dist[dp[i].second].second==-1){
            specific[dp[i].first]++;
        }
        else if(dist[dp[i].second].second==dp[i].second){
            times[dp[i].second][dp[i].first%dist[dp[i].second].first].push_back(dp[i].first);
            tosort.insert({dp[i].second,dp[i].first%dist[dp[i].second].first});
        }
        else if(dist[!dp[i].second].second==-1){
            specific[dp[i].first]++;
            specific[dist[dp[i].second].first+dp[i].first]++;
        }
        else if(dist[!dp[i].second].second==!dp[i].second){
            specific[dp[i].first]++;
            times[!dp[i].second][(dist[dp[i].second].first+dp[i].first)%dist[!dp[i].second].first].push_back(dist[dp[i].second].first+dp[i].first);
            tosort.insert({!dp[i].second,(dist[dp[i].second].first+dp[i].first)%dist[!dp[i].second].first});
        }
        else{
            times[2][dp[i].first%(dist[dp[i].second].first+dist[!dp[i].second].first)].push_back(dp[i].first);
            tosort.insert({2,dp[i].first%(dist[dp[i].second].first+dist[!dp[i].second].first)});
            times[2][(dp[i].first+dist[dp[i].second].first)%(dist[dp[i].second].first+dist[!dp[i].second].first)].push_back(dp[i].first+dist[dp[i].second].first);
            tosort.insert({2,(dp[i].first+dist[dp[i].second].first)%(dist[dp[i].second].first+dist[!dp[i].second].first)});
        }
    }
    for(auto x:tosort)sort(times[x.first][x.second].begin(),times[x.first][x.second].end());
    for(int i=0;i<Q;i++){
        int ans=specific[G[i]];
        if(dist[0].first!=-1&&dist[0].second==0&&sz(times[0][G[i]%dist[0].first])){int x=G[i]%dist[0].first;ans+=upper_bound(times[0][x].begin(),times[0][x].end(),G[i])-times[0][x].begin();}
        if(dist[1].first!=-1&&dist[1].second==1&&sz(times[1][G[i]%dist[1].first])){int x=G[i]%dist[1].first;ans+=upper_bound(times[1][x].begin(),times[1][x].end(),G[i])-times[1][x].begin();}
        if(dist[0].first!=-1&&dist[1].first!=-1&&dist[0].second==1&&dist[1].second==0&&sz(times[2][G[i]%(dist[0].first+dist[1].first)])){int x=G[i]%(dist[0].first+dist[1].first);ans+=upper_bound(times[2][x].begin(),times[2][x].end(),G[i])-times[2][x].begin();}
        answer(ans);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    int arr[20][2];
    for(int i=0;i<m;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    int queries[100];
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    count_routes(n,m,p,arr,q,queries);
    return 0;
}