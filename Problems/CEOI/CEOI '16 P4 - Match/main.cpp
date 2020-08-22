#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
map<pair<char,ll>,vector<int>> stackstates;
ll base=131,mod=1e9+7;
ll precalc[MAXN];
ll fix(ll a){
    if(a<0)a+=mod;
    if(a>=mod)a-=mod;
    return a;
}
ll states[MAXN];
char ans[MAXN];
string s;
void solve(int l, int r){
    if(r<l)return;
    int p=*(upper_bound(stackstates[{s[l],states[r]}].begin(),stackstates[{s[l],states[r]}].end(),r)-1);
    ans[l]='(',ans[p]=')';
    solve(p+1,r),solve(l+1,p-1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>s;
    stack<char> st;
    precalc[0]=1;
    for(int i=1;i<sz(s);i++){
        precalc[i]=precalc[i-1]*base%mod;
    }
    ll curhsh=0;
    for(int i=0;i<sz(s);i++){
        if(sz(st)&&s[i]==st.top()){
            curhsh=fix(curhsh-(precalc[sz(st)-1]*(st.top()-'`')%mod));
            st.pop();
        }
        else{
            curhsh=fix(curhsh+(precalc[sz(st)]*(s[i]-'`')%mod));
            st.push(s[i]);
        }
        states[i]=curhsh;
        stackstates[{s[i],curhsh}].push_back(i);
    }
    if(sz(st)){
        printf("-1\n");
        return 0;
    }
    solve(0,sz(s)-1);
    for(int i=0;i<sz(s);i++)printf("%c",ans[i]);
    return 0;
}