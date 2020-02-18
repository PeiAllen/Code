#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<pair<lli,pair<pair<lli,int>,pll>>> ships;
lli dist(int a, int b){
    return (ships[a].second.first.first-ships[b].second.first.first)*(ships[a].second.first.first-ships[b].second.first.first)+(ships[a].second.second.first-ships[b].second.second.first)*(ships[a].second.second.first-ships[b].second.second.first)+(ships[a].second.second.second-ships[b].second.second.second)*(ships[a].second.second.second-ships[b].second.second.second);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    set<int> used;
    lli a,b,c,d;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        ships.push_back({d,{{a,i+1},{b,c}}});
    }
    sort(ships.begin(),ships.end(),greater<pair<lli,pair<pair<lli,int>,pll>>>());
    for(int i=0;i<n;i++){
        bool use=true;
        for(int x:used){
            if(dist(i,x)<(ships[i].first+ships[x].first)*(ships[i].first+ships[x].first))use=false;
        }
        if(use)used.insert(i);
    }
    printf("%d\n",sz(used));
    for(int x:used)printf("%d ",ships[x].second.first.second);
    return 0;
}
