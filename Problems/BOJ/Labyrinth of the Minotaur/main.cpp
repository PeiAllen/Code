#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1501;
int xc[8]={1,-1,0,0,1,-1,1,-1},yc[8]={0,0,1,-1,1,-1,-1,1};
pii dsu[MN*MN+1];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
char arr[MN][MN];
int psa[3][MN+1][MN+1];
int query(int ind, int down, int left, int up, int right){
    return psa[ind][up][right]-(down>=1?psa[ind][down-1][right]:0)-(left>=1?psa[ind][up][left-1]:0)+(down>=1&&left>=1?psa[ind][down-1][left-1]:0);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>m>>n;
    dsu[0]={0,1},dsu[n*m+1]={n*m+1,1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='#')psa[0][i][j]=1;
            psa[0][i][j]+=psa[0][i-1][j]+psa[0][i][j-1]-psa[0][i-1][j-1];
            dsu[(i-1)*m+j]={(i-1)*m+j,1};
            if(arr[i][j]=='#'){
                if(j==1||i==n)uni(0,(i-1)*m+j);
                if(j==m||i==1)uni(n*m+1,(i-1)*m+j);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            if(arr[i][j]=='#'){
                for(int k=0;k<8;k++){
                    pii ne={i+xc[k],j+yc[k]};
                    if(ne.first>=1&&ne.first<=n&&ne.second>=1&&ne.second<=m&&arr[ne.first][ne.second]=='#'){
                        uni((i-1)*m+j,(ne.first-1)*m+ne.second);
                    }
                }
            }
        }
    }
    for(int i=0;i<=n+1;i++) {
        for (int j = 0; j <= m+1; j++) {
            if(i==0&&j==0)continue;
            if(i!=n+1||j!=m+1) {
                if (i == 0 || j == m + 1)psa[2][i][j]=1;
                if(j==0||i==n+1)psa[1][i][j]=1;
            }
            if(i<=n&&j<=m&&i>=1&&j>=1&&find((i-1)*m+j)==find(0))psa[1][i][j]=1;
            psa[1][i][j]+=(i>=1?psa[1][i-1][j]:0)+(j>=1?psa[1][i][j-1]:0)-(i>=1&&j>=1?psa[1][i-1][j-1]:0);
            if(i<=n&&j<=m&&i>=1&&j>=1&&find((i-1)*m+j)==find(n*m+1))psa[2][i][j]=1;
            psa[2][i][j]+=(i>=1?psa[2][i-1][j]:0)+(j>=1?psa[2][i][j-1]:0)-(i>=1&&j>=1?psa[2][i-1][j-1]:0);
        }
    }
    int len=INT_MAX;
    pii point={-1,-1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]!='#'&&(i!=1||j!=1)&&(i!=n||j!=m)){
                int lo=1,hi=min(n-i+1,m-j+1);
                if(i+hi-1==n&&j+hi-1==m)hi--;
                while(lo!=hi) {
                    int mid=(lo+hi+1)/2;
                    if(query(0,i,j,i+mid-1,j+mid-1)>=1)hi=mid-1;
                    else lo=mid;
                }
                if(query(1,i-1,j-1,i+lo,j+lo)>=1&&query(2,i-1,j-1,i+lo,j+lo)>=1){
                    lo=1;
                    while(lo!=hi){
                        int mid=(lo+hi)/2;
                        if(query(1,i-1,j-1,i+mid,j+mid)>=1&&query(2,i-1,j-1,i+mid,j+mid)>=1)hi=mid;
                        else lo=mid+1;
                    }
                    if(lo<len)len=lo,point={i,j};
                }
            }
        }
    }
    if(len==INT_MAX)printf("Impossible\n");
    else printf("%d %d %d\n",len,point.second,point.first);
    return 0;
}