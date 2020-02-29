#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<string,set<int>> stuffs;
set<pii> ams;
set<string> am[401];
string fin[401];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string a;
    if(n>(1<<m)){
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a;
        int cnt=0;
        vector<int> pos;
        for(int j=0;j<m;j++){
            if(a[j]=='?')cnt++,pos.push_back(j);
        }
        for(int j=0;j<(1<<cnt);j++){
            for(int l=0;l<cnt;l++){
                if(j&(1<<l)){
                    a[pos[l]]='X';
                }
                else a[pos[l]]='.';
            }
            stuffs[a].insert(i);
            am[i].insert(a);
        }
        ams.insert({sz(am[i]),i});
    }
    while(sz(ams)){
        auto cur=*ams.begin();
        ams.erase(ams.begin());
        if(cur.first==0){
            cout<<"NO\n";
            return 0;
        }
        fin[cur.second]=*am[cur.second].begin();
        for(auto x:am[cur.second]){
            stuffs[x].erase(cur.second);
        }
        for(auto x:stuffs[*am[cur.second].begin()]){
            ams.erase({sz(am[x]), x});
            assert(x!=cur.second);
            am[x].erase(*am[cur.second].begin());
            ams.insert({sz(am[x]), x});
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)cout<<fin[i]<<"\n";
    return 0;
}