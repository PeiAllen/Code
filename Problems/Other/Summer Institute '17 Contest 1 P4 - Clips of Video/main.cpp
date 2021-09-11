#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
struct speed{
    int ind, rnk;
    bool operator<(const speed &a)const {
        return rnk<a.rnk;
    }
};
speed ind[MAXN];
int rnk[MAXN],tmp[MAXN],lcp[MAXN],actlcp[MAXN][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    int asize=sz(a);
    a=a+"$"+b;
    int n=sz(a);
    for(int i=0;i<=n;i++)ind[i]={i,a[i]};sort(ind,ind+n),rnk[n]=-1,rnk[ind[0].ind]=0;
    for(int i=1;i<n;i++)rnk[ind[i].ind]=(ind[i].rnk==ind[i-1].rnk?rnk[ind[i-1].ind]:i);
    for(int h=1;h<n;h<<=1)for(int i=0,left=0;i<n;i++){
        ind[i].rnk=rnk[ind[i].ind+h];
        if(rnk[ind[i].ind]!=rnk[ind[i+1].ind]&&left!=i){
            sort(ind+left,ind+i+1);
            tmp[left]=rnk[ind[left].ind];for(int j=left+1;j<=i;j++)tmp[j]=(ind[j].rnk==ind[j-1].rnk?tmp[j-1]:j);
            for(left=left+1;left<=i;left++)rnk[ind[left].ind]=tmp[left];
        }
        else left+=rnk[ind[i].ind]!=rnk[ind[i+1].ind];
    }
    for(int i=0,k=0,j=ind[rnk[i]+1].ind;i<n;i++,k-=k>0,j=ind[rnk[i]+1].ind){
        while(i+k<n&&j+k<n&&a[i+k]==a[j+k])k++;
        lcp[rnk[i]]=k;
    }
    int curlcp=0;
    for(int i=0;i<n;i++){
        actlcp[i][0]=curlcp;
        if(ind[i].ind<asize)curlcp=lcp[i];
        else curlcp=min(curlcp,lcp[i]);
    }
    curlcp=0;
    for(int i=n-1;i>=0;i--){
        actlcp[i][1]=curlcp=min(curlcp,lcp[i]);
        if(ind[i].ind<asize)curlcp=INT_MAX;
    }
    int curind=asize+1;
    int ans=0;
    while(curind<n){
        int best=max(actlcp[rnk[curind]][0],actlcp[rnk[curind]][1]);
        if(best==0){
            printf("-1\n");
            return 0;
        }
        curind+=best;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}