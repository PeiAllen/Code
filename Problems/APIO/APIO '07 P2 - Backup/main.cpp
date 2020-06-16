#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+2;
ll arr[MAXN];
pair<ll,pii> dll[MAXN];
bool bad[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i>1)q.push({arr[i]-arr[i-1],i}),dll[i]={arr[i]-arr[i-1],{(i-1>=2?i-1:0),(i+1<=n?i+1:0)}};
    }
    dll[0].first=1e16;
    ll totsum=0;
    for(int i=1;i<=k;i++){
        auto cur=q.top();
        q.pop();
        if(!bad[cur.second]){
            totsum+=cur.first;
            dll[cur.second].first=dll[dll[cur.second].second.first].first+dll[dll[cur.second].second.second].first-cur.first;
            bad[dll[cur.second].second.first]=true,bad[dll[cur.second].second.second]=true;
            dll[cur.second].second={dll[dll[cur.second].second.first].second.first,dll[dll[cur.second].second.second].second.second};
            q.push({dll[cur.second].first,cur.second});
            if(dll[cur.second].second.first)dll[dll[cur.second].second.first].second.second=cur.second;
            if(dll[cur.second].second.second)dll[dll[cur.second].second.second].second.first=cur.second;
        }
        else i--;
    }
    printf("%lli\n",totsum);
    return 0;
}