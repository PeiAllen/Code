#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+2;
pair<lli,int> arr[MAXN];
lli peeps[MAXN];
lli ans[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    for(int j=0;j<n;j++){
        cin>>peeps[j];
    }
    sort(arr,arr+n+1);
    sort(peeps,peeps+n);
    multiset<int> diffs;
    for(int i=0;i<n;i++){
        diffs.insert(max(arr[i+1].first-peeps[i],(lli)0));
    }
    ans[arr[0].second]=*diffs.rbegin();
    for(int i=1;i<=n;i++){
        diffs.insert(max(arr[i-1].first-peeps[i-1],(lli)0));
        diffs.erase(diffs.find(max(arr[i].first-peeps[i-1],(lli)0)));
        ans[arr[i].second]=*diffs.rbegin();
    }
    for(int i=0;i<=n;i++)printf("%lli ",ans[i]);
    return 0;
}