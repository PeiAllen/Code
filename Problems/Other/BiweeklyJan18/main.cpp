#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=5003;
lli shash[MAXN];
lli mut=37;
lli mod=1610612741;
lli inv[MAXN];
lli prepow[MAXN];
lli fastpow(lli a, lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
inline lli fix(lli a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
map<int,int> hashes;
lli ans[5];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    prepow[0]=1;
    for(int i=1;i<5003;i++)prepow[i]=prepow[i-1]*mut%mod;
    for(int i=0;i<5003;i++){
        inv[i]=fastpow(prepow[i],mod-2);
    }
    rep(i,0,n){
        string s;
        sc(s);
        for(int b=0;b<sz(s);b++){
            shash[b+1]=(fix((shash[b]+(((s[b]-'a')+1)*prepow[b]%mod))));
            for(int a=0;a<=b;a++){
                lli te=(fix(shash[b+1]-shash[a])*inv[a]%mod);
                if(hashes.count(te)){
                    if(hashes[te]!=i)hashes[te]=-1;
                }
                else{
                    hashes[te]=i;
                }
            }
        }
    }
    for(auto x:hashes){
        if(x.second!=-1)ans[x.second]++;
    }
    rep(i,0,n)prl(ans[i]);
    return 0;
}