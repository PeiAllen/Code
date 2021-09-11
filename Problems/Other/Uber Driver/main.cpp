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
    int n,l;
    cin>>n>>l;
    vector<pair<int,pii>> points;
    int a,b;
    vector<ll> st,en;
    st.push_back(l);
    en.push_back(0);
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ans+=abs(a-b);
        st.push_back(a);
        en.push_back(b);
    }
    sort(st.begin(),st.end()),sort(en.begin(),en.end());
    for(int i=0;i<sz(st);i++)ans+=abs(st[i]-en[i]);
    printf("%lli\n",ans);
    return 0;
}