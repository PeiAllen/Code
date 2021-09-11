#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
typedef unsigned long long ull;
const int N = 400000;
bool s[N+1][256];

ull myRand(ull &k1, ull &k2) {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

void gen(int n, ull a1, ull a2) {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 256; j++)
            s[i][j] = (myRand(a1, a2) & (1ull << 32)) ? 1 : 0;
}
bitset<256> arr;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    ull a1,a2;
    cin>>n>>m>>a1>>a2;
    gen(n,a1,a2);
    int lastans=0;
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        for(int j=0;j<SZ(a);j++){
            int val=(isdigit(a[j])?a[j]-'0':(a[j]-'A'+10));
            for(int l=0;l<4;l++)arr[j*4+l]=!!(val&(1<<(4-l-1)));
        }
        for(int j=0;j<256;j++)arr[j]=(arr[j])^lastans;
        cin>>k;

    }
    return 0;
}