#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char type[2]={'.','.'};
        char a;
        bool poss=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a;
                if(a!='.'){
                    if(type[(i+j)%2]=='.')type[(i+j)%2]=a;
                    else poss&=(type[(i+j)%2]==a);
                }
            }
        }
        if(!poss||(type[0]==type[1]&&type[0]!='.')){
            printf("no\n");
        }
        else{
            printf("yes\n");
            if(type[0]=='.')type[0]=(type[1]=='R'?'W':'R');
            if(type[1]=='.')type[1]=(type[0]=='R'?'W':'R');
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%c",type[(i+j)%2]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}