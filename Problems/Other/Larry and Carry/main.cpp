#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=21;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        vector<int> vals;
        for(int j=0;j<n;j++)if(i&(1<<j))vals.push_back(arr[j]);
        bool work=true;
        while(vals.back()&&work){
            int sum=0;
            for(int j=0;j<sz(vals);j++){
                sum+=vals[j]%10;
                if(sum>=10)work=false;
                vals[j]/=10;
            }
        }
        if(work)ans=max(ans,__builtin_popcount(i));
    }
    printf("%d\n",ans);
    return 0;
}