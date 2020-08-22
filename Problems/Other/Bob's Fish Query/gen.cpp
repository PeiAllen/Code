#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=10,q=10;
    printf("%d\n",n);
    multiset<ll> nums;
    for(int i=0;i<n;i++){
        ll te=rnd.next(ll(1),ll(1e12));
        nums.insert(te);
        printf("%lli ",te);
    }
    printf("\n");
    printf("%d\n",q);
    while(q--){
        int type=rnd.next(1,3);
        printf("%d ",type);
        if(type==1){
            printf("%lli %lli\n",rnd.next(ll(1),ll(1e12)),rnd.next(ll(1),ll(1e12)));
        }
        else if(type==2){
            ll te=rnd.next(ll(1),ll(1e12));
            nums.insert(te);
            printf("%lli\n",te);
        }
        else{
            int loc=rnd.next(0,sz(nums)-1);
            printf("%lli\n",*next(nums.begin(),loc));
            nums.erase(next(nums.begin(),loc));
        }
    }
    return 0;
}