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
    int n,s,m;
    cin>>n>>s>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int s=1;i<=n;i++){
        for(int m=1;m<=n;m++){
            
        }
    }
    int moves=0;
    while(1){
        if(arr[s]==m){
            printf("magic\n%d\n",moves);
            return 0;
        }
        else if(s<=0){
            printf("left\n%d\n",moves);
            return 0;
        }
        else if(s>n){
            printf("right\n%d\n",moves);
            return 0;
        }
        else if(gone[s]){
            printf("cycle\n%d\n",moves);
            return 0;
        }
            gone[s]=true;
            s=arr[s]+s;
            moves++;
    }

    return 0;
}