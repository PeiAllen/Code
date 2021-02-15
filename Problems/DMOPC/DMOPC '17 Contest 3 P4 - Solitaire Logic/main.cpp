#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+2;
int low[MN][2],high[MN][2];//lowest and highest position that each number can be on each row.
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    set<int> nums={0,2*n+1};
    low[2*n+1][0]=low[2*n+1][1]=high[2*n+1][0]=high[2*n+1][1]=n+1;
    int a,b,c,d;
    while(q--){
        cin>>a>>b;
        if(a==1){
            cin>>c>>d;
            b--;
            nums.insert(d);
            low[d][b]=high[d][b]=c;
            low[d][!b]=d-c,high[d][!b]=d-c+1;
        }
        else{
            if(nums.count(b)){
                printf("1\n");
                continue;
            }
            auto it=nums.lower_bound(b);
            int larger=*it,smaller=*prev(it,1);
            int ans=0;
            for(int i=0;i<2;i++){
                int left=max(low[smaller][i]+1,high[larger][i]-(larger-b));
                int right=min(high[larger][i]-1,low[smaller][i]+(b-smaller));
                ans+=right-left+1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}