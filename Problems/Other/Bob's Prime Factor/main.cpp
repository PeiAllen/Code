#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int mpf(int a){
    int best=1;
    for(int i=2;i*i<=a;i++){
        while(a%i==0){
            best=max(best,i);
            a/=i;
        }
    }
    if(a!=1)best=max(best,a);
    return best;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    pii best={-1,0};
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        int te=mpf(a);
        if(te>best.second)best={a,te};
    }
    printf("%d\n",best.first);
    return 0;
}