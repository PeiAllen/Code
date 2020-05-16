#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
lli mod1=1000012333;
lli base1=2081;
lli precalc1[MAXN];
lli inv1[MAXN];
//lli mod2=1e9+7;
//lli base2=1009;
//lli precalc2[MAXN];
//lli inv2[MAXN];
int val[MAXN];
vector<int> matrix[MAXN];
lli fix(lli a, lli mod){
    while(a<0)a+=mod;
    return a%mod;
}
lli fp(lli a,lli b, lli mod){
    lli ans=1;
    for(lli i=1;i<=b;i<<=(lli)1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int wanted;
bool work1,work2;
bool cent[MAXN];
int sts[MAXN];
lli prehash[MAXN];
lli sufhash[MAXN];
int lift[16][MAXN];
bool ispal[MAXN];
int getsize(int loc, int parent){
    sts[loc]=1;
    for(int x:matrix[loc])if(!cent[x]&&x!=parent)sts[loc]+=getsize(x,loc);
    return sts[loc];
}
int decompsubtree(int loc, int parent, int size){
    for(int x:matrix[loc])if(!cent[x]&&x!=parent&&sts[x]>size)return decompsubtree(x,loc,size);
    return loc;
}
inline int goup(int loc, int am){
    for(int i=0;i<16;i++){
        if(am&(1<<i))loc=lift[i][loc];
    }
    return loc;
}
gp_hash_table<lli,null_type> hashes;
vector<lli> toinsert;
int from;
void dfs(int loc, int parent, lli hashpre, lli hashsuf, int dep){
    lift[0][loc]=parent;
    for(int i=1;i<16;i++)lift[i][loc]=lift[i-1][lift[i-1][loc]];
    hashpre=((hashpre*base1%mod1)+val[loc])%mod1;
    //hashpre.second=((hashpre.second*base2%mod2)+val[loc])%mod2;
    prehash[loc]=hashpre;
    hashsuf=(hashsuf+(precalc1[dep]*val[loc]%mod1))%mod1;
    //  hashsuf.second=(hashsuf.second+(precalc2[dep]*val[loc]%mod2))%mod2;
    sufhash[loc]=hashsuf;
    ispal[loc]=false;
    int halfpoint=goup(loc,dep-(dep-1)/2);
    int cuthalf=goup(loc,dep-dep/2);
    lli te=sufhash[loc];
    te=fix(te-sufhash[cuthalf],mod1)*inv1[dep/2+1]%mod1;
    // te.second=fix(te.second-sufhash[cuthalf].second,mod2)*inv2[dep/2+1]%mod2;
    if(prehash[halfpoint]==te){
        ispal[loc]=true;
        if(dep+1==wanted)work1=true;
        if(dep+1==wanted+1)work2=true;
    }
    te=sufhash[loc];
    te=fix(te-sufhash[from],mod1)*inv1[1]%mod1;
    //  te.second=fix(te.second-sufhash[from].second,mod2)*inv2[1]%mod2;
    toinsert.push_back(te);
    if(dep+1>=wanted-(dep+1)&&wanted-(dep+1)>0){
        int check=goup(loc,wanted-(dep+1));
        te=sufhash[loc];
        te=fix(te-sufhash[check],mod1)*inv1[dep-(wanted-(dep+1))+1]%mod1;
        //  te.second=fix(te.second-sufhash[check].second,mod2)*inv2[dep-(wanted-(dep+1))+1]%mod2;
        if(ispal[check]&&hashes.find(te)!=hashes.end())work1=true;
    }
    if(dep+1>=(wanted+1)-(dep+1)&&(wanted+1)-(dep+1)>0){
        int check=goup(loc,(wanted+1)-(dep+1));
        te=sufhash[loc];
        te=fix(te-sufhash[check],mod1)*inv1[dep-((wanted+1)-(dep+1))+1]%mod1;
        //  te.second=fix(te.second-sufhash[check].second,mod2)*inv2[dep-(wanted-(dep+1))+1]%mod2;
        if(ispal[check]&&hashes.find(te)!=hashes.end())work2=true;
    }
    for(int x:matrix[loc]){
        if(!cent[x]&&x!=parent)dfs(x,loc,hashpre,hashsuf,dep+1);
    }
}
void decompfulltree(int loc){
    int next=decompsubtree(loc,0,getsize(loc,0)/2);
    cent[next]=true;
    for(int i=0;i<16;i++)lift[i][next]=0;
    lli hashpre,hashsuf;
    hashpre=val[next];
    // hashpre.second=val[next];
    prehash[next]=hashpre;
    hashsuf=val[next];
    //  hashsuf.second=val[next];
    sufhash[next]=hashsuf;
    from=next;
    ispal[next]=true;
    for(int x:matrix[next]){
        if(!cent[x])dfs(x,next,hashpre,hashsuf,1);
        for(auto x:toinsert)hashes.insert(x);
        toinsert.clear();
    }
    hashes.clear();
    reverse(matrix[next].begin(),matrix[next].end());
    for(int x:matrix[next]){
        if(!cent[x])dfs(x,next,hashpre,hashsuf,1);
        for(auto x:toinsert)hashes.insert(x);
        toinsert.clear();
    }
    hashes.clear();
    reverse(matrix[next].begin(),matrix[next].end());
    for(int x:matrix[next]){
        if(!cent[x])decompfulltree(x);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    char c;
    precalc1[0]=1;
    // precalc2[0]=1;
    inv1[0]=1;
    // inv2[0]=1;
    ispal[0]=true;
    for(int i=1;i<=n;i++){
        cin>>c;
        val[i]=(c-'a')+1;
        precalc1[i]=precalc1[i-1]*base1%mod1;
        //   precalc2[i]=precalc2[i-1]*base2%mod2;
        inv1[i]=fp(precalc1[i],mod1-2,mod1);
        //  inv2[i]=fp(precalc2[i],mod2-2,mod2);
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    int ans=1;
    int lo=0,hi=n/2;
    while(lo!=hi){
        int mid=(lo+hi)/2+1;
        wanted=mid*2;
        work1=false,work2=false;
        memset(cent,false,sizeof(cent));
        decompfulltree(1);
        if(work1||work2){
            lo=mid;
            if(work2)ans=wanted+1;
            else ans=wanted;
        }
        else hi=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}