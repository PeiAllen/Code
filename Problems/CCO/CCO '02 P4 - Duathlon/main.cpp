#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
pair<double,double> speed[21];
const double prec=1e-7;
int n;
double t;
double calc(double r){
    double chetime=r/speed[n].first+(t-r)/speed[n].second;
    double worst=INT_MAX;
    for(int i=1;i<n;i++){
        worst=min(worst,r/speed[i].first+(t-r)/speed[i].second-chetime);
    }
    return worst;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>speed[i].first>>speed[i].second;
    }
    double lo=0,hi=t;
    while((hi-lo)>=prec){
        double mid=(lo+hi)/2;
        if(calc(mid+prec)>=calc(mid))lo=mid;
        else hi=mid-prec;
    }
    if(lo+prec<=t&&calc(lo+prec)>calc(lo))lo+=prec;
    if(calc(lo)<=0-prec)printf("The cheater cannot win.\n");
    else printf("The cheater can win by %.0f seconds with r = %.2fkm and k = %.2fkm.\n",max(0.0,calc(lo)*3600.0),lo,t-lo);
    return 0;
}