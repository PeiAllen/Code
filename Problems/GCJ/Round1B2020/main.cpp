#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    int t;
    cin>>t;
    lli a,b;
    cin>>a>>b;
    while(t--){
        string in;
        bool done=false;
        lli le=-1;
        for(lli i=1e9;i>=1e9-150;i--){
            cout<<0<<" "<<i<<endl;
            cin>>in;
            if(in=="WRONG")return 0;
            if(in=="HIT"){
                le=i-(a);
                break;
            }
        }
        lli up=-1;
        for(lli i=1e9;i>=1e9-150;i--){
            cout<<i<<" "<<0<<endl;
            cin>>in;
            if(in=="WRONG")return 0;
            if(in=="HIT"){
                up=i-(a);
                break;
            }
        }
        for(lli i=up;i<=up+8&&!done;i++){
            for(lli j=le;j<=le+8&&!done;j++){
                cout<<i<<" "<<j<<endl;
                cin>>in;
                if(in=="WRONG")return 0;
                if(in=="CENTER"){
                    done=true;
                    break;
                }
            }
            if(done)break;
        }
        if(!done)assert(0);
    }
    return 0;
}