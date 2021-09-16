#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    vector<pair<int,pair<pii,pii>>> stores;
    int t,a,b,c,d;
    for(int i=1;i<=q;i++){
        cin>>t>>a;
        if(t==1){
            cin>>b>>c>>d;
            stores.push_back({i,{{a-b,a+b},{c,d}}});
        }
        else if(t==2){
            for(int j=0;j<sz(stores);j++){
                if(stores[j].first==a){
                    stores.erase(stores.begin()+j);
                    break;
                }
            }
        }
        else{
            cin>>b>>c;
            int ans=0;
            for(auto x:stores){
                if(min(x.second.first.second,b)>=max(x.second.first.first,a)&&x.second.second.second<=c)ans=max(ans,x.second.second.first);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}