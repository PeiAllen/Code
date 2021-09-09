#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=51;
string arr[MN];
int rown[MN],coln[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("xs_and_os_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        int best=INT_MAX,am=0;
        for(int i=0;i<n;i++){
            bool bad=false;
            int needed=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]=='.')needed++;
                if(arr[i][j]=='O')bad=true;
            }
            if(!bad){
                if(needed<best)best=needed,am=1;
                else if(needed==best)am++;
                rown[i]=needed;
            }
            else rown[i]=INT_MAX;
        }
        for(int i=0;i<n;i++){
            bool bad=false;
            int needed=0;
            for(int j=0;j<n;j++){
                if(arr[j][i]=='.')needed++;
                if(arr[j][i]=='O')bad=true;
            }
            if(!bad){
                if(needed<best)best=needed,am=1;
                else if(needed==best)am++;
                coln[i]=needed;
            }
            else coln[i]=INT_MAX;
        }
        if(best==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(arr[i][j]=='.'&&rown[i]==1&&coln[j]==1)am--;
                }
            }
        }
        if(best==INT_MAX)printf("Case #%d: Impossible\n",cs);
        else printf("Case #%d: %d %d\n",cs,best,am);
    }
    return 0;
}