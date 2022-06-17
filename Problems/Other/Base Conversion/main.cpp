#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    set<int> poss;
    for(int i=0;i<sz(a);i++){
        a[i]=(a[i]=='1'?'0':'1');
        int cur=0;
        for(int j=0;j<sz(a);j++){
           cur=cur*2+(a[j]-'0');
        }
        poss.insert(cur);
        a[i]=(a[i]=='1'?'0':'1');
    }
    for(int i=0;i<sz(b);i++){
        b[i]++;
        if(b[i]=='3')b[i]='0';
        int cur=0;
        for(int j=0;j<sz(b);j++){
            cur=cur*3+(b[j]-'0');
        }
        if(poss.count(cur)){
            return 0*printf("%d\n",cur);
        }
        b[i]++;
        if(b[i]=='3')b[i]='0';
        cur=0;
        for(int j=0;j<sz(b);j++){
            cur=cur*3+(b[j]-'0');
        }
        if(poss.count(cur)){
            return 0*printf("%d\n",cur);
        }
        b[i]++;
        if(b[i]=='3')b[i]='0';
    }
    return 0;
}