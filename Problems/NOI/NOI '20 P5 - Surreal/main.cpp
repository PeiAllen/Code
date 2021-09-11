#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=2e6+1;
pii arr[MN];
bool isleaf(int a){return arr[a].first==0&&arr[a].second==0&&a;}
bool dfs(const vector<int> &nodes){
    if(SZ(nodes)==0)return false;
    vector<int> left,right,leftwl,rightwl;
    for(auto x:nodes){
        if(arr[x].first==0&&arr[x].second==0)return true;
        if(arr[x].second==0)left.push_back(arr[x].first);
        if(arr[x].first==0)right.push_back(arr[x].second);
        //both subtrees have smth, one of nodes must be a leaf, otherwise the empty one will never exist -> infinite, and other side is full, this also covers all cases.
        if(isleaf(arr[x].second)&&arr[x].first)leftwl.push_back(arr[x].first);
        if(isleaf(arr[x].first)&&arr[x].second)rightwl.push_back(arr[x].second);
    }
    return dfs(left)&&dfs(right)&&dfs(leftwl)&&dfs(rightwl);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        vector<int> roots;
        for(int i=0,nodecnt=0;i<m;i++){
            int n;
            cin>>n;
            roots.push_back(nodecnt);
            for(int j=0;j<n;j++,nodecnt++){
                cin>>arr[nodecnt].first>>arr[nodecnt].second;
                if(arr[nodecnt].first)arr[nodecnt].first+=roots.back()-1;
                if(arr[nodecnt].second)arr[nodecnt].second+=roots.back()-1;
            }
        }
        if(dfs(roots))printf("Almost Complete\n");
        else printf("No\n");
    }
    return 0;
}