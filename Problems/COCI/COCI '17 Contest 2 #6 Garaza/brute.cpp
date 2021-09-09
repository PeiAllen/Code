#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b,c;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            arr[b]=c;
        }
        else{
            int ans=0;
            for(int i=b;i<=c;i++){
                int te=0;
                for(int j=i;j<=c;j++){
                    te=__gcd(te,arr[j]);
                    if(te>1)ans++;
                    else break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}