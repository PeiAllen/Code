#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
const ll MV=1e12;
int arr[MN];
ll hashval[MN];
ll psum[MN];
ll bit[MN];
        int n;
void update(int loc, ll val){
    for(;loc<=n;loc+=loc&-loc){
        bit[loc]+=val;
    }
}
ll query(int loc){
    ll sum=0;
    for(;loc>0;loc-=loc&-loc){
        sum+=bit[loc];
    }
    return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    uniform_int_distribution<ll> numgen(0,MV);
    mt19937_64 gen(4382498328748923);
   
    for(int cs=1;cs<=t;cs++){
         unordered_set<ll> store;
        for(int i=0;i<=1e6;i++){
            hashval[i]=numgen(gen);
            store.insert(hashval[i]);
            bit[i]=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            update(i,hashval[arr[i]]);
        }
        int q;
        cin>>q;
        int l,r;
        int ans=0;
        int type;
        while(q--){
            cin>>type>>l>>r;
            if(type==2){
                if((r-l+1)%2==1){
                    int mid=(r+l)/2;
                    int off=0;
                    ll midval=query(mid),lvalue=query(l-1),rvalue=query(r);
                    ll res=midval-lvalue-(rvalue-midval);
                    if(store.count(res)){
                        ans++;
                    }
                    else{
                        mid--;
                        midval=query(mid);
                        res=(rvalue-midval)-(midval-lvalue);
                        if(store.count(res)){
                            ans++;
                        }
                    }
                }
            }
            else{
                update(l,-hashval[arr[l]]);
                arr[l]=r;
                update(l,hashval[arr[l]]);
            }
        }
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}


/*
so realy jsut check even.
determine if the set of characters in the start is the same as the set of characters in the end. 
    26*1e6??
    or 
odd case:
    if delete in front, or delete in back
        so either the middle is included in left or giht
            and then check if you can delete a character to make it match.
            solves 26*q

check if the count for two subarrays is the same??
oh give each number a hash lmfao im stupid and xor.
uhh to check which one to delete..
if xor result is a number.

mmo?
line sweep.
*/