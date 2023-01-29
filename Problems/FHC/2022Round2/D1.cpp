#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
ll bit[4][MN];
int arr[MN];
int n;
void update(int ind, int loc, ll val){
    for(;loc<=n;loc+=loc&-loc){
        bit[ind][loc]+=val;
    }
}
ll query(int ind, int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc){
        sum+=bit[ind][loc];
    }
    return sum;
}
ll solve(int total, int mid){
    vector<int> left,right;
    left.push_back(0),right.push_back(0);
    int leftsum=0;
    for(int i=1;i<=2;i++){
        left.push_back(query(i,mid));
        leftsum+=i*left.back();
        right.push_back(query(i,n)-query(i,mid));
    }
    if(total%2==1)return -1;
    int wanted=total/2;
    if(wanted==leftsum)return 0;
    if(leftsum<=wanted){
        int needed=wanted-leftsum;
        if(right[2]<needed)return -1;
        int lo=mid+1,hi=n;
        while(lo!=hi){
            int mi=(lo+hi)/2;
            if(query(2,mi)-left[2]>=needed)hi=mi;
            else lo=mi+1;
        }
        int rightside=lo;
        if(left[1]<needed)return -1;
        lo=1,hi=mid;
        while(lo!=hi){
            int mi=(lo+hi+1)/2;
            if(left[1]-query(1,mi-1)>=needed)lo=mi;
            else hi=mi-1;
        }
        int leftside=lo;
        ll totaltwos=query(2,rightside)-query(2,leftside-1);
        return query(3,rightside)-query(3,leftside-1)-(totaltwos*(leftside-1)+(totaltwos)*(totaltwos+1)/2);
    }
    else{
        int needed=leftsum-wanted;
        if(left[2]<needed)return -1;
        int lo=1,hi=mid;
        while(lo!=hi){
            int mi=(lo+hi+1)/2;
            if(left[2]-query(2,mi-1)>=needed)lo=mi;
            else lo=mi-1;
        }
        int leftside=lo;
        if(right[1]<needed)return -1;
        lo=mid+1,hi=n;
        while(lo!=hi){
            int mi=(lo+hi)/2;
            if(query(2,mi)-left[1]>=needed)hi=mi;
            else lo=mid+1;
        }
        int rightside=lo;
        ll totaltwos=query(2,rightside)-query(2,leftside-1);
        return (totaltwos*(rightside+1)-(totaltwos)*(totaltwos+1)/2)-(query(3,rightside)-query(3,leftside-1));
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int m;
        cin>>n>>m;
        for(int i=0;i<=n;i++)bit[0][i]=bit[1][i]=bit[2][i]=bit[3][i]=0;
        ll sum=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sum+=arr[i];
            update(arr[i],i,1);
            if(arr[i]==2){
                update(3,i,i);
            }
        }
        int a,b,c;
        ll ans=0;
        while(m--){
            cin>>a>>b>>c;
            update(arr[a],a,-1);
            if(arr[a]==2){
                update(3,a,-a);
            }
            sum-=arr[a];
            arr[a]=b;
            sum+=arr[a];
            update(arr[a],a,1);
            if(arr[a]==2){
                update(3,a,a);
            }
            ans+=solve(sum,c);
        }
        printf("Case #%d: %lli\n",cs,ans);
    }
    return 0;
}
