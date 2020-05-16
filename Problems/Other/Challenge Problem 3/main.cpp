#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        string ate,b;
        cin>>ate>>b;
        string a(sz(b),'0');
        for(int i=0;i<sz(ate);i++){
            a[i+sz(b)-sz(ate)]=ate[i];
        }
        int ma=0;
        int cur=0;
        bool same=true;
        for(int i=0;i<sz(b);i++){
            if(a[i]!=b[i])same=false;
            cur+=b[i]-'0';
            if(!same)ma=max(ma,cur-1+9*(sz(b)-i-1));
        }
        ma=max(ma,cur);
        printf("%d\n",ma);
    }
    return 0;
}