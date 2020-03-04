#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli am[10];
lli fact[19];
lli ways(int dig,int last, lli cur,lli top){
    if(dig==2){
        lli tot=fact[2];
        lli te[10];
        for(int i=1;i<=9;i++){
            tot/=fact[am[i]];
            te[i]=am[i];
        }
        if(cur==0)return tot;
        lli ma=top/cur;
        string a=to_string(ma);
        reverse(a.begin(),a.end());
        a.resize(2,'0');
        reverse(a.begin(),a.end());
        lli ans=0;
        for(int i=0;i<2;i++){
            for(int j=1;j<a[i]-'0';j++){
                if(te[j]){
                    lli tetot=tot;
                    tetot=tetot/fact[2-i]*fact[2-i-1];
                    tetot=tetot*fact[te[j]]/fact[te[j]-1];
                    ans+=tetot;
                }
            }
            if(!te[a[i]-'0'])return ans;
            te[a[i]-'0']-=1;
            tot=tot/fact[2-i]*fact[2-i-1];
            tot=tot*fact[te[a[i]-'0']+1]/fact[te[a[i]-'0']];
        }
        return ans;
    }
    lli ans=0;
    for(int i=last;i<=9;i++){
        am[i]++;
        ans+=ways(dig+1,i,cur*(i==0?1:i),top);
        am[i]--;
    }
    return ans;
}
//lli am=0;
//void cnt(int dig, int last){
//    if(dig==18){
//        am++;
//        return;
//    }
//    for(int i=last;i<=9;i++){
//        cnt(dig+1,i);
//    }
//}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    cnt(0,0);
//    printf("%lli\n",am);
    fact[0]=1;
    for(lli i=1;i<=18;i++){
        fact[i]=fact[i-1]*i;
    }
    lli a,b;
    cin>>a>>b;
    printf("%lli %lli\n",ways(0,0,1,b),ways(0,0,1,a-1));
    printf("%lli\n",ways(0,0,1,b)-ways(0,0,1,a-1));
    return 0;
}
