#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef __int128 lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXHSH=1;
const int MAXN=2e5+1;
template <class T> struct RIT :iterator<random_access_iterator_tag, T,lli,const T*,T>{
    T elt,skip;
    RIT(T t, T jump) : elt(t), skip(jump) {}
    bool operator == (const RIT &other) const { return elt == other.elt; }
    bool operator != (const RIT &other) const { return elt != other.elt; }
    T &operator * ()  { return elt; }
    RIT &operator ++ () { elt += skip; return *this; }
    RIT &operator -- () { elt -= skip; return *this; }
    RIT &operator += (lli am) { elt += am*skip; return *this; }
    RIT operator + (lli am) const { auto ret = RIT(elt + am * skip,skip); return ret; }
    lli operator - (const RIT& other) const{return (elt-other.elt)/skip;}
};
lli base[MAXHSH]={31};
lli mod[MAXHSH]={(lli)((long long int)1e15+37)};
lli hsh[MAXN][MAXHSH];
inline lli fix(lli a, lli tmod){
    if(a<0)a+=tmod;
    if(a>=tmod)a-=tmod;
    return a;
}
lli prepow[MAXN][MAXHSH];
gp_hash_table<long long int,null_type> used[MAXHSH];
int n;
inline bool work(int len){
    for(int j=0;j<MAXHSH;j++)used[j].clear();
    for(int i=len;i<=n;i++){
        bool happened=true;
        for(int j=0;j<MAXHSH;j++){
            long long int te=fix(hsh[i][j]-hsh[i-len][j],mod[j])*prepow[n-i][j]%mod[j];
            if(used[j].find(te)==used[j].end())happened=false,used[j].insert(te);
        }
        if(happened)return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<MAXHSH;i++)prepow[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<MAXHSH;j++)prepow[i][j]=prepow[i-1][j]*base[j]%mod[j];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<MAXHSH;j++){
            hsh[i][j]=fix(hsh[i-1][j]+(((a[i-1]-'a')+1)*prepow[i-1][j]%mod[j]),mod[j]);
        }
    }
    printf("%d\n",max(0,*lower_bound(RIT<int>(0,1),RIT<int>(n,1),work,[&](auto lhs, auto f){
        return f(lhs);
    })-1));
    return 0;
}