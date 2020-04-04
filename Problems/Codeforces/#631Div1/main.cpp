#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<int> nums;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)nums.insert(i);
    vector<int> lens;
    int a;
    for(int i=0;i<m;i++){
        cin>>a;
        lens.push_back(a);
    }
    sort(lens.begin(),lens.end(),greater<>());
    return 0;
}