#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> arr={};
    for(int i=1;i<=179;i++)arr.push_back(2*i);
    map<int,int> vals;
    for(int i=0;i<(1<<sz(arr));i++){
        int a=0,b=0;
        for(int j=0;j<sz(arr);j++){
            if(i&(1<<j))a+=arr[j];
            else b+=arr[j];
        }
        if((a+b)%2)assert(0);
        vals[abs(a-b)]++;
    }
    printf("%d %d\n",vals.begin()->first,vals.begin()->second);
    return 0;
}