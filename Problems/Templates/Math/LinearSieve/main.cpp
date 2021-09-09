#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e7+1;
bool iscompo[MN];
int spc[MN];
int multfunc[MN];//totient for now
int fp(int a, int b){
    int ans=1;
    for(int i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a;
        a=a*a;
    }
    return ans;
}
int calc(int p, int k){
    return (p-1)*fp(p,k-1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(!iscompo[i]){
            primes.push_back(i);
            multfunc[i]=calc(i,1);
            spc[i]=1;
        }
        printf("%d ",multfunc[i]);
        for(int j=0;j<sz(primes)&&primes[j]*i;j++){
            if(i%primes[j]==0){
                multfunc[i*primes[j]]=multfunc[i]/calc(primes[j],spc[i])*calc(primes[j],spc[i]+1);
                spc[i*primes[j]]=spc[i]+1;
            }
            else{
                multfunc[i*primes[j]]=multfunc[i]*multfunc[primes[j]];
                spc[i*primes[j]]=1;
            }
            iscompo[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
    printf("\n");
    for(auto x:primes)printf("%d\n",x);
    return 0;
}