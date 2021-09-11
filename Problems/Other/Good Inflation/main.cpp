#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e6+2;
struct line{
    ll m,b;
    line(ll a=0, ll c=0){
        m=a,b=c;
    }
    ll at(ll x){
        return b+m*x;
    }
};
struct lichao{
    line t[2*MAXN];
    void update(int ind, int le, int ri, line a){
        int mid=(le+ri)/2;
        bool lef=a.at(le)>=t[ind].at(le),mi=a.at(mid)>=t[ind].at(mid);
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(mi)swap(a,t[ind]);
        if(le==ri)return;
        if(lef!=mi)update(left,le,mid,a);
        else update(right,mid+1,ri,a);
    }
    ll query(int ind, int le, int ri, int loc){
        ll ans=t[ind].at(loc);
        if(le==ri)return ans;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(loc<=mid)return max(ans,query(left,le,mid,loc));
        return max(ans,query(right,mid+1,ri,loc));
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ll best=tree.query(0,0,n,i);
        tree.update(0,0,n,line(-b,best+a+b*ll(i)));
    }
    printf("%lli\n",tree.query(0,0,n,n));
    return 0;
}