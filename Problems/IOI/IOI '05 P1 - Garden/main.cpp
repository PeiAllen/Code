#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=251,MV=3000;
int psa[MN][MN],pma[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int l,w,n,k;
    cin>>l>>w>>n>>k;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        psa[a][b]++;
    }
    for(int i=0;i<=w;i++)pma[0][i]=MV;
    for(int i=0;i<=l;i++)pma[i][0]=MV;
    int ans=MV;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=w;j++){
            psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
            pma[i][j]=min(pma[i-1][j],pma[i][j-1]);
            int ptr=i;
            for(int m=1;m<=j;m++){
                while(ptr>=1&&psa[i][j]-psa[i][m-1]-psa[ptr-1][j]+psa[ptr-1][m-1]<k)ptr--;
                if(ptr==0)break;
                if(psa[i][j]-psa[i][m-1]-psa[ptr-1][j]+psa[ptr-1][m-1]>k)continue;
                pma[i][j]=min(pma[i][j],(i-ptr+1+j-m+1)*2);
            }
        }
    }
    for(int i=1;i<=l;i++){
        for(int j=1;j<=w;j++){
            int ptr=i;
            for(int m=1;m<=j;m++){
                while(ptr>=1&&psa[i][j]-psa[i][m-1]-psa[ptr-1][j]+psa[ptr-1][m-1]<k)ptr--;
                if(ptr==0)break;
                if(psa[i][j]-psa[i][m-1]-psa[ptr-1][j]+psa[ptr-1][m-1]>k)continue;
                ans=min(ans,(i-ptr+1+j-m+1)*2+min(pma[l][m-1],pma[ptr-1][w]));
            }
        }
    }
    if(ans==MV)printf("NO\n");
    else printf("%d\n",ans);
    return 0;
}