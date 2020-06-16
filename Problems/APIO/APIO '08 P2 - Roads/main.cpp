#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e4+1;
vector<pii> normal;
vector<pii> cobble;
pii dsu[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(c==0){
            cobble.push_back({a,b});
        }
        else{
            normal.push_back({a,b});
            uni(a,b);
        }
    }
    vector<pii> used;
    vector<pii> notused;
    for(auto x:cobble){
        if(find(x.first)!=find(x.second)){
            uni(x.first,x.second);
            used.push_back(x);
        }
        else notused.push_back(x);
    }
    if(sz(used)>k){
        printf("no solution\n");
        return 0;
    }
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    for(auto x:used)uni(x.first,x.second);
    for(auto x:notused){
        if(sz(used)<k&&find(x.first)!=find(x.second)){
            uni(x.first,x.second);
            used.push_back(x);
        }
    }
    if(sz(used)!=k){
        printf("no solution\n");
        return 0;
    }
    for(auto x:used){
        printf("%d %d 0\n",x.first,x.second);
    }
    for(auto x:normal){
        if(find(x.first)!=find(x.second)){
            uni(x.first,x.second);
            printf("%d %d 1\n",x.first,x.second);
        }
    }
    return 0;
}