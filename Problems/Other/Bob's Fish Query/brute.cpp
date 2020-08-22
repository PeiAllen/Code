#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    multiset<ll> weights;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        weights.insert(a);
    }
    int q;
    cin>>q;
    ll b,c;
    while(q--){
        cin>>a>>b;
        if(a==1){
            cin>>c;
            multiset<ll> te;
            for(auto x:weights)te.insert(x);
            int am=0;
            while(b<c){
                auto it=te.lower_bound(b);
                if(it==te.begin()){
                    am=-1;
                    break;
                }
                it--;
                b+=*it;
                te.erase(it);
                am++;
            }
            printf("%d\n",am);
        }
        else if(a==2){
            weights.insert(b);
        }
        else{
            weights.erase(weights.find(b));
        }
    }
    return 0;
}