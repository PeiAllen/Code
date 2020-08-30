#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
vector<pair<int,ll>> matrix[MAXN];
pair<pii,ll> deq[2*MAXN];
ll val[MAXN];
pair<int,ll> best;
int l,r;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int a,b;
    ll c;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    int curloc=1;
    int type;
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>a>>c;
            val[a]=c;
        }
        else{
            cin>>a>>b>>c;
            for(int j=0;j<sz(matrix[a]);j++){
                if(matrix[a][j].first==b){
                    matrix[a][j].second=c;
                    break;
                }
            }
            for(int j=0;j<sz(matrix[b]);j++){
                if(matrix[b][j].first==a){
                    matrix[b][j].second=c;
                    break;
                }
            }
        }
        best={-1,LLONG_MIN};
        l=0,r=-1;
        for(auto x:matrix[curloc])deq[++r]={{x.first,curloc},x.second};
        while(l<=r){
            int loc=deq[l].first.first,parent=deq[l].first.second;
            ll dist=deq[l].second;
            l++;
            if(val[loc]-dist>best.second)best={loc,val[loc]-dist};
            else if(val[loc]-dist==best.second&&loc<best.first)best={loc,val[loc]-dist};
            for(auto x:matrix[loc])if(x.first!=parent){
                    deq[++r]={{x.first,loc},dist+x.second};
                }
        }
        printf("%d ",best.first);
        curloc=best.first;
    }
    return 0;
}