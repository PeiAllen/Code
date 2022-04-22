#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int bit[MN],n;
ll bit2[MN];
void updatesum(int loc, ll val){
    for(;loc<=n;loc+=loc&-loc)bit2[loc]+=val;
}
ll querysum(int loc){
    ll am=0;
    for(;loc>0;loc-=loc&-loc)am+=bit2[loc];
    return am;
}
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int am=0;
    for(;loc>0;loc-=loc&-loc)am+=bit[loc];
    return am;
}
int getkth(int am){//returns index of first element with prefix sum == am
    int loc=0;
    for(int i=__lg(n);i>=0;i--){
        if(loc+(1<<i)<=n&&bit[loc+(1<<i)]<am){
            loc+=(1<<i);
            am-=bit[loc];
        }
    }
    return loc+1;
}
int query2(int curi, ll k){
    int loc=0;
    ll less=0;
    for(int i=__lg(n);i>=0;i--){
        if(loc+(1<<i)<=n){
            ll indexcur=less+bit[loc+(1<<i)];
            ll largeram=(n-curi+1)-indexcur;
            if(largeram*ll(n-(loc+(1<<i))-largeram)>k){
                loc+=(1<<i);
                less+=bit[loc];
            }
        }
    }
    return loc;
}
int query3(int curi){
    int loc=0;
    ll less=0;
    for(int i=__lg(n);i>=0;i--){
        if(loc+(1<<i)<=n){
            ll indexcur=less+bit[loc+(1<<i)];
            ll largeramfree=(n-curi+1)-indexcur;
            ll largeramset=n-(loc+(1<<i))-largeramfree;
            if(largeramset<=largeramfree){
                loc+=(1<<i);
                less+=bit[loc];
            }
        }
    }
    return loc;
}
ll psa[MN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        update(i,1),updatesum(i,i);
        psa[i]=psa[i-1]+ll(i/2)*ll(i-i/2);
    }
    bool done=false;
    for(int i=1;i<=n;i++){
        int startingindex=query(query2(i,k))+1;
        for(int j=startingindex;j<=n-i+1;j++){
            int val=getkth(j);
            ll mi=ll(n-i+1-j)*ll(n-val-(n-i+1-j));
            ll ma=mi;
            update(val,-1);
            updatesum(val,-val);
            int splitpoint=query(query3(i));
            ma+=psa[n-i+1-1]-psa[n-i+1-splitpoint-1];

            update(val,1);
            updatesum(val,val);
            if(ma<k)continue;
            printf("%d%c",val," \n"[i==n]);
            k-=mi;
            update(val,-1);
            updatesum(val,-val);
            done=true;
            break;
        }
    }
    if(!done)printf("-1\n");
    return 0;
}