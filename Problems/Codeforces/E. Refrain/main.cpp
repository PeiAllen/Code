#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=150005;
int arr[MAXN],ind[MAXN],rnk[MAXN],tmp[MAXN],lcp[MAXN],deq[MAXN],n,l,r;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    iota(ind,ind+n+1,0),sort(ind,ind+n,[&](auto &lhs, auto &rhs){return arr[lhs]<arr[rhs];}),rnk[n]=-1,rnk[ind[0]]=0;
    for(int i=1;i<n;i++)rnk[ind[i]]=(arr[ind[i]]==arr[ind[i-1]]?rnk[ind[i-1]]:i);
    for(int h=1;h<n;h+=h)for(int i=0,left=0;i<n;i++){
        if(rnk[ind[i]]!=rnk[ind[i+1]]&&left!=i){
            sort(ind+left,ind+i+1,[&](auto &lhs, auto &rhs){return rnk[lhs+h]<rnk[rhs+h];});
            tmp[left]=rnk[ind[left]];for(int j=left+1;j<=i;j++)tmp[j]=(rnk[ind[j]+h]==rnk[ind[j-1]+h]?tmp[j-1]:j);
            for(left=left+1;left<=i;left++)rnk[ind[left]]=tmp[left];
        }
        else if(rnk[ind[i]]!=rnk[ind[i+1]])left++;
    }
    for(int i=0,k=0,j=ind[rnk[i]+1];i<n;i++,k=(k?k-1:0),j=ind[rnk[i]+1]){
        while(i+k<n&&j+k<n&&arr[i+k]==arr[j+k])k++;
        lcp[rnk[i]]=k;
    }
    ll best=n;
    pii loc={0,n};
    l=0,r=-1;
    deq[++r]=-1;
    for(int i=0;i<n;i++){
        while(deq[r]!=-1&&lcp[deq[r]]>=lcp[i]){
            if(ll(lcp[deq[r]])*ll(i-deq[r-1])>best){
                best=ll(lcp[deq[r]])*ll(i-deq[r-1]);
                loc={ind[deq[r]],lcp[deq[r]]};
            }
            r--;
        }
        deq[++r]=i;
    }
    printf("%lli\n%d\n",best,loc.second);
    for(int i=0;i<loc.second;i++)printf("%d ",arr[i+loc.first]);
    return 0;
}