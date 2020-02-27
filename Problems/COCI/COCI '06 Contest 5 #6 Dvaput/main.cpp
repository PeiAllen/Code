#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXHSH=3;
const int MAXN=2e5+1;
lli base[MAXHSH]={37,131,137};
lli mod[MAXHSH]={(lli)1e9+9,(lli)4e9+7,((lli)1<<(lli)31)-1};
lli hsh[MAXN][MAXHSH];
lli fix(lli a, int type){
    if(a<0)a+=mod[type];
    if(a>=mod[type])a-=mod[type];
    return a;
}
lli prepow[MAXN][MAXHSH];
set<lli> used[MAXHSH];
int n;
bool work(int len){
    for(int j=0;j<MAXHSH;j++)used[j].clear();
    for(int i=len;i<=n;i++){
        bool happened=true;
        for(int j=0;j<MAXHSH;j++){
            lli te=fix(hsh[i][j]-hsh[i-len][j],j)*prepow[n-i][j]%mod[j];
            if(!used[j].count(te))happened=false,used[j].insert(te);
        }
        if(happened)return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<MAXHSH;i++)prepow[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<MAXHSH;j++)prepow[i][j]=prepow[i-1][j]*base[j]%mod[j];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<MAXHSH;j++){
            hsh[i][j]=fix(hsh[i-1][j]+(((a[i-1]-'a')+1)*prepow[i-1][j]%mod[j]),j);
        }
    }
    int lo=0;
    int hi=n-1;
    while(lo!=hi){
        int mid=(lo+hi)/2+1;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%d\n",lo);
    return 0;
}