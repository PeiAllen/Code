#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MC=1000;
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q,d,m;
    ll k;
    cin>>k>>q>>d>>m;
    map<ll,vector<ll>> vals;
    ll a;
    for(int i=0;i<d;i++){
        cin>>a;
        vals[a%k].push_back(a);
    }
    while(q--){
        cin>>a;
        bool neg=a<0;
        a=abs(a);
        set<pair<ll,bool>> gone;
        map<pair<pair<ll,bool>,int>,pair<pair<pair<ll,bool>,int>,ll>> from;
        from[{{a,neg},-1}]={{{-1,0},-2},-1};
        set<pair<ll,bool>> poss={{a,neg}};
        int cnt=0;
        bool work=false;
        while(sz(poss)){
            set<pair<ll,bool>> nextposs;
            for(const auto &x:poss){
                ll val=x.first%k;
                if(x.second)val*=-1;
                if(vals.count(val)){
                    ll cheese=0;
                    for(ll y:vals[val]) {
                        cheese++;
                        if(x.second)y*=-1;
                        ll nextval=x.first-y;
                        assert(nextval%k==0);
                        nextval/=k;
                        neg=x.second;
                        if(nextval<0)nextval*=-1,neg^=1;
                        if(!gone.count({nextval,neg})){
                            gone.insert({nextval,neg});
                            if(x.second)y*=-1;
                            from[{{nextval,neg},cnt}]={{x,cnt-1},y};
                            nextposs.insert({nextval,neg});
                        }
                        if(cheese>MC)break;
                    }
                }
                ll reeval=-(k-(x.first%k));
                if(x.second)reeval*=-1;
                if(vals.count(reeval)){
                    ll cheese=0;
                    for(ll y:vals[reeval]) {
                        cheese++;
                        if(x.second)y*=-1;
                        ll nextval=x.first-y;
                        assert(nextval%k==0);
                        nextval/=k;
                        neg = x.second;
                        if(nextval<0)nextval*=-1,neg^=1;
                        if(!gone.count({nextval,neg})){
                            gone.insert({nextval,neg});
                            if(x.second)y*=-1;
                            from[{{nextval,neg},cnt}]={{x,cnt-1},y};
                            nextposs.insert({nextval,neg});
                        }
                        if(cheese>MC)break;
                    }
                }
            }
            poss.swap(nextposs);
            nextposs=set<pair<ll,bool>>();
            if(poss.count({0,0})){
                pair<pair<ll,bool>,ll> cur={{0,0},cnt};
                vector<ll> toprint;
                while(cur.second!=-1){
                    toprint.push_back(from[cur].second);
                    cur=from[cur].first;
                }
                for(int i=0;i<sz(toprint);i++)printf("%lli%c",toprint[i]," \n"[i==sz(toprint)-1]);
                work=true;
                break;
            }
            if(poss.count({0,1})){
                pair<pair<ll,bool>,ll> cur={{0,1},cnt};
                vector<ll> toprint;
                while(cur.second!=-1){
                    toprint.push_back(from[cur].second);
                    cur=from[cur].first;
                }
                for(int i=0;i<sz(toprint);i++)printf("%lli%c",toprint[i]," \n"[i==sz(toprint)-1]);
                work=true;
                break;
            }
            cnt++;
            if(cnt>100)break;
        }
        if(!work)printf("IMPOSSIBLE\n");
    }
    return 0;
}