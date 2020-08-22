#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
ll n;
ll needed;
ll sqr;
ll oth;
ll cnt(ll a){
    ll ans=0;
    ll prev=n/1;
    for(ll i=2;i<=sqr;i++){
        ll cur=n/i;
        if(prev<=a+1){
            return ans+prev;
        }
        ll st=n%prev;
        if(st<=a)ans+=min(prev-cur,(a-st)/(i-1)+1);
        prev=cur;
    }
    ans+=min(a+1,oth);
    for(ll i=a+2;i<=oth;i++){
        if(n%i<=a)ans++;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    needed=(n+1)/2;
    ll lo=0,hi=n;
    sqr=sqrt(n);
    oth=n/sqr;
    while(lo!=hi){
        ll mid=(lo+hi)/2;
        ll te=cnt(mid);
        if(te==needed){
            printf("%lli\n",mid);
            return 0;
        }
        if(te>needed)hi=mid;
        else lo=mid+1;
    }
    printf("%lli\n",lo);
    return 0;
}