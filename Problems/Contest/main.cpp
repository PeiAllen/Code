#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
int arr[MN];
bool solve(int n){
    vector<pii> intervals;
    set<int> vals;
    for(int i=1;i<=n;i++)vals.insert(i);
    int last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            for(int j=last+1;j<i;j++){
                intervals.push_back({min((last==-1?0:arr[last]),arr[i])+1,max((last==-1?0:arr[last]),arr[i])-1});
            }
            vals.erase(arr[i]);
            last=i;
        }
    }
    for(int j=last+1;j<n;j++){
        intervals.push_back({min((last==-1?0:arr[last]),0)+1,max((last==-1?0:arr[last]),0)-1});
    }
    sort(intervals.begin(),intervals.end(),[&](const auto &lhs, const auto &rhs){
        return lhs.second<rhs.second;
    });
    for(auto x:intervals){
        auto it=vals.lower_bound(x.first);
        if(it==vals.end()||*it>x.second)return false;
        vals.erase(it);
    }
    printf("YES\n");
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,a,b;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int tc=0;tc<=q;tc++) {
        if(tc>0) {
            cin >> a >> b;
            arr[a - 1] = b;
        }
        pii largest={0,-1};
        for(int i=0;i<n;i++) {
            if(arr[i]>0)largest = max(largest, {arr[i], i});
        }
        int last = INT_MAX;
        bool done=false;
        for (int i = largest.second; i >= 0; i--) {
            if (arr[i] > 0) {
                if (arr[i] >= last) {
                    printf("NO\n");
                    done=true;
                    break;
                }
                last = arr[i];
            }
        }
        if(done)continue;
        last = INT_MAX;
        for (int i = largest.second; i < n; i++) {
            if (arr[i] > 0) {
                if (arr[i] >= last) {
                    printf("NO\n");
                    done=true;
                    break;
                }
                last = arr[i];
            }
        }
        if(done)continue;
        if (largest.first == n) {
            if (!solve(n))printf("NO\n");
        } else {
            if (largest.second != n - 1 && arr[largest.second + 1] == 0) {
                arr[largest.second + 1] = n;
                if (solve(n)) {
                    arr[largest.second + 1] = 0;
                    continue;
                }
                arr[largest.second + 1] = 0;
            }
            if (largest.second != 0 && arr[largest.second - 1] == 0) {
                arr[largest.second - 1] = n;
                if (solve(n)) {
                    arr[largest.second - 1] = 0;
                    continue;
                }
                arr[largest.second - 1] = 0;
            }
            printf("NO\n");
        }
    }
    return 0;
}