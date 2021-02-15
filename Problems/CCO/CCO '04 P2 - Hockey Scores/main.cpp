#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
pii times[MAXN];
bool done[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        for(int i=0;i<n;i++){
            scanf(" %d-%d",&times[i].first,&times[i].second);
            done[i]=false;
            if(times[i].first<times[i].second)swap(times[i].first,times[i].second);
        }
        sort(times,times+n);
        int cnt=0;
        vector<vector<pii>> ans;
        while(cnt<n){
            pii cur={0,0};
            ans.push_back({});
            for(int i=0;i<n;i++){
                if(!done[i]&&times[i].first>=cur.first&&times[i].second>=cur.second){
                    ans.back().push_back(times[i]);
                    cur=times[i];
                    cnt++;
                    done[i]=true;
                }
            }
        }
        printf("%d\n",sz(ans));
        for(auto x:ans){
            for(auto y:x)printf("%d-%d ",y.first,y.second);
            printf("\n");
        }
    }
    return 0;
}