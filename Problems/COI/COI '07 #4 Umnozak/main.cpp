#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans*=a;
        a*=a;
    }
    return ans;
}
int arr[4];
int dig[19];
int cont[10][4];
unordered_map<ll,ll> dp[19][2][2];
ll go(int cur, int two, int three, int five, int seven, bool ma, bool lead, ll val){
    if(two>arr[0]||three>arr[1]||five>arr[2]||seven>arr[3])return 0;
    if((arr[0]-two)/3+(arr[1]-three+1)/2+arr[2]-five+arr[3]-seven>cur+1)return 0;
    if(cur==-1){
        if(arr[0]==two&&arr[1]==three&&arr[2]==five&&arr[3]==seven)return 1;
        return 0;
    }
    if(dp[cur][ma][lead].count(val))return dp[cur][ma][lead][val];
    ll ans=0;
    for(ll i=!lead;i<=(ma?dig[cur]:9);i++){
        ans+=go(cur-1,two+cont[i][0],three+cont[i][1],five+cont[i][2],seven+cont[i][3],ma&&i==dig[cur],lead&&i==0,(i==0?val:val*i));
    }
    return dp[cur][ma][lead][val]=ans;
}
ll getans(ll a){
    for(int i=0;i<19;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=unordered_map<ll,ll>();
    for(int i=0;i<19;i++)dig[i]=a%10,a/=10;
    return go(18,0,0,0,0,1,1,1);
}
ll solve(ll a, ll b){
    if(a>b)return 0;
    ll te=getans(b);
    if(te==0)return 0;
    return te-getans(a-1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=1;i<=9;i++){
        int cur=i;
        while(cur%2==0)cont[i][0]++,cur/=2;
        while(cur%3==0)cont[i][1]++,cur/=3;
        while(cur%5==0)cont[i][2]++,cur/=5;
        while(cur%7==0)cont[i][3]++,cur/=7;
    }
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    for(arr[0]=0;arr[0]<=3*18;arr[0]++){
        for(arr[1]=0;arr[1]<=2*(18-arr[0]/3)&&fp(2,arr[0])*fp(3,arr[1])<=b;arr[1]++){
            for(arr[2]=0;arr[2]<=18-arr[0]/3-arr[1]/2&&fp(2,arr[0])*fp(3,arr[1])*fp(5,arr[2])<=b;arr[2]++){
                for(arr[3]=0;arr[3]<=18-arr[0]/3-arr[1]/2-arr[2]&&fp(2,arr[0])*fp(3,arr[1])*fp(5,arr[2])*fp(7,arr[3])<=b;arr[3]++) {
                    ll selfprod = fp(2, arr[0]) * fp(3, arr[1]) * fp(5, arr[2])*fp(7,arr[3]);
                    int neededdigits=arr[0]/3+(arr[1]+1)/2+arr[2]+arr[3];
                    ll te=b/selfprod;
                    while(te)neededdigits--,te/=10;
                    if(neededdigits>0)continue;
                    ans += solve((a + selfprod - 1) / selfprod, b / selfprod);
                }
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}