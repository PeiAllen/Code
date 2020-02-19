#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
int arr[MAXN];
int last[MAXN];
vector<int> burgers;
double dp[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        last[arr[i]]=i;
    }
    for(int i=0;i<n;i++){
        if(last[arr[i]]==i)burgers.push_back(arr[i]);
    }
    for(int i=0;i<sz(burgers);i++){

    }
    return 0;
}