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
    for(int i=0;i<Q;i++){
        int ans=0;
        for(int j=0;j<N;j++){
            if(dp[j].second==-1)continue;
            int tim=G[i]-dp[j].first;
            if(tim<0)continue;
            if(dist[dp[j].second].second==-1){
                if(tim==0)ans++;
            }
            else if(dist[dp[j].second].second==dp[j].second){
                if(tim%dist[dp[j].second].first==0)ans++;
            }
            else if(dist[!dp[j].second].second==-1){
                if(tim==0||tim==dist[dp[j].second].first)ans++;
            }
            else if(dist[!dp[j].second].second==!dp[j].second){
                if(tim==0)ans++;
                else if(tim>=dist[dp[j].second].first&&(tim-dist[dp[j].second].first)%dist[!dp[j].second].first==0)ans++;
            }
            else{
                if(tim%(dist[dp[j].second].first+dist[!dp[j].second].first)==0||tim%(dist[dp[j].second].first+dist[!dp[j].second].first)==dist[dp[j].second].first)ans++;
            }
        }
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