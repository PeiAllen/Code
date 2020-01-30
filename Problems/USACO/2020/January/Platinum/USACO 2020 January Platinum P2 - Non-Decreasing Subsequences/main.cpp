#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int MAXN=5e4+1;
const int MAXQ=2e5+1;
int n,k,q;
int arr[MAXN];
pair<pii,int> queries[MAXQ];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>queries[i].first.first>>queries[i].first.second;
        queries[i].second=i;
    }
    sort(queries,queries+q,[](auto & lhs, auto & rhs){
        if(lhs.first.second==rhs.first.second)return lhs.first.first<rhs.first.first;
        return lhs.first.second<rhs.first.second;
    });
    calc(0,q);
    return 0;
}