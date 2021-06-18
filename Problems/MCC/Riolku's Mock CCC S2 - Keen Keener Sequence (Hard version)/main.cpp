#include "bits/stdc++.h"
using namespace std;
using ll=long long;
using pii=pair<int,int>;
template <typename T>
int sz(const T &a){return int(a.size());}
const int MN=7e3+1;
ll arr[MN];
int cnt2[MN];
ll vals[MN*(MN-1)/2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans=0;
    int ptr=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i)vals[ptr++]=arr[i]*arr[j];
            if(arr[j]==arr[i])cnt2[i]++;
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j)ans-=ll(2)*(cnt2[i]-(arr[j]==arr[i]?2:0)+cnt2[j])-2;
    sort(vals,vals+ptr);
    ll last=-1;
    ll cnt=0;
    for(int i=0;i<ptr;i++){
        if(vals[i]!=last){
            ans+=cnt*cnt*4;
            cnt=0;
        }
        last=vals[i];
        cnt++;
    }
    ans+=cnt*cnt*4;
    printf("%lli\n",ans);
    return 0;
}