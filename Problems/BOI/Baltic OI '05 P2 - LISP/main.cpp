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
    int n,m;
    cin>>n>>m;
    string a(n,'_');
    int ptr=0;
    string in;
    while(ptr<n){
        cin>>in;
        for(auto x:in)a[ptr++]=x;
    }
    int extra=0;
    int cnt=0;
    int lastloc=-1;
    for(int i=0;i<sz(a);i++){
        if(a[i]=='(')extra++;
        else if(a[i]==')')extra--;
        else{
            lastloc=i;
            cnt++;
        }
    }
    if(cnt>extra){
        printf("0\n");
        return 0;
    }
    int am=0;
    for(int i=0;i<sz(a);i++){
        if(a[i]=='(')am++;
        else if(a[i]==')'||a[i]==']'){
            if(i==lastloc)am-=extra-cnt;
            am--;
            if(am<0){
                printf("0\n");
                return 0;
            }
        }
    }
    printf("1\n");
    for(int i=1;i<cnt;i++){
        printf("%d\n",1);
    }
    printf("%d\n",extra-cnt+1);
    return 0;
}