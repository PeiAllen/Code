#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
unordered_map<int,vector<int>> locs;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int> st,sm;
    int mostleft=n+1;
    vector<pii> apps;
    for(int i=n;i>=1;i--){
        while(sz(sm)&&arr[sm.back()]>arr[i])sm.pop_back();
        while(sz(st)&&arr[st.back()]<arr[i]){
            locs[arr[st.back()]-st.back()].pop_back();
            st.pop_back();
        }
        int limit=(sz(sm)?sm.back():n+1);
        if(locs.count(arr[i]-i)&&sz(locs[arr[i]-i])){
            int ind=locs[arr[i]-i].back();
            if(ind<min(mostleft,limit)){
                mostleft=ind;
                apps.push_back({i,ind});
            }
        }
        sm.push_back(i);
        st.push_back(i);
        locs[arr[i]-i].push_back(i);
    }
    reverse(apps.begin(),apps.end());
    printf("%d\n",sz(apps));
    for(auto x:apps)printf("%d %d\n",x.first,x.second);
    return 0;
}