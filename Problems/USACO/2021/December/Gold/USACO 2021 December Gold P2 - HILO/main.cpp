#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
int loc[MN];
vector<int> insertinto[MN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    set<pii> te;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        loc[arr[i]]=i;
        auto it=te.lower_bound({arr[i],i});
        if(it!=te.begin())insertinto[prev(it)->second].push_back(i);
        else insertinto[0].push_back(i);
        te.insert({arr[i],i});
    }
    set<int> lolocations;
    set<pii> words;
    int am=0;
    auto insert=[&](pii a){
        auto it=words.lower_bound(a);
        if(it!=words.end()&&it!=words.begin()&&it->second==0&&prev(it)->second==1)am--;
        if(a.second==1&&it!=words.end()&&it->second==0)am++;
        if(a.second==0&&it!=words.begin()&&prev(it)->second==1)am++;
        words.insert(a);
    };
    auto erase=[&](pii a){
        auto it=words.lower_bound(a);
        if(it!=words.begin()&&it->second==0&&prev(it)->second==1)am--;
        if(next(it)!=words.end()&&it->second==1&&next(it)->second==0)am--;
        if(it!=words.begin()&&next(it)!=words.end()&&next(it)->second==0&&prev(it)->second==1)am++;
        words.erase(a);
    };
    for(auto x:insertinto[0]){
        insert({x,1});
    }
    printf("%d\n",am);
    for(int i=1;i<=n;i++){
        erase({loc[i],1});
        insert({loc[i],0});
        auto it=lolocations.lower_bound(loc[i]);
        while(it!=lolocations.end()){
            erase({*it,0});
            it++;
        }
        lolocations.erase(lolocations.lower_bound({loc[i]}),lolocations.end());
        lolocations.insert(loc[i]);
        for(auto x:insertinto[loc[i]]){
            insert({x,1});
        }
        printf("%d\n",am);
    }
    return 0;
}