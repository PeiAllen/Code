#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
pll dp[61][2][2][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        lli n,m,k,p;
        cin>>n>>m>>k>>p;
        lli to=log2(max(n,m))+1;
        dp[0][1][1][1]={0,1};
        for(lli i=1;i<=to;i++){
            for(int a=0;a<=1;a++){
                for(int b=0;b<=1;b++){
                    for(int c=0;c<=1;c++){
                        dp[0][1][1][1]={0,0};
                        for(int a1=a;a1<=1;a1++) {
                            for (int b1 = b; b1 <= 1; b1++) {
                                for (int c1 = c; c1 <= 1; c1++) {
                                    int firstbit=0;
                                    if(a){
                                        firstbit=(n&(1<<(log2-1))?)
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}