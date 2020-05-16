#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int hydro=d;
    if((2*a+4*b+6*c+d)%4!=0){
        printf("invalid\n");
        return 0;
    }
    int carbo=(2*a+4*b+6*c+d)/4;
    if(carbo+hydro-1==a+b+c+d){
        printf("C%dH%d\n",carbo,hydro);
    }
    else{
        printf("invalid\n");
        return 0;
    }
    return 0;
}