#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
int fight[MN];
int strength[MN];
vector<int> elves[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>fight[i];
    for(int i=0;i<n;i++)cin>>strength[i];
    int a;
    for(int i=0;i<n;i++)cin>>a,elves[fight[i]-1].push_back(a);
    int st=0,am=0;
    for(int cnt=0,i=0;cnt<n;cnt++,i++){
        am+=sz(elves[i])-1;
        while(am<0){
            st=(st-1+n)%n;
            am+=sz(elves[st])-1;
            cnt++;
        }
    }
    set<int> cur;
    int ans=0;
    for(int offset=0,i=st;offset<n;offset++,i=(i+1)%n){
        for(auto x:elves[i])cur.insert(x);
        auto it=cur.lower_bound(strength[i]);
        if(it==cur.end())cur.erase(cur.begin());
        else ans++,cur.erase(it);
    }
    printf("%d\n",ans);
    return 0;
}