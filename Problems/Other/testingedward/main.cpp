#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
int am[5];
bool work(int ma){

}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0;i<5;i++){
        cin>>am[i];
    }
    int lo=0,hi=100;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    return 0;
}