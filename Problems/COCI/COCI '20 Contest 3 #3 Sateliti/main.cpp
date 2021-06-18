#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1001;
const ll mod=1e9+7,mut=31;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll pc[MN*MN],inv[MN*MN];
string arr[MN];
int n,m;
ll rowhash[MN][MN];
ll rowshash[MN][MN];
char getith(pii st, int i){
    return arr[(st.first+i/m)%n][(st.second+i%m)%m];
}
ll getrowhash(int r, int a, int b){
    if(b<a){
        ll pre=rowhash[r][b]*pc[m-a]%mod;
        ll suf=(rowhash[r][m-1]-(a-1>=0?rowhash[r][a-1]:0)+mod)*inv[a]%mod;
        return (pre+suf)%mod;
    }
    return (rowhash[r][b]-(a-1>=0?rowhash[r][a-1]:0)+mod)*inv[a]%mod;
}
ll gethash(pii st, int characters){
    if(characters==0)return 0;
    pii before={st.first,st.second-1};
    if(before.second==-1)before.first-=1,before.second=m-1;
    pii en={(st.first+(characters-1)/m)%n,(st.second+(characters-1)%m)%m};
    if(en<st){
        ll pre=psahash[en.first][en.second]*pc[(n-1-st.first)*m+m-st.second]%mod;
        ll suf=(psahash[n-1][m-1]-(before.first>=0?psahash[before.first][before.second]:0)+mod)*inv[st.first*m+st.second]%mod;
        return (pre+suf)%mod;
    }
    else{
        if(st.first==en.first)return getrowhash(st.first,st.second,en.second);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)pc[i]=pc[i-1]*mut%mod,inv[i]=fp(pc[i],mod-2);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ll last=0;
        int curind=0;
        for(int j=0;j<m;j++){
            last=rowhash[i][j]=(last+pc[curind]*((arr[i][j]=='*')+1))%mod;
            curind++;
        }
    }
    for(int i=0;i<m;i++){
        ll last=0;
        for(int j=0;j<n;j++){
            last=rowshash[i][j]=(last+getrowhash(j,i,(i==0?m-1:i-1))*pc[j*m]%mod)%mod;
        }
    }
    auto f=[&](const pii& lhs, const pii& rhs){
        int lo=0,hi=n*m;
        while(lo!=hi){
            int mid=(lo+hi+1)/2;
            if(gethash(lhs,mid)==gethash(rhs,mid))lo=mid;
            else hi=mid-1;
        }
        if(hi==m*n)return false;
        return getith(lhs,lo)<getith(rhs,lo);
    };
    pii cur={0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(f({i,j},cur))cur={i,j};
        }
    }
    int curi=cur.first;
    for(int i=0;i<n;i++){
        int curj=cur.second;
        for(int j=0;j<m;j++){
            printf("%c",arr[curi][curj]);
            curj=(curj+1)%m;
        }
        curi=(curi+1)%n;
        printf("\n");
    }
    return 0;
}