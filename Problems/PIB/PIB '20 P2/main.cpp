#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli t;
bool work(lli a){
    for(lli i=0;i<=1;i++)if((a+i)/2-(a+i)/7<=t)return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>t;
    lli lo=0,hi=1e15;
    while(lo!=hi){
        lli mid=(lo+hi)/2+1;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%lli\n",lo);
    return 0;
}