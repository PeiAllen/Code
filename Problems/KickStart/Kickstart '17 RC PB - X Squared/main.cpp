#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
string arr[56];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            arr[i].resize(n);
            for(int j=0;j<n;j++)cin>>arr[i][j];
        }
        int oneam=0;
        set<pii> onex;
        set<string> stff;
        bool work=true;
        for(int i=0;i<n&&work;i++){
            int cnt=0;
            int last=-1;
            for(int j=0;j<n;j++)if(arr[i][j]=='X')cnt++,last=j;
            if(cnt==1){
                oneam++;
                onex.insert({i,last});
            }
            else if(cnt!=2)work=false;
            else stff.insert(arr[i]);
        }
        if(oneam!=1)work=false;
        oneam=0;
        for(int i=0;i<n&&work;i++){
            int cnt=0;
            int last=0;
            for(int j=0;j<n;j++)if(arr[j][i]=='X')cnt++,last=j;
            if(cnt==1){
                oneam++;
                onex.insert({last,i});
            }
            else if(cnt!=2)work=false;
        }
        if(oneam==1&&work&&sz(onex)==1&&sz(stff)==n/2)printf("Case #%d: POSSIBLE\n",cs);
        else printf("Case #%d: IMPOSSIBLE\n",cs);
        cs++;
    }
    return 0;
}