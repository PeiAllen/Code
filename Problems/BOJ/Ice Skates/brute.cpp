#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
ll d;
int n,m;
ll arr[MN],am[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll b;
    int a;
    cin>>n>>m>>b>>d;
    for(int i=1;i<=n;i++)arr[i]=b;
    while(m--){
        cin>>a>>b;
        am[a]+=b;
        int ptr=1;
        ll amtaken=0;
        bool work=true;
        for(int i=1;i<=n;i++){
            if(am[i]==0)continue;
            while(ptr<i)ptr++,amtaken=0;
            ll needed=am[i];
            while(ptr<=n&&arr[ptr]-amtaken<needed){
                needed-=arr[ptr]-amtaken;
                ptr++;
                amtaken=0;
            }
            if(ptr>i+d){
                work=false;
                break;
            }
            amtaken+=needed;
            if(amtaken==arr[ptr])ptr++,amtaken=0;
        }
        if(work)printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}