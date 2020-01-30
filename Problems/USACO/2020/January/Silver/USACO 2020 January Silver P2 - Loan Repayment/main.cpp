#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli n,k,m;
bool work(lli x){
    lli am=0;
    lli cur=n;
    lli cnt=0;
    while(cur/x>=m){
       lli y=cur/x;
       lli tocan=((cur%x)+y)/y;
       if(am+y*tocan>=n){
           if((n-am+y-1)/y+cnt<=k)return 1;
           return 0;
       }
       am+=y*tocan;
       cnt+=tocan;
       cur-=y*tocan;
    }
    if(cnt+(n-am+m-1)/m<=k)return 1;
    return 0;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>m;
    lli lo=1,hi=n;
    while(lo!=hi){
        lli mid=(lo+hi)/2+1;
        if(work(mid))lo=mid;
        else hi=mid-1;
    }
    printf("%lli\n",lo);
    return 0;
}