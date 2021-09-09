#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll mod;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int f,k;
    cin>>f>>k>>mod;
    vector<pii> arr(f);
    for(int i=0;i<f;i++)cin>>arr[i].first>>arr[i].second;
    set<vector<int>> cnter;
    for(int i=1;i<(1<<f);i++){
        vector<int> weights,gems;
        for(int j=0;j<f;j++){
            if(i&(1<<j)){
                weights.push_back(arr[j].first);
                gems.push_back(arr[j].second);
            }
        }
        sort(weights.begin(),weights.end()),sort(gems.begin(),gems.end());
        if(sz(weights)==1||weights.back()>=weights[sz(weights)-2]*2){
            cnter.insert(gems);
        }
    }
    printf("%lli\n",sz(cnter)%mod);
    return 0;
}