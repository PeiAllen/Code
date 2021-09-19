#include "bits/stdc++.h"
using namespace std;
using pii = pair<int,int>;
using ll=long long;
template<typename T>
int sz(const T &a){return int(a.size());}
struct slopefunc{
    priority_queue<pair<ll,ll>> q;
    ll m,b;
    slopefunc(){
        q={};
        m=0,b=0;
    }
    void add(slopefunc a){
        while(sz(a.q)){
            q.push(a.q.top());
            a.q.pop();
        }
        m+=a.m,b+=a.b;
    }
};
int k;
vector<int> lol(1000000,2);
vector<vector<int>> pain(1000,vector<int>(1000,2));
map<int,pair<pii,ll>> pain2;
int main(){// i dont think this is intended LOL
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll p,w,d;
    slopefunc cur=slopefunc();
    pain2[2]={{2,3},3};
    for(int i=0;i<n;i++){
        cin>>p>>w>>d;
        slopefunc te=slopefunc();
        te.m=w;
        te.b=-(p+d)*w;
        te.q.push({p+d,w});
        te.q.push({p-d,w});
        cur.add(te);
    }
    while(cur.m>0){
        ll needed=min(cur.q.top().second,cur.m);
        cur.m-=needed;
        cur.b+=(needed*cur.q.top().first);
        cur.q.pop();
    }
    printf("%lli\n",cur.b);
    return 0;
}