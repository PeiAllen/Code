#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int arr[MAXN];
int am[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,r;
    cin>>n>>k>>r;
    int ri=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a;
    int goodam=k-r;
    for(int i=0;i<r;i++){
        cin>>a;
        cin>>am[a];
        if(am[a]==0)goodam++;
    }
    int best=INT_MAX;
    for(int i=0;i<n;i++){
        while(goodam<k&&ri+1<n){
            ri++;
            am[arr[ri]]--;
            if(am[arr[ri]]==0)goodam++;
        }
        if(goodam<k)break;
        best=min(best,ri-i+1);
        am[arr[i]]++;
        if(am[arr[i]]==1)goodam--;
    }
    if(best==INT_MAX)printf("impossible\n");
    else printf("%d\n",best);
    return 0;
}