#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=501;
const int MAXM=1e6+3;
int arr[MAXM];
lli mod=998244353;
pii range[MAXN];
int deq[MAXM];
int l=0,r=-1;
int le[MAXM];
int ri[MAXM];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)range[i].first=INT_MAX;
    for(int i=1;i<=m;i++){
        cin>>arr[i];
        range[arr[i]].first=min(i,range[arr[i]].first);
        range[arr[i]].second=max(i,range[arr[i]].second);
    }
    deq[++r]=0;
    for(int i=1;i<=m;i++){
        while(r>=l&&arr[deq[r]]>=arr[i])r--;
        le[i]=deq[r];
        deq[++r]=i;
    }
    r=-1,l=0;
    deq[++r]=m+1;
    for(int i=m;i>=1;i--){
        while(r>=l&&arr[deq[r]]>=arr[i])r--;
        ri[i]=deq[r];
        deq[++r]=i;
    }
    lli ans=1;
    for(int i=1;i<=n;i++){
        if(le[range[i].second]>=range[i].first){
            printf("0\n");
            return 0;
        }

    }
    return 0;
}