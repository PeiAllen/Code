#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<ll> ways;
ll cost[41];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    int half=n/2;
    ll ans=0;
    for(int i=0;i<(1<<half);i++){
        ll tot=0;
        for(int j=0;j<half;j++){
            if(i&(1<<j)){
                tot+=cost[j];
            }
        }
        ways.push_back(tot);
    }
    sort(ways.begin(),ways.end());
    int oth=n-half;
    for(int i=0;i<(1<<oth);i++){
        ll tot=0;
        for(int j=0;j<oth;j++){
            if(i&(1<<j)){
                tot+=cost[j+half];
            }
        }
        ans+=upper_bound(ways.begin(),ways.end(),m-tot)-ways.begin();
    }
    printf("%lli\n",ans);
    return 0;
}