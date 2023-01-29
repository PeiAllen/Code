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
        int r,c;
        cin>>r>>c;
        int cnt=0;
        char a;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a;
                if(a=='^')cnt++;
            }
        }
        printf("Case #%d: ",cs);
        if(cnt==0){
            printf("Possible\n");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    printf(".");
                }
                printf("\n");
            }
        }
        else if(r==1||c==1){
            printf("Impossible\n");
        }
        else{
            printf("Possible\n");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    printf("^");
                }
                printf("\n");
            }
        }
    }
    return 0;
}