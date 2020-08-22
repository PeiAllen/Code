#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=4e5+1;
int ind[MAXN],rnk[MAXN],tmp[MAXN],lcp[19][MAXN],n;
pii arr[MAXN];
string s;
void mt(){
   for(int j=1;j<=log2(n);j++){
       for(int i=0;i<=n-(1<<j);i++){
            lcp[j][i]=min(lcp[j-1][i],lcp[j-1][i+(1<<(j-1))]);
       }
   }
}
int getlcp(int a, int b){
    if(a==b)return n-a;
    a=rnk[a],b=rnk[b];
    if(a>b)swap(a,b);
    b--;
    int k=log2(b-a+1);
    return min(lcp[k][a],lcp[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s;
    n=sz(s);
    iota(ind,ind+n+1,0),sort(ind,ind+n,[&](auto &lhs, auto &rhs){return s[lhs]<s[rhs];}),rnk[n]=-1,rnk[ind[0]]=0;
    for(int i=1;i<n;i++)rnk[ind[i]]=(s[ind[i]]==s[ind[i-1]]?rnk[ind[i-1]]:i);
    for(int h=1;h<n;h+=h)for(int i=0,left=0;i<n;i++){
        if(rnk[ind[i]]!=rnk[ind[i+1]]&&left!=i){
            sort(ind+left,ind+i+1,[&](auto &lhs, auto &rhs){return rnk[lhs+h]<rnk[rhs+h];});
            tmp[left]=rnk[ind[left]];for(int j=left+1;j<=i;j++)tmp[j]=(rnk[ind[j]+h]==rnk[ind[j-1]+h]?tmp[j-1]:j);
            for(left=left+1;left<=i;left++)rnk[ind[left]]=tmp[left];
        }
        else if(rnk[ind[i]]!=rnk[ind[i+1]])left++;
    }
    for(int i=0,k=0,j=ind[rnk[i]+1];i<n;i++,k=(k?k-1:0),j=ind[rnk[i]+1]){
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k])k++;
        lcp[0][rnk[i]]=k;
    }
    mt();
    int q;
    cin>>q;
    for(int i=0;i<q;i++)cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+q,[&](auto &lhs, auto &rhs){
        if(getlcp(lhs.first-1,rhs.first-1)<min(lhs.second-lhs.first+1,rhs.second-rhs.first+1))return rnk[lhs.first-1]<rnk[rhs.first-1];
        if(lhs.second-lhs.first+1!=rhs.second-rhs.first+1)return lhs.second-lhs.first+1<rhs.second-rhs.first+1;
        return lhs<rhs;
    });
    for(int i=0;i<q;i++)printf("%d %d\n",arr[i].first,arr[i].second);
    return 0;
}