#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e3+1;
map<pair<pll,pair<ll,pll>>,ll> cnt;
pll arr[MAXN];
pll mf(ll num, ll den){
    if(den<0)den*=-1,num*=-1;
    if(num==0)den=-1;
    else if(den==0)num=-1;
    else{
        ll gc=__gcd(abs(num),abs(den));
        num/=gc,den/=gc;
    }
    return {num,den};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        for(int j=0;j<i;j++){
            pll slope=mf(arr[i].second-arr[j].second,arr[i].first-arr[j].first);
            ll dis=(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
            pll inter;
            pll lbp=arr[i];
            if(arr[j].first<lbp.first||(arr[j].first==lbp.first&&arr[j].second<lbp.second))lbp=arr[j];
            if(slope.first==0)inter={lbp.first,0};
            else if(slope.second==0)inter={lbp.second,0};
            else{
                inter={-slope.second,slope.first};
                inter.first=inter.first*lbp.first-lbp.second*inter.second;
                inter=mf(inter.first,inter.second);
            }
            ans+=cnt[{slope,{dis,inter}}];
            cnt[{slope,{dis,inter}}]++;
        }
    }
    printf("%lli\n",ans/2);
    return 0;
}