#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int MAXN=1e5+1;
int arr[2][MAXN];
int act[MAXN];
int ind[MAXN];
lli bit[MAXN];
int n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
lli query(int loc){
    lli am=0;
    for(;loc>0;loc-=loc&-loc)am+=bit[loc];
    return am;
}
lli check(){
    memset(bit,0,sizeof(bit));
    lli inver=0;
    for(int i=0;i<n;i++)ind[arr[0][i]]=i+1;
    for(int i=0;i<n;i++){
        act[i]=ind[arr[1][i]];
        inver+=query(n)-query(act[i]);
        update(act[i],1);
    }
    lli best=inver;
    for(int i=0;i<n;i++){
        inver-=query(act[i]-1);
        inver+=query(n)-query(act[i]);
        best=min(best,inver);
    }
    return best;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin>>arr[i][j];
    lli best=check();
    for(int i=0;i<n;i++)swap(arr[0][i],arr[1][i]);
    best=min(best,check());
    printf("%lli\n",best);
    return 0;
}