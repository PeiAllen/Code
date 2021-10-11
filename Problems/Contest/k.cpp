#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}
const int MN=1e5+1;
vector<int> am[MN];
int who[MN];
bool carefuldudes[MN];
pii relation[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int p,n,k;
    cin>>p>>n;
    for(int i=1;i<=n;i++){
        cin>>who[i];
        am[who[i]].push_back(i);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>relation[i].first>>relation[i].second;
        carefuldudes[relation[i].first]=true;
        carefuldudes[relation[i].second]=true;
    }
    int addon=0;
    vector<int> both,onlybad;
    for(int i=1;i<=p;i++){
        int careful=0,oth=0;
        for(auto x:am[i]){
            if(carefuldudes[x]){
                careful++;
            }
            else oth++;
        }
        if(careful==0)addon++;
        else if(oth>0)both.push_back(i);
        else onlybad.push_back(i);
    }

    return 0;
}