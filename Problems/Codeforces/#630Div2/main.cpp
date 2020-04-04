#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli mod=998244353;
//lli fact[10000];
//lli inv[10000];
lli fp(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=(lli)1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
lli fix(lli a){
    while(a<0)a+=mod;
    return a%mod;
}
//lli choose(lli a, lli b){
//    return ((fact[a]*inv[b]%mod)*inv[a-b]%mod);
//}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,m,l,r;
    long long int n1,m1,l1,r1;
    cin>>n1>>m1>>l1>>r1;
    n=n1,m=m1,l=l1,r=r1;
    lli tot=r-l+(lli)1;
//    lli ea,oa;
//    if(l%2){
//        ea=tot/2;
//        oa=tot-ea;
//    }
//    else{
//        oa=tot/2;
//        ea=tot-oa;
//    }
//    oa%=mod,ea%=mod,tot%=mod;
    lli bs=n*m%mod;
//    fact[0]=1,inv[0]=1;
//    for(lli i=1;i<=bs;i++){
//        fact[i]=fact[i-1]*i%mod;
//        inv[i]=fp(fact[i],mod-2);
//    }
    lli ans=fp(tot%mod,bs%mod);
    if(n%(lli)2==(lli)0||m%(lli)2==(lli)0){
        lli tm=0;
        if(r%(lli)2==l%(lli)2)tm=fix(ans-1)*fp(2,mod-2)%mod;
        else tm=ans*fp(2,mod-2)%mod;
        ans=fix(ans-tm);
    }
    long long int ans2=ans;
    printf("%lli\n",ans2);
//    ans=fp(tot%mod,bs);
//    if(n%2==0||m%2==0)for(lli i=1;i<bs;i+=2){
//        ans=fix(ans-((fp(ea,i)*fp(oa,fix(bs-i))%mod)*choose(bs,i)%mod));
//    }
//    printf("%lli\n",ans);
    return 0;
}