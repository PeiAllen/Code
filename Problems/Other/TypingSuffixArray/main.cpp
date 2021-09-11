#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
int ind[MAXN],rnk[MAXN],tmp[MAXN],lcp[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    string s;
    cin>>s;
    int ssize=sz(s);
    s=s+"$"+a;
    int n=sz(s);
    iota(ind,ind+n+1,0),sort(ind,ind+n,[&](auto &lhs, auto & rhs){return s[lhs]<s[rhs];}),rnk[n]=-1,rnk[ind[0]]=0;
    for(int i=1;i<n;i++)rnk[ind[i]]=(s[i]==s[ind[i-1]]?rnk[ind[i-1]]:i);
    for(int h=1;h<n;h<<=1)for(int i=0,left=0;i<n;i++){
        if(rnk[ind[i]]!=rnk[ind[i+1]]&&left!=i) {
            sort(ind+left, ind+i+1,[&](auto &lhs, auto &rhs){return rnk[lhs + h] < rnk[rhs + h];});
            tmp[left]=rnk[ind[left]];for(int j=left+1;j<=i;j++)tmp[j]=(rnk[ind[j]+h]==rnk[ind[j-1]+h]?tmp[j-1]:j);
            for(left=left+1;left<=i;left++)rnk[ind[left]]=tmp[left];
        }
        else if(rnk[ind[i]]!=rnk[ind[i+1]])left++;
    }
    for(int i=0,k=0,j=ind[rnk[i]+1];i<n;i++,k-=k>0,j=ind[rnk[i]+1]){
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k])k++;
        lcp[rnk[i]]=k;
    }
    int am=0;
    while(rnk[ssize+1]+am+1<n&&lcp[rnk[ssize+1]+am]==sz(a))am++;
    printf("%d\n",am);
    return 0;
}