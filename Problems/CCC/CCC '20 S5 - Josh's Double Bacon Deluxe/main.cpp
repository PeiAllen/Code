#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
double psa[MN];
vector<int> locs[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i],locs[arr[i]].push_back(i);
    psa[1]=double(1)/double(n);
    for(int i=2;i<=n;i++){
        psa[i]=psa[i-1];
        if(locs[arr[i]].back()==i&&locs[arr[i]][0]!=1){
            int last=0;
            int am=sz(locs[arr[i]]);
            double dp=0;
            for(auto x:locs[arr[i]]){
                dp+=(psa[x]-psa[last])*am;
                am--,last=x;
            }
            psa[i]+=dp/(n-i+1);
        }
    }
    printf("%.9f\n",1-(psa[n]-psa[n-1]));
    return 0;
}