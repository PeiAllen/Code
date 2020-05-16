#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
//#define lli __int128
lli mo;
lli fastpow(lli a,lli b){
    a%=mo;
    lli ans=1;
    for(lli i=1;i<=b;i<<=(lli)1){
        if(b&i)ans=ans*a%mo;
        a=a*a%mo;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli m,x;
    long long int mt,xt;
    cin>>mt>>xt;
    m=mt,x=xt;
    lli tot=m;
    mo=m;
    set<lli> done;
    for(lli i=2;i*i<=m;i++){
        lli am=0;
        while(m%i==0){
            done.insert(i);
            am++;
            m/=i;
        }
        if(am){
            tot=tot-tot/i;
        }
    }
    if(m!=1){
        if(!done.count(m))tot=tot-tot/m;
    }
    lli vals=tot;
    for(lli i=1;i*i<=tot;i++){
        if(tot%i==0){
            if(fastpow(x,i)==(lli)1)vals=min(vals,i);
            if(fastpow(x,tot/i)==(lli)1)vals=min(vals,tot/i);
        }
    }
    printf("%lli\n",(long long int)(tot/vals));
    return 0;
}