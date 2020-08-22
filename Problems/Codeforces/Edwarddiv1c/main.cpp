#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int arr[20];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        arr[a]=i;
    }
    int p;
    cin>>p;
    int b;
    int val=0;
    for(int i=0;i<p;i++){
        cin>>a>>b;
        val+=abs(a-b);
        swap(arr[a],arr[b]);
    }
    printf("%d\n",val);
    int cnt=0;
    for(int i=1;i<n;i++)printf("%d ",arr[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[j]>arr[i])cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}