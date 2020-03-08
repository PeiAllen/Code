#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=501;
int arr[MAXN];
set<int> heights[MAXN];
bool can[24403];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    can[0]=true;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            heights[i].insert(arr[j]-arr[i]);
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=24402;j>=0;j--){
            if(can[j])for(int x:heights[i])can[j+x]=true;
        }
    }
    for(int i=0;i<24403;i++)if(can[i])printf("%d ",i);
    return 0;
}