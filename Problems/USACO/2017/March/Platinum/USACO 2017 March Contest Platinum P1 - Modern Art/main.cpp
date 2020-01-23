#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int MAXN=1002;
const int MAXC=1000001;
int arr[MAXN][MAXN];
int pre[MAXN][MAXN];
pii po[MAXC][2];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int am=0;
    set<int> stuff;
    for(int i=1;i<=pow(n,2);i++)po[i][0]={INT_MAX,-1},po[i][1]={INT_MAX,-1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j])stuff.insert(arr[i][j]);
            po[arr[i][j]][0].first=min(po[arr[i][j]][0].first,i);
            po[arr[i][j]][0].second=max(po[arr[i][j]][0].second,i);
            po[arr[i][j]][1].first=min(po[arr[i][j]][1].first,j);
            po[arr[i][j]][1].second=max(po[arr[i][j]][1].second,j);
        }
    }
    set<int> can;
    for(int i=1;i<=pow(n,2);i++){
        can.insert(i);
        if(po[i][0].first!=INT_MAX){
            pre[po[i][0].first][po[i][1].first]+=1;
            pre[po[i][0].second+1][po[i][1].first]-=1;
            pre[po[i][0].first][po[i][1].second+1]-=1;
            pre[po[i][0].second+1][po[i][1].second+1]+=1;
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j]+=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
            if(pre[i][j]>1){
                can.erase(arr[i][j]);
            }
        }
    }
    if((int)stuff.size()==1&&n>1)printf("%d\n",((int)can.size())-1);
    else printf("%d\n",(int)can.size());
    return 0;
}