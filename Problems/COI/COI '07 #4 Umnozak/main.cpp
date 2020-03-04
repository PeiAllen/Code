#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<int> digits;
//lli ways(int dig,int last, lli cur,lli top){
//    for(int i=last;i<=9;i++){
//
//    }
//}
lli am=0;
void cnt(int dig, int last){
    if(dig==18){
        am++;
        break;
    }
    for(int i=last;i<=9;i++){
        cnt(dig+1,i);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cnt(0,0);
    printf("%lli\n")
//    lli a,b;
////    cin>>a>>b;
//    printf("%lli\n",ways(0,0,1,b)-ways(0,0,1,a));
    return 0;
}