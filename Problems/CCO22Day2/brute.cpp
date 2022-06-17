#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=2001;
struct dsu{
    pii t[MN];
    void reset(int n){
        for(int i=0;i<=n;i++)t[i]={i,1};
    }
    int find(int a){
        if(t[a].first==a)return a;
        return t[a].first=find(t[a].first);
    }
    bool uni(int a, int b){
        int ap=find(a),bp=find(b);
        if(ap==bp)return false;
        if(t[ap].second<t[bp].second)swap(ap,bp);
        t[ap].second+=t[bp].second;
        t[bp].first=ap;
        return true;
    }
}dsu1,dsu2;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    ll k;
    cin>>n>>a>>b>>k;
    if(k==0)return 0*printf("0\n");
    vector<pair<ll,pii>> edgesa,edgesb;
    int x1,y1;
    ll z1;
    for(int i=1;i<=a;i++){
        cin>>x1>>y1>>z1;
        edgesa.push_back({z1,{x1,y1}});
    }
    sort(edgesa.begin(),edgesa.end());
    for(int i=1;i<=b;i++){
        cin>>x1>>y1>>z1;
        edgesb.push_back({z1,{x1,y1}});
    }
    sort(edgesb.begin(),edgesb.end());
    dsu1.reset(n);
    dsu2.reset(n);
    ll best=LLONG_MAX;
    for(auto x:edgesb) {
        dsu2.uni(x.second.first,x.second.second);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dsu2.find(i)==dsu2.find(j)){
                    cnt++;
                }
            }
        }
        if(cnt>=k)best=min(best,x.first);
    }
    for(auto x:edgesa){
        dsu1.uni(x.second.first,x.second.second);
        dsu2.reset(n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dsu1.find(i)==dsu1.find(j)){
                    cnt++;
                }
            }
        }
        if(cnt>=k)best=min(best,x.first);
        for(auto y:edgesb){
            dsu2.uni(y.second.first,y.second.second);
            cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(dsu2.find(i)==dsu2.find(j)){
                        cnt++;
                    }
                    else if(dsu1.find(i)==dsu1.find(j)){
                        cnt++;
                    }
                }
            }
            if(cnt>=k)best=min(best,x.first+y.first);
        }
    }
    if(best==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",best);
    return 0;
}