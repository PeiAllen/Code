#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+2;
int ind[MAXN],rnk[MAXN],tmp[MAXN],lcp[MAXN],n;
string a,b;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>a>>b;
    a=a+"$"+b;
    n=sz(a);
    iota(ind,ind+n+1,0),sort(ind,ind+n,[&](auto &lhs, auto &rhs){return a[lhs]<a[rhs];}),rnk[n]=-1,rnk[ind[0]]=0;
    for(int i=1;i<n;i++)rnk[ind[i]]=(a[ind[i]]==a[ind[i-1]]?rnk[ind[i-1]]:i);
    for(int h=1;h<n;h+=h)for(int i=0,left=0;i<n;i++){
        if(rnk[ind[i]]!=rnk[ind[i+1]]&&left!=i){
            sort(ind+left,ind+i+1,[&](auto &lhs, auto &rhs){return rnk[lhs+h]<rnk[rhs+h];});
            tmp[left]=rnk[ind[left]];for(int j=left+1;j<=i;j++)tmp[j]=(rnk[ind[j]+h]==rnk[ind[j-1]+h]?tmp[j-1]:j);
            for(left=left+1;left<=i;left++)rnk[ind[left]]=tmp[left];
        }
        else if(rnk[ind[i]]!=rnk[ind[i+1]])left++;
    }
    for(int i=0,k=0,j=ind[rnk[i]+1];i<n;i++,k=(k?k-1:0),j=ind[rnk[i]+1]){
        while(i+k<n&&j+k<n&&a[i+k]==a[j+k])k++;
        lcp[rnk[i]]=k;
    }
    int best=-1;
    for(int i=0;i<n-1;i++){
        if(min(ind[i],ind[i+1])<n-sz(b)-1&&max(ind[i],ind[i+1])>=n-sz(b)&&(best==-1||lcp[best]<lcp[i]))best=i;
    }
    if(best==-1)cout<<"\n";
    else cout<<a.substr(ind[best],lcp[best])<<"\n";
    return 0;
}