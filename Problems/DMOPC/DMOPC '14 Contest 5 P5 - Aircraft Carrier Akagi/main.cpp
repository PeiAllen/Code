#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
ll arr[MAXN];
ll bit[2][4*MAXN];
ll bitsum[2][4*MAXN];
void update(int ind, int loc, ll val){
    for(;loc<=8e5;loc+=loc&-loc)bit[ind][loc]+=val;
}
ll query(int ind, int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[ind][loc];
    return sum;
}
void updatesum(int ind, int loc, ll val){
    for(;loc<=8e5;loc+=loc&-loc)bitsum[ind][loc]+=val;
}
ll querysum(int ind, int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bitsum[ind][loc];
    return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=2e5;
    }
    if(1>=k){
        printf("0\n");
        return 0;
    }
    ll ans=LLONG_MAX;
    if(n>=3){
        update(0,arr[1]-1,1);
        update(1,arr[3]+3,1);
        updatesum(0,arr[1]-1,arr[1]-1);
        updatesum(1,arr[3]+3,arr[3]+3);
        if(3>=k){
            ll lo=2e5+1,hi=6e5;
            while(lo!=hi){
                ll mid=(lo+hi)/2;
                ll am=query(0,mid-2)+query(1,mid+2)+(arr[2]<=mid?1:0);
                if(am>=2)hi=mid;
                else lo=mid+1;
            }
            ll leftcnt=query(0,lo-2),leftsum=querysum(0,lo-2);
            ll teleft=leftcnt*(lo-2)-leftsum+querysum(0,8e5)-leftsum-(query(0,8e5)-leftcnt)*(lo-2);
            ll rightcnt=query(1,lo+2),rightsum=querysum(1,lo+2);
            ll teright=rightcnt*(lo+2)-rightsum+querysum(1,8e5)-rightsum-(query(1,8e5)-rightcnt)*(lo+2);
            ans=min(ans,teleft+teright+abs(lo-arr[2]));
        }
    }
    for(ll i=3;i-1+i<=n;i++){
        update(0,arr[i-1]-(i-1),1);
        update(1,arr[i]+i,-1);
        update(1,arr[i-1+i]+(i-1+i),1);
        update(1,arr[i-2+i]+(i-2+i),1);
        updatesum(0,arr[i-1]-(i-1),arr[i-1]-(i-1));
        updatesum(1,arr[i]+i,-(arr[i]+i));
        updatesum(1,arr[i-1+i]+(i-1+i),arr[i-1+i]+(i-1+i));
        updatesum(1,arr[i-2+i]+(i-2+i),arr[i-2+i]+(i-2+i));
        if(i-1+i>=k){
            ll lo=2e5+1,hi=6e5;
            while(lo!=hi){

                ll mid=(lo+hi)/2;
                ll am=query(0,mid-i)+query(1,mid+i)+(arr[i]<=mid?1:0);
                if(am>=i)hi=mid;
                else lo=mid+1;
            }
            ll leftcnt=query(0,lo-i),leftsum=querysum(0,lo-i);
            ll teleft=leftcnt*(lo-i)-leftsum+querysum(0,8e5)-leftsum-(query(0,8e5)-leftcnt)*(lo-i);
            ll rightcnt=query(1,lo+i),rightsum=querysum(1,lo+i);
            ll teright=rightcnt*(lo+i)-rightsum+querysum(1,8e5)-rightsum-(query(1,8e5)-rightcnt)*(lo+i);
            ans=min(ans,teleft+teright+abs(lo-arr[i]));
        }
    }
    if(ans==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",ans);
    return 0;
}