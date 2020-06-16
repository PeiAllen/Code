#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
ll height[MAXN];
ll dp[MAXN];
ll psa[MAXN];
ll calc(int point, ll i){
    return dp[point]-psa[point]+height[point]*height[point]-height[point]*i*(ll)2;
}
struct lichao{
    int t[2*MAXN];
    void update(int ind, int le, int ri, int point){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        bool lef=calc(point,le)<=calc(t[ind],le);
        bool mi=calc(point,mid)<=calc(t[ind],mid);
        if(mi)swap(point,t[ind]);
        if(le==ri)return;
        if(mi==lef)update(right,mid+1,ri,point);
        else update(left,le,mid,point);
    }
    ll query(int ind, int le, int ri, int i){
        if(le>i||ri<i)return LLONG_MAX;
        if(le==ri)return calc(t[ind],i);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return min({calc(t[ind],i),query(left,le,mid,i),query(right,mid+1,ri,i)});
    }
}tree;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cin>>psa[0];
    for(int i=1;i<n;i++){
        cin>>psa[i];
        psa[i]+=psa[i-1];
        dp[i]=tree.query(0,0,1e6,height[i])+psa[i-1]+height[i]*height[i];
        tree.update(0,0,1e6,i);
    }
    printf("%lli\n",dp[n-1]);
    return 0;
}