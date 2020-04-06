#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
pair<pll,int> bombs[MAXN];
pii range[MAXN];
pii deq[MAXN];
pii sparse[19][MAXN];
int l=0,r=-1;
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bombs[i].first.first>>bombs[i].first.second;
        bombs[i].second=i+1;
    }
    sort(bombs,bombs+n);
    for(int i=0;i<n;i++){
        range[i].first=lower_bound(bombs,bombs+n,bombs[i].first.first-bombs[i].first.second,[&](auto it, auto val){
            return it.first.first<val;
        })-bombs;
        range[i].second=(upper_bound(bombs,bombs+n,bombs[i].first.first+bombs[i].first.second,[&](auto val, auto it){
            return val<it.first.first;
        })-bombs)-1;
    }
    for(int i=0;i<n;i++){
        while(r>=l&&deq[l].second<range[i].first)l++;
        if(r>=l)range[i].first=min(range[i].first,deq[l].first);
        while(r>=l&&deq[r].first>=range[i].first)r--;
        deq[++r]={range[i].first,i};
    }
    for(int i=n-1;i>=0;i--){
        while(r>=l&&deq[l].second>range[i].second)l++;
        if(r>=l)range[i].second=max(range[i].second,deq[l].first);
        while(r>=l&&deq[r].first<=range[i].second)r--;
        deq[++r]={range[i].second,i};
    }
    for(int i=0;i<n;i++)sparse[0][i]=range[i];
    for(int i=1;i<=log2(n);i++){
        for(int j=0;j<=n-(1<<i);j++){
            sparse[i][j].first=min(sparse[i-1][j].first,sparse[i-1][j+(1<<(i-1))].first);
            sparse[i][j].second=max(sparse[i-1][j].second,sparse[i-1][j+(1<<(i-1))].second);
        }
    }
    lli ans=0;
    for(int i=0;i<n;i++){
        int l=range[i].first,r=range[i].second;
        while(1){
            int k=log2(r-l+1);
            int newl=min(sparse[k][l].first,sparse[k][r-(1<<k)+1].first);
            int newr=max(sparse[k][l].second,sparse[k][r-(1<<k)+1].second);
            if(newl==l&&newr==r)break;
            l=newl,r=newr;
        }
        ans=(ans+((lli)(r-l+1)*bombs[i].second%mod))%mod;
    }
    printf("%lli\n",ans);
    return 0;
}