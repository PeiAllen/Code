#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<int> arr[7];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    arr[0]={0,4,8};
    arr[1]={1,5,9};
    arr[2]={2,6,10};
    arr[3]={3,7,11};
    arr[4]={0,3,6,9};
    arr[5]={1,4,7,10};
    arr[6]={2,5,8,11};
    int cnt=0;
    for(int i=0;i<(1<<12);i++){
        bool baf=false;
        for(auto x:arr){
            set<int> cols;
            for(auto y:x)cols.insert(!!(i&(1<<y)));
            if(sz(cols)==1)baf=true;
        }
        if(!baf)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}