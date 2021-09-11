#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=101,MK=1001;
const __int128 MV=__int128(LLONG_MAX)*__int128(LLONG_MAX);
pll cost[MN][MK];
ll matrix[MN][MN];
ll best[MN][MN];
int n,m,k;
bool work(__int128 eff){
    vector<vector<__int128>> mat(n+1,vector<__int128>(n+1,0));
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(matrix[i][j]==0)mat[i][j]=MV;
        else mat[i][j]=__int128(matrix[i][j])*eff;
        if(i==j)assert(mat[i][j]==MV);
    }
    for(int mid=1;mid<=n;mid++){
        for(int i=1;i<=n;i++){
            if(mat[i][mid]!=MV)for(int j=1;j<=n;j++){
                if(mat[mid][j]!=MV)mat[i][j]=min(mat[i][j],mat[i][mid]+mat[mid][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]!=MV)mat[i][j]-=__int128(best[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        __int128 mival=MV;
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(mat[i][j]!=MV&&mat[j][i]!=MV)mival=min(mival,mat[i][j]+mat[j][i]);
            }
        }
        if(mival>mat[i][i]){
            assert(mival<=mat[i][i]);
        }
        assert(mat[i][i]>0);
    }
    vector<int> last(n+1,-1);
    for(int mid=1;mid<=n;mid++){
        for(int i=1;i<=n;i++){
            if(mat[i][mid]!=MV)for(int j=1;j<=n;j++){
                    if(mat[mid][j]!=MV){
                        if(mat[i][mid]+mat[mid][j]<mat[i][j]&&i==j)last[i]=mid;
                        mat[i][j]=min(mat[i][j],mat[i][mid]+mat[mid][j]);
                    }
            }
        }
    }
    bool pass=false;
    for(int i=1;i<=n;i++){
        if(mat[i][i]<=0)pass=true;
    }

//    for(int i=1;i<=n;i++){
//        bool othpass=false;
//        for(int j=1;j<=n;j++){
//            if(i!=j){
//                if(mat[i][j]!=MV&&mat[j][i]!=MV&&mat[i][j]+mat[j][i]<=0||(mat[i][j]<=0&&mat[i][j]<=0))othpass=true;
//            }
//        }
//    }

//    assert(othpass==pass);
    return pass;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>cost[i][j].first>>cost[i][j].second;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            best[i][j]=0;
            for(int l=1;l<=k;l++){
                if(cost[j][l].second!=-1&&cost[i][l].first!=-1)best[i][j]=max(best[i][j],cost[j][l].second-cost[i][l].first);
            }
            assert(best[i][j]>=0);
        }
    }
    int a,b;
    ll c;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        matrix[a][b]=c;
    }
    ll lo=0,hi=1e9;
    while(lo!=hi){
        ll mid=(lo+hi+1)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%lli\n",lo);
    return 0;
}