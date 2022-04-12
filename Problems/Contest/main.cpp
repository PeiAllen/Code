#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
bool ree[10]={0,0,1,0,0,1,1,0,0,1};
int sum[10];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a;
    for(int i=0;i<29;i++){
        cin>>a;
        for(int j=0;j<10;j++){
            cin>>a;
            if(ree[j])printf("%c",'A'+a);
            else printf("%c",'a'+a);
        }
        printf("\n");
    }
    return 0;
}