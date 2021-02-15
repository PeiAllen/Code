#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=150001;
vector<pii> oadj[MN];
vector<int> nadj[MN];
int depth[MN],ldepth[MN];
vector<int> st;
int comp[MN];
int nodes;
int n,m,k;
void adfs(int loc, int eind, int dep){
    depth[loc]=ldepth[loc]=dep;
    st.push_back(loc);
    for(auto x:oadj[loc]){
        if(x.second!=eind){
            if(depth[loc])ldepth[loc]=min(ldepth[loc],depth[loc]);
            else{
                adfs(x.first,x.second,dep+1);
                if(ldepth[x.first]==depth[x.first])nadj[loc].push_back(x.first),nadj[x.first].push_back(loc);
                else if(ldepth[x.first]==depth[loc]){
                    nodes++;
                    nadj[loc].push_back(nodes);
                    nadj[nodes].push_back(loc);
                    while(1){
                        int cur=st.back();
                        st.pop_back();
                        if(cur==loc)break;
                        comp[cur]=nodes;
                    }
                }
                ldepth[loc]=min(ldepth[loc],ldepth[x.first]);
            }
        }
    }
    if(ldepth[loc]==depth[loc])st.pop_back();
    if(eind==-1&&sz(nadj[loc])==1){
        if(nadj[loc].back()>n)comp[loc]=nadj[loc].back(),nadj[comp[loc]].pop_back(),nadj[loc].pop_back();
        else{
            nodes++;
            nadj[nodes].push_back(nadj[loc].);
            nadj[loc].pop_back();
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll p;
    cin>>n>>m>>k>>p;
    nodes=n;
    return 0;
}