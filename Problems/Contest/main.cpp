#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll arr[MN];
struct data{
    int cnt[19],mi;
    data(){
        mi=INT_MAX;
        for(int i=0;i<19;i++)cnt[i]=0;
    }
};
data mergeleft(const data &a, const data &b){
    if(b.mi==INT_MAX)return a;
    if(a.mi==INT_MAX)return b;
    return
}
struct seg{
    struct node{
        data fl,fr;
        node(){
            fl=data(),fr=data();
        }
    };

}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    return 0;
}