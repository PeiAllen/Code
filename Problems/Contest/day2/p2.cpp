#include "bits/stdc++.h"
#include "Ali.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=10001;
vector<int> adj[MN];
int dist[MN],ma[MN];
void dfs(int loc, int parent){
    dist[loc]=dist[parent]+1;
    for(auto x:adj[loc]){
        if(x!=parent)dfs(x,loc);
    }
}
int n;
int name[MN],backname[3*MN];
void Init(int N, vector<int> U, vector<int> V){
    for(int i=0;i<MN;i++)adj[i]=vector<int>(),dist[i]=0,ma[i]=0,n=0,name[i]=0;
    for(int i=0;i<3*MN;i++)backname[i]=0;
    n=N;
    dist[N]=-1;
    for(int i=0;i<N;i++){
        adj[i]=vector<int>();
    }
    for(int i=0;i<N-1;i++){
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }
    dfs(0,N);
    int oneend=max_element(dist,dist+N)-dist;
    dfs(oneend,N);
    int othend=max_element(dist,dist+N)-dist;
    for(int i=0;i<N;i++)ma[i]=dist[i];
    dfs(othend,N);
    vector<pii> nodes;
    for(int i=0;i<N;i++)ma[i]=max(ma[i],dist[i]),nodes.push_back({ma[i],i});
    sort(nodes.begin(),nodes.end(),greater<>());
    int allowedbits=20-(__lg(n+100)+1);
    int groups=(1<<allowedbits);
    int lo=0,hi=300000;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        int last=0;
        int neededgroups=0;
        for(int i=0;i<N;i++){
            if((i-last+1)*(__lg(nodes[last].first)+1)>mid){
                last=i;
                neededgroups++;
            }
        }
        neededgroups++;
        if(neededgroups<=groups)hi=mid;
        else lo=mid+1;
    }
    int last=0;
    vector<vector<int>> finalgroups;
    for(int i=0;i<N;i++){
        if((i-last+1)*(__lg(nodes[last].first)+1)>lo){
            finalgroups.push_back(vector<int>());
            for(int j=last;j<i;j++){
                finalgroups.back().push_back(nodes[j].second);
            }
            last=i;
        }
    }
    finalgroups.push_back(vector<int>());
    for(int j=last;j<N;j++){
        finalgroups.back().push_back(nodes[j].second);
    }
    if(sz(finalgroups)==1){
        for (auto x: finalgroups) {
            for(int i=0;i<sz(x);i++){
                int id=i;
                name[x[i]]=id;
                backname[id]=x[i];
                SetID(x[i],id);
            }
        }
    }
    else {
        int neededbits =  __lg(sz(finalgroups) - 1) + 1;
        int groupid = 0;
        for (auto x: finalgroups) {
            for(int i=0;i<sz(x);i++){
                int id=groupid+(i<<neededbits);
//                assert(id<=2*N+19);
                name[x[i]]=id;
                backname[id]=x[i];
                SetID(x[i],id);
            }
            groupid++;
        }
    }
}
string SendA(string S){
    int firstbits=(__lg(n+100)+1);
    int val=0,p2=1;
    for(int i=0;i<firstbits;i++){
        val+=(S[i]-'0')*p2;
        p2*=2;
    }
    int val2=0;
    p2=1;
    for(int i=firstbits;i<20;i++){
        val2+=(S[i]-'0')*p2;
        p2*=2;
    }
    dfs(backname[val],n);
    int bitssentover=min(20-firstbits,(__lg(n+100)+1));
    int mask=(1<<bitssentover)-1;
    vector<pii> givedist;
    int neededdistbits=0;
    for(int i=0;i<n;i++){
        if((name[i]&mask)==val2){
            neededdistbits=max(neededdistbits,__lg(dist[i])+1);
            givedist.push_back({name[i],dist[i]});
        }
    }
    sort(givedist.begin(),givedist.end());
    string s(4+neededdistbits*sz(givedist),'0');
    int ptr=0,te=neededdistbits;
    for(int i=0;i<4;i++){
        s[ptr++]='0'+(te%2);
        te/=2;
    }
    for(auto x:givedist){
        for(int i=0;i<neededdistbits;i++){
            s[ptr++]='0'+(x.second%2);
            x.second/=2;
        }
    }
    return s;
}
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    return 0;
//}