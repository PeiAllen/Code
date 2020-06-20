#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+2;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int l,r;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        arr[l]+=1,arr[r+1]-=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        if(arr[i]%2)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}