#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=1e3+1;
int arr[MN][MN];
bool used[MN];
vector<int> can[MN];
int cnt[MN];
int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int n=inf.readInt(2,1e3,"n");
    inf.readEoln();
    vector<int> rows;
    for(int i=1;i<=n;i++){
        int emptied=0;
        for(int j=1;j<=n;j++){
            arr[i][j]=inf.readInt(0,n,"a_{i,j}");
            if(arr[i][j]==0)emptied++;
            if(j==n)inf.readEoln();
            else inf.readSpace();
        }
        ensuref(emptied==0||emptied==n,"Row is not completely removed");
        if(emptied)rows.push_back(i);
    }
    ensuref(sz(rows)==2,"Incorrect number of rows removed");
    for(int i=1;i<=n;i++){
        if(i!=rows[0]&&i!=rows[1]){
            for(int j=1;j<=n;j++)ensuref(!used[arr[i][j]],"Not a Valid Latin Square with Two Rows Removed"),used[arr[i][j]]=true;
            for(int j=1;j<=n;j++)used[j]=false;
        }
        for(int j=1;j<=n;j++){
            if(arr[j][i]!=0)ensuref(!used[arr[j][i]],"Not a Valid Latin Square with Two Rows Removed"),used[arr[j][i]]=true;
        }
        for(int j=1;j<=n;j++){
            if(!used[j])can[i].push_back(j),cnt[j]++;
            used[j]=false;
        }
    }
    for(int i=1;i<=n;i++)ensuref(cnt[i]==2,"Not a Valid Latin Square with Two Rows Removed");
    inf.readEof();
    return 0;
}