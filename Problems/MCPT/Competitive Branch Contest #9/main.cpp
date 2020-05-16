#pragma GCC optimize("Ofast,branch-probabilities,unroll-loops,peel-loops,tracer,vpt,inline-functions,ipa-cp,ipa-cp-clone,ipa-bit-cp,predictive-commoning,split-loops,unswitch-loops,gcse-after-reload,tree-loop-vectorize,tree-slp-vectorize,vect-cost-model=dynamic,tree-loop-distribute-patterns")
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt"
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli best=-1;
int n,k;
struct node{
    bitset<30> thisval;
    pair<int,int> to[2];
    node(){
        thisval=-1;
        to[0]={0,0};
        to[1]={0,0};
    }
}t[6000000];
int ind=2;
void add(int loc,bitset<30> curval, lli bit, int len){
    if(bit!=0){
        bool curbit=curval[bit];
        if(t[loc].to[curbit].first!=0)t[loc].to[curbit].second=max(t[loc].to[curbit].second,len);
        else{
            t[ind]=node();
            t[loc].to[curbit]={ind,len};
            ind++;
        }
        add(t[loc].to[curbit].first,curval,bit-1,len);
    }
    else t[loc].thisval=curval;
}
void get(int loc,bitset<30> curval, lli bit, int len){
    if(bit!=0){
        bool curbit=curval[bit];
        curbit=!curbit;
        if(t[loc].to[curbit].first==0||t[loc].to[curbit].second+len<k)curbit=!curbit;
        if(t[loc].to[curbit].first==0||t[loc].to[curbit].second+len<k)return;
        get(t[loc].to[curbit].first,curval,bit-1,len);
    }
    else best=max(best,(lli)((curval^t[loc].thisval).to_ullong()));
}
lli val[MAXN];
vector<int> matrix[MAXN];
bool cent[MAXN];
int sts[MAXN];
int gtsz(int loc, int parent){
    sts[loc]=1;
    for(int x:matrix[loc])if(x!=parent&&!cent[x])sts[loc]+=gtsz(x,loc);
    return sts[loc];
}
int dst(int loc, int parent, int size){
    for(int x:matrix[loc])if(x!=parent&&!cent[x]&&sts[x]>size)return dst(x,loc,size);
    return loc;
}
vector<pair<lli,int>> paths;
void dfs(int loc, int parent, lli curval, int dep){
    curval^=val[loc];
    paths.push_back({curval,dep});
    for(int x:matrix[loc]){
        if(x!=parent&&!cent[x]){
            dfs(x,loc,curval,dep+1);
        }
    }
}
void solve(int loc){
    t[1]=node();
    ind=2;
    if(1>=k){
        best=max(best,val[loc]);
    }
    for(int x:matrix[loc]){
        if(!cent[x]){
            dfs(x,loc,val[loc],2);
            for(auto y:paths){
                get(1,y.first,29,y.second);
                if(y.second>=k){
                    best=max(best,y.first);
                }
            }
            for(auto y:paths){
                add(1,y.first^val[loc],29,y.second-1);
            }
            paths.clear();
        }
    }
}
void dft(int loc){
    int next=dst(loc,0,gtsz(loc,0)/2);
    cent[next]=true;
    solve(next);
    for(int x:matrix[next])if(!cent[x])dft(x);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dft(1);
    printf("%lli\n",best);
    return 0;
}