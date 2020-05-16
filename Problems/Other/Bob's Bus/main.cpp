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
        //cin>>a;
        if(1) {
            lli madist = 0;
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
            if (sz(used)) {
                for (auto x = next(used.begin(), 1); x != used.end(); x++) {
                    auto pre=prev(x,1);
                    lli te=(x->first+pre->first)/2;
                    for(lli j=-1;j<=1;j++) {
                        for(lli k=1;k<=2;k++) {
                            lli dis = check({te+j,k});
                            if (dis > madist||(dis==madist&&pll{(te+j),k}<loc)) {
                                madist = dis;
                                loc = {(te+j), k};
                            }
                        }
                    }
                }
            }
            else{
                loc={1,1};
            }
            sit[i]=loc;
            used.insert(loc);
            printf("%lli %lli\n",loc.first,loc.second);
        }
        else{
            cin>>p;
            used.erase(sit[p]);
        }
    }
    return 0;
}