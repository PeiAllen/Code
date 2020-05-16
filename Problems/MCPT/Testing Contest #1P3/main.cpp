#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli arr[MAXN];
lli sortarr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    lli v;
    cin>>n>>v;
    lli mi=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mi=min(mi,arr[i]);
        sortarr[i]=arr[i];
    }
    sort(sortarr,sortarr+n);
    lli ma=-1;
    for(int i=0;i<n;i++){
        if(arr[i]!=sortarr[i]){
            ma=max(ma,arr[i]);
        }
    }
    if(ma==-1)printf("0\n");
    else printf("%lli\n",max((lli)0,mi-v/ma));
    return 0;
}