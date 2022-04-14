#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> arr={"0","1"};
    for(int i=2;i<=n;i++){
        vector<string> te=arr;
        reverse(te.begin(),te.end());
        arr.insert(arr.end(),te.begin(),te.end());
        for(int j=0;j<sz(arr);j++){
            arr[j].push_back((j<sz(te)?'0':'1'));
        }
    }
    for(auto x:arr)printf("%s\n",x.c_str());
    return 0;
}