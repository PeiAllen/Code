#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e4+1;
pii arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    priority_queue<pii> q;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
        if(arr[i].first>=x){
            q.push({arr[i].first+arr[i].second*m,i});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[j].first+arr[j].second*(i-1)<x&&arr[j].first+arr[j].second*i>=x){
                q.push({arr[j].first+arr[j].second*m,j});
            }
        }
        for(int j=1;j<=k&&sz(q);j++){
            int cur=q.top().second;
            q.pop();
            arr[cur].first-=x;
            if(arr[cur].first+arr[cur].second*i>=x)q.push({arr[cur].first+arr[cur].second*m,cur});
        }
    }
    int ma=INT_MIN;
    for(int i=1;i<=n;i++){
        ma=max(ma,arr[i].first+arr[i].second*m);
    }
    printf("%d\n",ma);
    return 0;
}