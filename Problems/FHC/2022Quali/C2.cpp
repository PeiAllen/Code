#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int n;
        cin>>n;
        string a;
        cin>>a;
        printf("Case #%d:\n",cs);
        char first=(a[0]=='.'?'-':'.');
        for(int i=0;i<n-1;i++){
            printf("%c",first);
            for(int j=0;j<9;j++){
                if(i&(1<<j)){
                    printf(".");
                }
                else{
                    printf("-");
                }
            }
            printf("\n");
        }
    }
    return 0;
}