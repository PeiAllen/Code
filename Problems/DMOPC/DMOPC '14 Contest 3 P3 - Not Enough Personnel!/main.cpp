#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
pair<int,string> current[500];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>current[i].second>>current[i].first;
    }
    stable_sort(current,current+n,[&](auto lhs, auto rhs){
        return lhs.first<rhs.first;
    });
    int q;
    cin>>q;
    int v,d;
    while(q--){
        cin>>v>>d;
        int ind=lower_bound(current,current+n,pair<int,string>{v,""})-current;
        if(ind<n&&current[ind].first<=v+d){
            cout<<current[ind].second<<"\n";
        }
        else cout<<"No suitable teacher!\n";
    }
    return 0;
}