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
    int n,a;
    cin>>n;
    vector<pii> st;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        pii recent={-1,-1};
        while(sz(st)&&st.back().first<=a){
            ans+=st.back().second;
            recent=st.back();
            st.pop_back();
        }
        if(sz(st))ans+=1;
        if(recent.first==a)st.push_back({a,recent.second+1});
        else st.push_back({a,1});
    }
    printf("%lli\n",ans);
    return 0;
}