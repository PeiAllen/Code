#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e2+1;
pii arr[MN];
int n;
map<int,vector<int>> cows;
int fullsquare=0;
int solve(){
    int ans=0;
    cows=map<int,vector<int>>();
    vector<int> xcoords;
    for(int i=0;i<n;i++)xcoords.push_back(arr[i].first),cows[arr[i].first].push_back(arr[i].second);
    sort(xcoords.begin(),xcoords.end()),xcoords.erase(unique(xcoords.begin(),xcoords.end()),xcoords.end());
    for(int i=0;i<sz(xcoords);i++){
        vector<pii> ir;
        set<int> ycoords;
        for(int j=i;j<sz(xcoords);j++){
            for(auto x:cows[xcoords[j]])ir.push_back({x,j}),ycoords.insert(x);
            sort(ir.begin(),ir.end());
            int lam=0,ram=0;
            int l=0,r=-1;
            int length=xcoords[j]-xcoords[i];
            int lastx=INT_MIN;
            for(auto x:ycoords){
                while(l<=r&&ir[l].first<x){
                    if(ir[l].second==i)lam--;
                    if(ir[l].second==j)ram--;
                    l++;
                }
                if(lam&&ram&&(r+1==sz(ir)||ir[r+1].first!=lastx+length+1))ans++;
                while(r+1<sz(ir)&&ir[r+1].first<=x+length){
                    r++;
                    if(ir[r].second==i)lam++;
                    if(ir[r].second==j)ram++;
                    if(lam&&ram&&(r+1==sz(ir)||ir[r+1].first!=ir[r].first))ans++;
                }
                if(lam&&ram)fullsquare+=ir[r].first==x+length;
                lastx=x;
            }
        }
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    int ans=solve();
    for(int i=0;i<n;i++)swap(arr[i].first,arr[i].second);
    ans+=solve();
    printf("%d\n",ans-fullsquare/2+1);
    return 0;
}