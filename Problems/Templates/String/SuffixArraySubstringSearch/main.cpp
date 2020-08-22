#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
int ind[MAXN],rnk[MAXN],tmp[MAXN];
string t,a;
int n;
int upperbound(){
    int lo=0,hi=n-1;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(a<t.substr(ind[mid],sz(a)))hi=mid;
        else lo=mid+1;
    }
    if(!(a<t.substr(ind[lo],sz(a))))lo++;
    return lo;
}
int lowerbound(){
    int lo=0,hi=n-1;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(a<=t.substr(ind[mid],sz(a)))hi=mid;
        else lo=mid+1;
    }
    if(!(a<=t.substr(ind[lo],sz(a))))lo++;
    return lo;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>t;
    n=sz(t);
    iota(ind,ind+n+1,0),sort(ind,ind+n,[&](auto & lhs, auto & rhs){return t[lhs]<t[rhs];}),rnk[n]=-1,rnk[ind[0]]=0;
    for(int i=1;i<n;i++)rnk[ind[i]]=(t[ind[i]]==t[ind[i-1]]?rnk[ind[i-1]]:i);
    for(int h=1;h<n;h+=h)for(int i=0,left=0;i<n;i++){
        if(rnk[ind[i]]!=rnk[ind[i+1]]&&left!=i){
            sort(ind+left,ind+i+1,[&](auto &lhs, auto &rhs){return rnk[lhs+h]<rnk[rhs+h];});
            tmp[left]=rnk[ind[left]];for(int j=left+1;j<=i;j++)tmp[j]=(rnk[ind[j]+h]==rnk[ind[j-1]+h]?tmp[j-1]:j);
            for(left=left+1;left<=i;left++)rnk[ind[left]]=tmp[left];
        }
        else if(rnk[ind[i]]!=rnk[ind[i+1]])left++;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>a;
        printf("%d\n",upperbound()-lowerbound());
    }
    return 0;
}