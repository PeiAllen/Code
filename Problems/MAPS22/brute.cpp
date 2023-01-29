#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=201;
int arr[MN];
vector<int> adj[MN];
bool gone[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    arr[0]=1e9,arr[n+1]=1e9;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int kek=1;kek<=n;kek++){
        for(int m=-(n+3);m<=n+3;m++){
            for(int i=1;i<=n;i++)gone[i]=false;
            int moves=0;
            int s=kek;
            while(1){
                if(s<=0){
                    break;
                }
                else if(s>n){
                    break;
                }
                else if(arr[s]==m){
                    ans++;
                    break;
                }
                else if(gone[s]){
                    break;
                }
                    gone[s]=true;
                    s=arr[s]+s;
                    moves++;
            }
        }
    }
   printf("%d\n",ans);

    return 0;
}