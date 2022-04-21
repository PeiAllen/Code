#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int arr[MN];
int poss[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vals(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        vals[i]=i+1;
    }
    do{
        bool work=true;
        for(int i=0;i<n&&work;i++){
            if(min(vals[(i-1+n)%n],vals[(i+1)%n])!=arr[i])work=false;
        }
        if(work){
            for(int i=0;i<n;i++){
                if(poss[i]==0)poss[i]=vals[i];
                else if(poss[i]!=vals[i])poss[i]=INT_MAX;
            }
        }
    }while(next_permutation(vals.begin(),vals.end()));
    for(int i=0;i<n;i++){
        if(poss[i]!=INT_MAX)printf("%d%c",poss[i]," \n"[i==n-1]);
        else printf("0%c"," \n"[i==n-1]);
    }
    return 0;
}