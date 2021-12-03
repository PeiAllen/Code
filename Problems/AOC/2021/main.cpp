#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    freopen(".txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int a;
    int prev=INT_MAX;
    int ans=0;
    vector<int> arr;
    while(1){
        cin>>a;
        if(a==-1)break;
        arr.push_back(a);
    }
    for(int i=1;i+2<sz(arr);i++){
        if(arr[i+2]>arr[i-1])ans++;
    }
    printf("%d\n",ans);
    return 0;
}