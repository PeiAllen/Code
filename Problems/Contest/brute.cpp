#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
vector<int> riffle(vector<int> arr){
    vector<int> fin;
    for(int lptr=0,rptr=sz(arr)/2;lptr<sz(arr)/2||rptr<sz(arr);){
        if(rptr==sz(arr)||(lptr<sz(arr)/2&&arr[lptr]<arr[rptr])){
            fin.push_back(arr[lptr++]);
        }
        else{
            fin.push_back(arr[rptr++]);
        }
    }
    return fin;
}
int ans[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<pair<pii,int>> queries;
    int a,b;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        queries.push_back({{a,b},i});
    }
    sort(queries.begin(),queries.end());
    int ptr=0;
    for(int i=0;ptr<sz(queries);i++){
        assert(i<n);
        while(ptr<sz(queries)&&i==queries[ptr].first.first){
            ans[queries[ptr].second]=arr[queries[ptr].first.second-1];
            ptr++;
        }
        vector<int> te=riffle(arr);
        if(te==arr){
            break;
        }
        arr=te;
    }
    while(ptr<sz(queries)){
        ans[queries[ptr].second]=arr[queries[ptr].first.second-1];
        ptr++;
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}