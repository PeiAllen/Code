#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
ll arr[MAXN];
int llae[MAXN];
int flee[MAXN];
int deq[MAXN];
int mintable[21][MAXN];
int l=0,r=-1;
int n;
void buildtable(){
    for(int i=1;i<=log2(n);i++){

    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i],mintable[0][i-1]=arr[i];
    arr[0]=LLONG_MAX;
    buildtable();
    deq[++r]=0;
    for(int i=1;i<=n;i++){
        while(l<=r&&arr[deq[r]]<arr[i])r--;
        llae[i]=deq[r];
        deq[++r]=i;
    }

    return 0;
}