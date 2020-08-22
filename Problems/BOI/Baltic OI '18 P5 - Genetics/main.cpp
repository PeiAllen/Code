#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=4101;
string arr[MAXN];
int am[MAXN][4];
int sum[MAXN];
int val[MAXN];
int conver[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(int(0), int(5e5));
    conver['A'-'A']=0;
    conver['C'-'A']=1;
    conver['T'-'A']=2;
    conver['G'-'A']=3;
    int totsum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        val[i]=dis(gen);
        totsum+=val[i];
        for(int j=0;j<m;j++)am[j][conver[arr[i][j]-'A']]+=val[i],sum[j]+=val[i];
    }
    for(int i=0;i<n;i++){
        int curam=0;
        for(int j=0;j<m;j++)curam+=sum[j]-am[j][conver[arr[i][j]-'A']];
        if(curam==k*(totsum-val[i])){
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}