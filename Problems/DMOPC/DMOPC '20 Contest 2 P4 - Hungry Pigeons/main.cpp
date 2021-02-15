#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e4+1,MM=5e5+1;
int arr[MN],worm[MM];
int diff[MN];
int act[MN];
int topr[MM];
int n,m;
void cdq(int l, int r, int left, int right){//sus cdq since its a global contribution thats being passed and not query by query.
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++)diff[worm[i]]++;
    int mi = diff[0];
    act[0] = diff[0];
    for (int i = 1; i < n; i++)act[i] = act[i - 1] + diff[i], mi = min(mi, act[i] / (i + 1));
    if(l==r){
        topr[mid]=min(mi,right);
        for(int i=l;i<=mid;i++)diff[worm[i]]--;
    }
    else{
        if(mi+1<=right)cdq(mid+1,r,mi+1,right);
        for(int i=l;i<=mid;i++)diff[worm[i]]--;
        if(left<=mi)cdq(l,mid,left,mi);
    }
}
int main(){//CDQ
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int a;
    for(int i=0;i<m;i++){
        cin>>a;
        worm[i]=upper_bound(arr,arr+n,a)-arr;
    }
    cdq(0,m-1,1,m/n);
    int ree=0;
    for(int i=0;i<m;i++){
        ree=max(ree,topr[i]);
        printf("%d%c",ree," \n"[i==m-1]);
    }
    return 0;
}