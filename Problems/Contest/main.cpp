#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int n,m;
const int MN=10001;
int pc[MN];
int res[MN];
int nval[MN];

void solveone(){
    string a;
    cin>>a;
    vector<int> op;
    int zerovalue=0,onevalue=1;
    for(auto x:a){
        if(x=='R'){
            if(zerovalue==0&&onevalue==1)op.push_back(0);
            else if(zerovalue==0&&onevalue==0)op.push_back(1);
            else if(zerovalue==1&&onevalue==1)op.push_back(2);
            else op.push_back(3);
            zerovalue=0,onevalue=1;
        }
        else if(x=='0')zerovalue=0,onevalue=0;
        else if(x=='1')zerovalue=1,onevalue=1;
        else zerovalue^=1,onevalue^=1;
    }
    pc[0]=1;
    for(int i=1;i<=n;i++){
        pc[i]=pc[i-1]*3;
    }
    int ans=0;
    for(int i=0;i<(pc[n]);i++){
        int te=i;
        for(int j=0;j<n;j++){
            res[j]=te%3;
            te/=3;
        }
        set<vector<int>> cnt;
        for(int j=0;j+SZ(op)<=n;j++){
            int loc=j;
            for(int l=0;l<n;l++)nval[l]=res[l];
            for(auto x:op){
                if(res[loc]==0)nval[loc]=0;
                else{
                    if(x==0)nval[loc]=res[loc];
                    else if(x==1)nval[loc]=0;
                    else if(x==2)nval[loc]=1;
                    else if(x==3)nval[loc]=1-res[loc];
                }
                loc++;
            }
            vector<int> te(nval,nval+n);
            cnt.insert(te);
        }
        ans+=SZ(cnt);
    }
    printf("%d\n",ans);
}
void solvenor(string a){
    vector<int> op;
    int zerovalue=0,onevalue=1;
    for(auto x:a){
        if(x=='R'){
            if(zerovalue==0&&onevalue==1)op.push_back(0);
            else if(zerovalue==0&&onevalue==0)op.push_back(1);
            else if(zerovalue==1&&onevalue==1)op.push_back(2);
            else op.push_back(3);
            zerovalue=0,onevalue=1;
        }
        else if(x=='0')zerovalue=0,onevalue=0;
        else if(x=='1')zerovalue=1,onevalue=1;
        else zerovalue^=1,onevalue^=1;
    }
    if(zerovalue==0&&onevalue==1)op.push_back(0);
    else if(zerovalue==0&&onevalue==0)op.push_back(1);
    else if(zerovalue==1&&onevalue==1)op.push_back(2);
    else op.push_back(3);
    zerovalue=0,onevalue=1;
    if(op[0]==0){
        printf("%lli\n",fp(3,n*m)*n%mod);
    }
    else if(op[0]==1||op[0]==2){
        ll ans=fp(3,n*m)*n%mod;
        ll toadd=1;
        for(int i=0;i<n;i++){
            ans=(ans-fp(3,(n-1)*m)*fp(2,m)%mod+mod)%mod;
            toadd=toadd*(fp(3,m)-fp(2,m)+mod)%mod;
        }
        printf("%lli\n",(ans+fp(3,n*m)-toadd+mod)%mod);
    }
    else{
        ll ans=fp(3,n*m)*n%mod;
        ll toadd=1;
        for(int i=0;i<n;i++){
            ans=(ans-fp(3,(n-1)*m)+mod)%mod;
            toadd=toadd*(fp(3,m)-1+mod)%mod;
        }
        printf("%lli\n",(ans+fp(3,n*m)-toadd+mod)%mod);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    if(m==1) {
        solveone();
        return 0;
    }
    string a;
    cin>>a;
    if(a.find('R')==string::npos){
        solvenor(a);
        return 0;
    }
    return 0;
}