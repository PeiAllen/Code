#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
bool cypher(const vector<int>& a, int k){
    int sum=0;
    for(int i=0;i<sz(a);i++){
        int prod=1;
        for(int j=0;j<k;j++)prod*=a[(j+i)%sz(a)];
        sum+=prod;
    }
    return sum==0;
}
int get(int a){
    int ans=1;
    while(a%2==0)ans*=2,a/=2;
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int evenam=get(k);
    if(n%(evenam*2)==0) {
        for (int i = 0; i < n / evenam; i++) {
            for (int j = 0; j < evenam; j++) {
                printf("%d%c", (i % 2 == 0 ? 1 : -1), " \n"[i * evenam + j == n - 1]);
            }
        }
    }
    else{
        int nevenam=get(n);
        if(nevenam>=4&&n/nevenam>=3&&evenam>=nevenam&&k<n){
            bool flip=false;
            if(n-k<k)k=n-k,flip=true;
            int get=0;
            int am=0;
            while(get<n/2||am<=1)am++,get+=k;
            int cnt=0;
            for(int i=0;i<am-1;i++){
                for(int j=0;j<k-1;j++)printf("%d ",(flip?-1:1)),cnt++;
                printf("%d ",(flip?1:-1)),cnt++;
            }
            int needed=n/2-(get-2*k);
            int range=needed/2-1;
            for(int i=0;i<range;i++){
                printf("%d ",(flip?-1:1)),cnt++;
            }
            printf("%d",(flip?1:-1)),cnt++;
            assert(cnt<=n);
            if(cnt==n)printf("\n");
            else{
                printf(" ");
                for(int i=cnt;i<n;i++)printf("%d%c",(flip?-1:1)," \n"[i==n-1]);
            }
        }
        else{
            printf("0\n");
            return 0;
        }
    }
//    ll i=44;
//            for (ll k = 0; k < (ll(1) << i); k++) {
//                vector<int> num(i);
//                for (ll l = 0; l < i; l++) {
//                    if (k & (ll(1) << l))num[i-l-1] = -1;
//                    else num[i-l-1] = 1;
//                }
//                bool work=true;
//                for(int j=4;j<i;j+=4) {
//                    if (!cypher(num, j)) work=false;
//
////                        printf("%d %d\n", i, j);
////                        for (int v = 0; v < i; v++)printf("%d%c", num[v], " \n"[v == i - 1]);
//
//                }
//                if(work){
//                    for (ll v = 0; v < i; v++)printf("%d%c", num[v], " \n"[v == i - 1]);
//                    break;
//                }
//            }

    return 0;
}