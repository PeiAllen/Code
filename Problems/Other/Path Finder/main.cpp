#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
set<pii> gone[MAXN];
set<pii> ngone[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int a,b;
    for(int i=1;i<=n;i++){
        ngone[i].insert({1,m});
    }
    for(int i=0;i<k;i++){
        cin>>a>>b;
        auto it=ngone[a].lower_bound({b,m+1});
        it--;
        pii te=*it;
        if(b-1>=te.first)ngone[a].insert({te.first,b-1});
        if(b+1<=te.second)ngone[a].insert({b+1,te.second});
        ngone[a].erase(te);
    }
    gone[1].insert(*ngone[1].begin());
    queue<pair<int,pii>> q;
    q.push({1,*ngone[1].begin()});
    ngone[1].erase(ngone[1].begin());
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        if(cur.first==n&&cur.second.second==m){
            printf("YES\n");
            return 0;
        }
        for(int i=-1;i<=1;i+=2){
            if(cur.first+i>=1&&cur.first+i<=n){
                vector<pii> togo;
                auto it=ngone[cur.first+i].lower_bound({cur.second.first,m+1});
                if(it!=ngone[cur.first+i].begin())it--;
                while(it!=ngone[cur.first+i].end()&&it->second<cur.second.first)it++;
                while(it!=ngone[cur.first+i].end()&&it->first<=cur.second.second){
                    togo.push_back(*it);
                    it++;
                }
                for(auto x:togo){
                    gone[cur.first+i].insert(x);
                    ngone[cur.first+i].erase(x);
                    q.push({cur.first+i,x});
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}