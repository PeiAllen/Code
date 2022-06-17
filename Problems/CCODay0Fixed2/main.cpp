#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
pii arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int totalsum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        totalsum+=arr[i].second;
    }
    sort(arr,arr+n);
    int ptr=0;
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        while(ptr<n&&arr[ptr].first<=i){
            q.push(arr[ptr].second);
            ptr++;
        }
        if(sz(q)){
            totalsum-=q.top();
            q.pop();
        }
    }
    printf("%d\n",totalsum);
    return 0;
}