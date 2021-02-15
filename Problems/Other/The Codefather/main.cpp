#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e3+1;
int arr[MAXN];
int n;
bool able(int largest){
    vector<int> smaller,larger;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[0])larger.push_back(arr[i]-arr[0]+1);
        else smaller.push_back(arr[i]);
    }
    sort(smaller.begin(),smaller.end());
    smaller.push_back(arr[0]-1);
    for(int x:larger){
        vector<int> newsmaller;
        int cur=smaller[0];
        for(int i=0;i<sz(smaller)-1&&x;){
            while(x/(i-sz(newsmaller)+1)==0)newsmaller.push_back(cur);
            cur=max(cur,smaller[i]);
            int addam=min({smaller[i+1]-cur,x/(i-sz(newsmaller)+1),largest-(cur-smaller[sz(newsmaller)])});
            cur+=addam;
            x-=addam*(i-sz(newsmaller)+1);
            while(sz(newsmaller)<=i&&cur-smaller[sz(newsmaller)]==largest)newsmaller.push_back(cur);
            while(cur==smaller[i+1]||i-sz(newsmaller)+1==0)i++;
        }
        while(sz(newsmaller)<sz(smaller))newsmaller.push_back(max(cur,smaller[sz(newsmaller)]));
        smaller=newsmaller;
        if(x)return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    if(!able(1e6)){
        printf("impossible\n");
        return 0;
    }
    int lo=0;
    int hi=1e6;
    while(lo!=hi){

        int mid=(lo+hi)/2;
        if(able(mid))hi=mid;
        else lo=mid+1;
    }
    printf("%d\n",lo);
    return 0;
}