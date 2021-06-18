#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> arr;
    arr.push_back(1);
    for(int i=2;i<=n;i++)arr.push_back(i),arr.push_back(i);
    do{
        bool work=true;
        for(int i=2;i<=n&&work;i++){
            vector<int> locs;
            for(int j=0;j<sz(arr);j++){
                if(arr[j]==i)locs.push_back(j);
            }
            if(locs[1]-locs[0]!=i)work=false;
        }
        if(work){
            for(auto x:arr)printf("%d ",x);
            printf("\n");
        }
    }while(next_permutation(arr.begin(),arr.end()));
    return 0;
}