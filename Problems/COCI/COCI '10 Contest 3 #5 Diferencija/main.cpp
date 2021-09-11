#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
ll arr[MN],le[MN],ri[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> st;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        while(sz(st)&&arr[st.back()]<=arr[i]){
            ri[st.back()]=i;
            st.pop_back();
        }
        le[i]=(sz(st)?st.back():-1);
        st.push_back(i);
    }
    while(sz(st))ri[st.back()]=n,st.pop_back();
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=arr[i]*(ri[i]-i)*(i-le[i]);
    }
    for(int i=0;i<n;i++){
        while(sz(st)&&arr[st.back()]>=arr[i]){
            ri[st.back()]=i;
            st.pop_back();
        }
        le[i]=(sz(st)?st.back():-1);
        st.push_back(i);
    }
    while(sz(st))ri[st.back()]=n,st.pop_back();
    for(int i=0;i<n;i++){
        ans-=arr[i]*(ri[i]-i)*(i-le[i]);
    }
    printf("%lli\n",ans);
    return 0;
}