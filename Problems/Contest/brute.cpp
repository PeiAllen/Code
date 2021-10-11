#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=1001;
int arr[MN];
bool diff[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int p,n,a,b;
    cin>>p>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        a-=1,b-=1;
        diff[a][b]=diff[b][a]=true;
    }
    int ans=0;
    int best=0;
    for(int i=0;i<(1<<n);i++){
        vector<int> used;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                used.push_back(j);
            }
        }
        bool work=true;
        for(auto x:used){
            for(auto y:used){
                if(x!=y){
                    if((arr[x]!=arr[y])==(diff[x][y]))work=false;
                }
            }
        }
        if(work&&SZ(used)>ans){
            ans=max(ans,SZ(used));
            best=i;
        }
    }
    printf("%d\n",ans);
        vector<int> used;
        for(int j=0;j<n;j++){
            if(best&(1<<j)){
               printf("%d ",j);
            }
        }
    return 0;
}