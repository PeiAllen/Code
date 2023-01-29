#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
ll lp[MN];
ll divi(ll a,ll b){
    ll ans=1;
    bool good=(a==451);
    for(ll i=2;i*i<=a;i++){
        ll cnt=0;
        while(a%i==0){
            cnt++;
            a/=i;
        }
        // if(good&&cnt>0)printf("%lli %lli\n",i,cnt);
        ans*=(cnt*b+1);
    }
    if(a>1){
        ans*=(1*b+1);
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<ll> pr;
    for (ll i=2; i < MN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j=0; j < (ll)pr.size() && pr[j] <= lp[i] && i*pr[j] < MN; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    vector<ll> ans;
    ans.push_back(1);
    pr.erase(pr.begin());
    
    for(int i=0;i<sz(pr);i++){
        for(int j=i+1;j<sz(pr);j++){
            ll val=pr[i]*pr[j];
            ll curval=val;
            ll power=1;
            while(curval<=m){
                // if(curval==225)printf("wtf %lli %lli\n",power*curval+1,divi(power*curval+1,ll(2)));
                if(curval%divi(power*curval+1,ll(2))==0){
                    ans.push_back(curval);
                }
                power++;
                curval*=val;
            }
        }
        ll val=pr[i];
        ll curval=val;
        ll power=1;
        while(curval<=m){
            if(curval%divi(power*curval+1,ll(1))==0){
               ans.push_back(curval);
            }
            power++;
            curval*=val;
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",upper_bound(ans.begin(),ans.end(),m)-lower_bound(ans.begin(),ans.end(),n));
    return 0;
}