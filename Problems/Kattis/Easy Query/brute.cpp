#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,q,a,b,c,d;
        cin>>n>>q;
        for(int i=0;i<n;i++)cin>>arr[i];
        while(q--){
            cin>>a>>b>>c>>d;
            a--,b--,c--,d--;
            vector<int> te(arr+a,arr+b+1);
            sort(te.begin(),te.end());
            int oneor=0,twoor=0,threeor=0;
            for(int i=c;i<=d;i++){
                oneor|=te[i];
                if(i+1<=d&&te[i]==te[i+1])twoor|=te[i];
                if(i+2<=d&&te[i]==te[i+2])threeor|=te[i];
            }
            printf("%lli\n",ll(oneor)+twoor+threeor);
        }
    }
    return 0;
}