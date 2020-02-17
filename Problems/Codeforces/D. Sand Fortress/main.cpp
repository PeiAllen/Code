#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli n,h;
lli work(lli a){
    lli te=a*(a+1);
    if(te)
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>h;
    lli lo=0;
    lli hi=n;
    while(lo!=hi){
        lli mid=(lo+hi)/2;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    lli te=work(lo);
     lo=0;
     hi=n;
    while(lo!=hi){
        lli mid=(lo+hi)/2;
        if(work2(mid))lo=mid;
        else hi=mid-1;
    }
    lli te2=work2(lo);
    printf("%lli\n",min(te,te2));
    return 0;
}