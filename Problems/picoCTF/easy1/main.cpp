#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    char arr[26][26];
    rep(i,0,26){
    	rep(j,0,26)sc(arr[i][j]);
    }
    string a,b;
    sc(a,b);
    rep(i,0,a.size()){
    	pr(arr[a[i]-'A'][b[i]-'A']);
    }
    return 0;
}
d35cr4mbl3_tH3_cH4r4cT3r5_6355f9
sT1tcHiNg_5tr1nGs_t0g3th3r_eaf92
jU5t_a_s
arr[30]='9',arr[28]='g',arr[26]='a',arr[24]='4',arr[22]='a',arr[20]='_',arr[18]='u',arr[16]='_'
arr[15]='n',arr[14]='a',arr[13]='_',arr[12]='3',arr[11]='l',arr[10]='p',arr[9]='m',arr[8]='1'
arr[15]='m',arr[14]='a',arr[13]='_',arr[12]='3',arr[11]='l',arr[10]='p',arr[9]='m',arr[8]='1'