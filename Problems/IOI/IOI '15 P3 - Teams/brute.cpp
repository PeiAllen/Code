#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<pii> ord;
void init(int N, vector<int> A, vector<int> B) {
    for(int i=0;i<N;i++)ord.push_back({A[i],B[i]});
    sort(ord.begin(),ord.end());
}

int can(int M, vector<int> K) {
    for(int i=0;i<M;i++){
        for(int j=1;j<K[i];j++)K.push_back(K[i]);
    }
    sort(K.begin(),K.end());
    int ptr=0;
    multiset<int> arr;
    for(auto x:K){
        while(ptr<sz(ord)&&ord[ptr].first<=x){
            arr.insert(ord[ptr].second);
            ptr++;
        }
        auto it=arr.lower_bound(x);
        if(it==arr.end())return 0;
        arr.erase(it);
    }
    return 1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int gn;
    cin>>gn;
    vector<int> A(gn),B(gn);
    for(int i=0;i<gn;i++)cin>>A[i]>>B[i];
    init(gn,A,B);
    int q;
    cin>>q;
    while(q--){
        int m;
        cin>>m;
        vector<int> K(m);
        for(int i=0;i<m;i++)cin>>K[i];
        printf("%d\n",can(m,K));
    }
    return 0;
}