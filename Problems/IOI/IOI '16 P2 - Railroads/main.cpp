#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+2;
ll deg[MN];//negative means needs in edges, positive means needs outedges. (add if getting a in edge)(subtract if getting a out edge) (in-out)
long long plan_roller_coaster(int n, int s[], int t[]){
    vector<ll> vals={1};
    deg[0]=1;
    for(int i=0;i<n;i++)vals.push_back(s[i]),vals.push_back(t[i]);
    sort(vals.begin(),vals.end()),vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=1;i<sz(vals)-1;i++)deg[i]=0;
    deg[sz(vals)-1]=-1;
    for(int i=0;i<n;i++)deg[lower_bound(vals.begin(),vals.end(),s[i])-vals.begin()]--,deg[lower_bound(vals.begin(),vals.end(),t[i])-vals.begin()]++;
    ll ans=0,edgecnt=0;//(out-in)(from left)
    for(int i=0;i<sz(vals);i++){
        if(edgecnt<0)ans+=abs(edgecnt)*(vals[i]-vals[i-1]);
        edgecnt+=deg[i];
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a[4]={1,4,5,6},b[4]={7,3,8,6};
    printf("%lli\n",plan_roller_coaster(4, a,b));
    return 0;
}