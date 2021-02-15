#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
bool used[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    priority_queue<pii,vector<pii>,greater<>> q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int> last;
    for(int i=n;i>=1;i--){
        if(!used[arr[i]]){
            last.push_back(i);
            used[arr[i]]=true;
        }
    }
    vector<int> ans;
    int r=-1;
    while(sz(ans)<k){
        while(!used[arr[last.back()]])last.pop_back();
        while(r<last.back()){
            r++;
            q.push({arr[r],r});
        }
        while(!used[q.top().first]||q.top().second<(sz(ans)?ans.back():-1))q.pop();
        ans.push_back(q.top().second);
        used[q.top().first]=false;
        q.pop();
    }
    for(int i=0;i<k;i++){
        printf("%d%c",arr[ans[i]]," \n"[i==k-1]);
    }
    return 0;
}