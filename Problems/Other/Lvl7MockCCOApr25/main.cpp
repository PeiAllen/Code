#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e4+1;
pll sit[MAXN];
set<pll> used;
struct comp{
    bool operator()(const pll& lhs, const pll& rhs)const {
        if((lhs.second-lhs.first)==(rhs.second-rhs.first)){
            if(lhs.first==rhs.first)return lhs.second<rhs.second;
            return lhs.first<rhs.first;
        }
        return ((lhs.second-lhs.first))>((rhs.second-rhs.first));
    }
};
set<pll,comp> best[3][3][2];
lli n;
lli check(pll a){
    if(a.first<=0||a.first>n)return -1;
    auto it=used.lower_bound(a);
    auto old=it;
    lli dis=LLONG_MAX;
    for(int i=0;i<2&&it!=used.end();i++){
        dis=min(dis,(it->first-a.first)*(it->first-a.first)+(it->second-a.second)*(it->second-a.second));
        it++;
    }
    it=old;
    for(int i=0;i<2&&it!=used.begin();i++){
        it--;
        dis=min(dis,(it->first-a.first)*(it->first-a.first)+(it->second-a.second)*(it->second-a.second));
    }
    return dis;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    char a;
    int p;
    for(int i=1;i<=m;i++){
//        cin>>a;
//        if(a=='E') {
        if(1){
            lli madist = -1;
            pll loc = {-1, -1};
            for(lli j=1;j<=2;j++){
                auto it=used.begin();
                lli dis = LLONG_MAX;
                for (int l = 0; l < 2 && it != used.end(); l++) {
                    dis = min(dis, (it->first - 1) * (it->first - 1) + (it->second - j) * (it->second - j));
                    it++;
                }
                if (dis&&dis > madist) {
                    madist = dis;
                    loc = {1,j};
                }
            }
            for(lli j=1;j<=2;j++){
                auto it=used.end();
                lli dis = LLONG_MAX;
                for (int l = 0; l < 2 && it != used.begin(); l++) {
                    it--;
                    dis = min(dis, (it->first - n) * (it->first - n) + (it->second - j) * (it->second - j));
                }
                if (dis&&dis > madist) {
                    madist = dis;
                    loc = {n,j};
                }
            }
            for(int x=1;x<=2;x++){
                for(int y=1;y<=2;y++) {
                    for(int par=0;par<=1;par++){
                        if(sz(best[x][y][par])) {
                            lli te = (best[x][y][par].begin()->second + best[x][y][par].begin()->first) / 2;
                            for (lli j = -1; j <= 1; j++) {
                                for (lli k = 1; k <= 2; k++) {
                                    lli dis = check({te + j, k});
                                    if (dis > madist || (dis == madist && pll{(te + j), k} < loc)) {
                                        madist = dis;
                                        loc = {(te + j), k};
                                    }
                                }
                            }
                        }
                    }
                }
            }
            sit[i]=loc;
            auto x=used.lower_bound(loc);
            if(x!=used.end()&&x!=used.begin()){
                auto oth=prev(x,1);
                best[oth->second][x->second][(x->first-oth->first)%2].erase({oth->first,x->first});
            }
            if(x!=used.end()){
                best[loc.second][x->second][(x->first-loc.first)%2].insert({loc.first,x->first});
            }
            if(x!=used.begin()){
                auto oth=prev(x,1);
                assert(*oth<loc);
                best[oth->second][loc.second][(loc.first-oth->first)%2].insert({oth->first,loc.first});
            }
            used.insert(loc);
            printf("%lli %lli\n",loc.first,loc.second);
        }
        else{
            cin>>p;
            au  to it=used.lower_bound(sit[p]);
            assert(*it==sit[p]);
            if(it!=prev(used.end(),1)){
                auto oth=next(it,1);
                best[it->second][oth->second][(oth->first-it->first)%2].erase({it->first,oth->first});
            }
            if(it!=used.begin()){
                auto oth=prev(it,1);
                best[oth->second][it->second][(it->first-oth->first)%2].erase({oth->first,it->first});
            }
            if(it!=prev(used.end(),1)&&it!=used.begin()) {
                auto oth=next(it,1);
                it--;
                best[it->second][oth->second][(oth->first-it->first)%2].insert({it->first,oth->first});
            }
            used.erase(sit[p]);
        }
    }
    return 0;
}