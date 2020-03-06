#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
//const int n=301;
lli arr[1001][1001];
//int topr[n][n];
int main(int argc, char * argv[]){
//    registerGen(argc, argv, 1);
//    rnd.setSeed(time(0));
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++)cin>>arr[i][j],arr[i][j]+=arr[i][j-1];
        //for(int j=1;j<n;j++)arr[i][j]=rnd.next(-1000,1000),topr[i][j]=arr[i][j];
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        vector<int> te;
        for(int j=0;j<n;j++){
            te.push_back(arr[j][i]);
        }
        sort(te.begin(),te.end());
        ans.push_back(te[n/2]);
    }
    sort(ans.begin(),ans.end());
    printf("YES\n");
    for(int i=0;i<n;i++)printf("%d\n",ans[n/2]);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)arr[i][j]-=ans[n/2];
//    }
//    ans.clear();
//    for(int i=0;i<n;i++){
//        vector<int> te;
//        for(int j=0;j<n;j++){
//            te.push_back(arr[j][i]);
//        }
//        sort(te.begin(),te.end());
//        ans.push_back(te[n/2]);
//    }
//    sort(ans.begin(),ans.end());
//    printf("%d\n",ans[n/2]);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++)printf("%d ",topr[i][j]);
//        printf("\n");
//    }
    return 0;
}