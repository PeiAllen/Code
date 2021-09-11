#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e4+1;
int psa[MAXN];
template <class T> T fp(T a, T b, T mod){
    a%=mod;
    T ans=1;
    for(T i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
template <class T> bool isprime(T x){
    if(x<=1||x%6%4!=1)return (x|1)==3;
    T s=0,d=x-1;
    while(!(d&1))s++,d>>=1;
    for(T a:{660, 56928287}){
        T v=fp(a,d,x),i=s-1;
        if(v!=1)while(v!=x-1&&i--&&v>1)v=v*v%x;
        if(v!=x-1&&a%x!=0&&i!=s-1)return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>psa[i];
            psa[i]+=psa[i-1];
        }
        bool done=false;
        for(int i=2;i<=n&&!done;i++){
            for(int j=i;j<=n&&!done;j++){
                if(isprime(ll(psa[j]-psa[j-i]))){
                    printf("Shortest primed subsequence is length %d:",i);
                    for(int k=j-i+1;k<=j;k++){
                        printf(" %d",psa[k]-psa[k-1]);
                    }
                    printf("\n");
                    done=true;
                }
            }
        }
        if(!done)printf("This sequence is anti-primed.\n");
    }
    return 0;
}