#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5051;
int dp[MN],from[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=1;i<MN;i++){
        dp[i]=INT_MAX;
        for(int j=1;j*(j+1)/2<=i;j++){
            if(dp[i]>j+dp[i-j*(j+1)/2]+(!!(i-j*(j+1)/2))){
                dp[i]=j+dp[i-j*(j+1)/2]+(!!(i-j*(j+1)/2));
                from[i]=j;
            }
        }
    }
    int k;
    cin>>k;
    for(int i=1;i<=100;i++){
        if(i*(i+1)/2>=k&&dp[i*(i+1)/2-k]<=i){
            int curloc=i*(i+1)/2-k;
            printf("%d\n",i);
            while(curloc!=0){
                for(int j=0;j<from[curloc];j++)printf("2%c"," \n"[!(--i)]);
                curloc-=from[curloc]*(from[curloc]+1)/2;
                if(curloc)printf("1%c"," \n"[!(--i)]);
            }
            while(i)printf("1%c"," \n"[!(--i)]);
            return 0;
        }
    }
    return 0;
}