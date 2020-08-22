#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll fix(ll a){return (a%mod+mod)%mod;}
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
pair<pll,pll> coords[11];
vector<ll> xcoords,ycoords;
multiset<ll> limits[24];
ll val[11];
vector<int> toinsert[24][24];
vector<int> toerase[24][24];
ll h,w,m;
int n;
ll ways(){
    ll last=1;
    ll ans=1;
    for(int i=0;i<sz(xcoords);i++){
        ll dis=xcoords[i]-last;
        for(int j=0;j+1<sz(ycoords);j++){
            ans=ans*fp(*limits[j].begin(),dis*(ycoords[j+1]-ycoords[j]))%mod;
            for(auto x:toinsert[i][j])limits[j].insert(val[x]);
            for(auto x:toerase[i][j])limits[j].erase(limits[j].find(val[x]));
        }
        last=xcoords[i];
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>h>>w>>m>>n;
        xcoords=vector<ll>(),ycoords=vector<ll>();
        xcoords.push_back(1);
        xcoords.push_back(h+1);
        ycoords.push_back(1);
        ycoords.push_back(w+1);
        for(int i=0;i<n;i++){
            cin>>coords[i].first.first>>coords[i].first.second>>coords[i].second.first>>coords[i].second.second>>val[i];
            xcoords.push_back(coords[i].first.first);
            xcoords.push_back(coords[i].second.first+1);
            ycoords.push_back(coords[i].first.second);
            ycoords.push_back(coords[i].second.second+1);
        }
        sort(xcoords.begin(),xcoords.end());
        xcoords.erase(unique(xcoords.begin(),xcoords.end()),xcoords.end());
        sort(ycoords.begin(),ycoords.end());
        ycoords.erase(unique(ycoords.begin(),ycoords.end()),ycoords.end());
        for(int i=0;i<sz(xcoords);i++)for(int j=0;j<sz(ycoords);j++)toinsert[i][j]=vector<int>(),toerase[i][j]=vector<int>();
        for(int i=0;i<sz(ycoords);i++)limits[i]=multiset<ll>(),limits[i].insert(m);
        for(int i=0;i<n;i++){
            int x=lower_bound(xcoords.begin(),xcoords.end(),coords[i].first.first)-xcoords.begin();
            int yst=lower_bound(ycoords.begin(),ycoords.end(),coords[i].first.second)-ycoords.begin();
            int yen=lower_bound(ycoords.begin(),ycoords.end(),coords[i].second.second+1)-ycoords.begin();
            for(int j=yst;j<yen;j++)toinsert[x][j].push_back(i);
            x=lower_bound(xcoords.begin(),xcoords.end(),coords[i].second.first+1)-xcoords.begin();
            for(int j=yst;j<yen;j++)toerase[x][j].push_back(i);
        }
        ll ans=0;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    val[j]--;
                }
            }
            ans=fix(ans+(__builtin_popcount(i)%2?-1:1)*ways());
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    val[j]++;
                }
            }
        }
        printf("%lli\n",ans);
    }
    return 0;
}