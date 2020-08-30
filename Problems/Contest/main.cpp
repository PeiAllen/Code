#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e6+1;
const ll mod=1e9+7;
ll x[MAXN],y[MAXN],edge[MAXN],wei[MAXN],edgeweight[MAXN];
multiset<ll> weights[MAXN+1][2];
const ll maxw=1e9;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("circular_circles_input (1).txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int n,m,e,k;
        cin>>n>>m>>e>>k;
        for(int i=0;i<k;i++){
            cin>>x[i];
        }
        for(int i=0;i<n+1;i++)weights[i][0]=multiset<ll>(),weights[i][1]=multiset<ll>();
        ll a,b,c;
        cin>>a>>b>>c;
        for(int i=k;i<n;i++){
            x[i]=(a*x[i-2]+b*x[i-1]+c)%m;
        }
        for(int i=0;i<k;i++){
            cin>>y[i];
        }
        cin>>a>>b>>c;
        for(int i=k;i<n;i++){
            y[i]=(a*y[i-2]+b*y[i-1]+c)%m;
        }
        for(int i=0;i<k;i++){
            cin>>edge[i];
        }
        cin>>a>>b>>c;
        for(int i=k;i<e;i++){
            edge[i]=(a*edge[i-2]+b*edge[i-1]+c)%(n*m+n);
        }
        for(int i=0;i<k;i++){
            cin>>wei[i];
        }
        cin>>a>>b>>c;
        for(int i=k;i<e;i++){
            wei[i]=(a*wei[i-2]+b*wei[i-1]+c)%(maxw);
        }
        for(int i=0;i<n;i++)if(x[i]>y[i])swap(x[i],y[i]);
        multiset<ll> bigcircle;
        for(int i=0;i<n*m+n;i++){
            edgeweight[i]=1;
            if(i/m<n)weights[i/m][i-(i/m*m)>=x[i/m]&&i-(i/m*m)<y[i/m]].insert(1);
            else bigcircle.insert(1);
        }
        ll prod=1;
        ll sum=n*m+n-(n+1);
        int cnt=1;
        for(int i=0;i<n;i++){
            if(x[i]!=y[i])bigcircle.insert(1),cnt++;
        }
        for(int i=0;i<e;i++){
            int circind=edge[i]/m;
            if(circind<n) {
                int side=edge[i]-(edge[i]/m*m)>=x[circind]&&edge[i]-(edge[i]/m*m)<y[circind];
                if(sz(weights[circind][!side])==0){
                    sum = (sum + *weights[circind][side].rbegin()) % mod;
                    sum = (((sum - edgeweight[edge[i]]) % mod) + mod) % mod;
                    sum = (sum + wei[i]) % mod;
                    weights[circind][side].erase(weights[circind][side].find(edgeweight[edge[i]]));
                    weights[circind][side].insert(wei[i]);
                    edgeweight[edge[i]] = wei[i];
                    sum = (((sum - *weights[circind][side].rbegin()) % mod) + mod) % mod;
                }
                else {
                    sum = (sum + max(*weights[circind][0].rbegin(),*weights[circind][1].rbegin())) % mod;
                    sum = (sum + *bigcircle.rbegin()) % mod;
                    sum = (((sum - edgeweight[edge[i]]) % mod) + mod) % mod;
                    sum = (sum + wei[i]) % mod;
                    bigcircle.erase(bigcircle.find(min(*weights[circind][0].rbegin(),*weights[circind][1].rbegin())));
                    weights[circind][side].erase(weights[circind][side].find(edgeweight[edge[i]]));
                    edgeweight[edge[i]] = wei[i];
                    weights[circind][side].insert(wei[i]);
                    bigcircle.insert(min(*weights[circind][0].rbegin(),*weights[circind][1].rbegin()));
                    sum = (((sum - max(*weights[circind][0].rbegin(),*weights[circind][1].rbegin())) % mod) + mod) % mod;
                    sum = (((sum - *bigcircle.rbegin()) % mod) + mod) % mod;
                }
            }
            else{
                sum = (sum + *bigcircle.rbegin()) % mod;
                sum = (((sum - edgeweight[edge[i]]) % mod) + mod) % mod;
                sum = (sum + wei[i]) % mod;
                bigcircle.erase(bigcircle.find(edgeweight[edge[i]]));
                edgeweight[edge[i]] = wei[i];
                bigcircle.insert(wei[i]);
                sum = (((sum - *bigcircle.rbegin()) % mod) + mod) % mod;
            }
            prod = prod * sum % mod;
        }
        printf("Case #%d: %lli\n",cs,prod);
        cs++;
    }
    return 0;
}