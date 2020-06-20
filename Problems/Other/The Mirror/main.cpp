#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
bool nprime[501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    nprime[1]=true;
    for(int i=2;i<=500;i++){
        if(!nprime[i]){
            for(int j=i*i;j<=500;j+=i){
                nprime[j]=true;
            }
        }
    }
    while(n--){
        cin>>a>>b;
        int cnt=0;
        for(int i=a;i<b;i++){
            if(!nprime[i])cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}