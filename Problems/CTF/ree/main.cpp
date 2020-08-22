#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[10000];
int te[10000];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            te[j]=arr[(j-1+n)%n]^(arr[j]|arr[(j+1)%n]);
        }

        for(int j=0;j<n;j++){
            arr[j]=te[j];
            //printf("%d ",arr[j]);
        }
        printf("%d\n",arr[0]);
//        printf("\n");
    }
    return 0;
}