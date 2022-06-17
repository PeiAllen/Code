#include "bits/stdc++.h"
using namespace std;
using ll =long long;
using pii = pair<int,int>;
using pll =pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1,MM=21;
const int mod=10007;
pii arr[MN];
int c;
struct seg{
    int t[2*MN][MM];// number of colour
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind][0]=arr[le].second%mod;
            t[ind][1]=arr[le].first%mod;
            for(int i=2;i<=c;i++)t[ind][i]=0;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        for(int i=0;i<=c;i++)t[ind][i]=0;
        for(int i=0;i<=min(c,mid-le+1);i++){
            for(int j=0;j<=min(ri-mid,c);j++){
                t[ind][min(c,i+j)]+=t[left][i]*t[right][j]%mod;
            }
        }
        for(int i=0;i<=c;i++)t[ind][i]%=mod;
    }
    void update(int ind, int le, int ri, int loc){
        if(loc>ri||loc<le)return;
        if(le==ri){
            t[ind][0]=arr[le].second%mod;
            t[ind][1]=arr[le].first%mod;
            for(int i=2;i<=c;i++)t[ind][i]=0;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        for(int i=0;i<=c;i++)t[ind][i]=0;
        for(int i=0;i<=min(c,mid-le+1);i++){
            for(int j=0;j<=min(ri-mid,c);j++){
                t[ind][min(c,i+j)]+=t[left][i]*t[right][j]%mod;
            }
        }
        for(int i=0;i<=c;i++)t[ind][i]%=mod;
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first;
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i].second;
    }
    tree.mt(0,1,n);
    int q,a;
    cin>>q;
    while(q--){
        cin>>a;
        cin>>arr[a].first>>arr[a].second;
        tree.update(0,1,n,a);
        printf("%lli\n",tree.t[0][c]);
    }
    return 0;
}