#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=23;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    vector<pair<pii,int>> trips(n);
    for(int i=0;i<n;i++){
        cin>>trips[i].first.first>>trips[i].first.second>>trips[i].second;
    }
    sort(trips.begin(),trips.end());
    
    if(p==1){

    }
    else{

    }
    return 0;
}