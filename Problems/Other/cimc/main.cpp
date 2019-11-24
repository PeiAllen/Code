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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long double nums[3]={9,19,25};
    long double cnt[3]={1,1,1};
    vector<int> th;
    rep(i,0,2019){
    	long double thi[3]={nums[0]/cnt[0],nums[1]/cnt[1],nums[2]/cnt[2]};
    	if(thi[2]>thi[1]&&thi[2]>thi[0]){
    		prl("R");
    		cnt[2]+=1;
    	}
    	else if(thi[1]>thi[0]){
    		prl("M");
    		cnt[1]+=1;
    	}
    	else{
    		prl("L");
    		th.push_back(i);
    		cnt[0]+=1;
    	}
    }
    int last=0;
    for(int x:th){
    	prl(x-last);
    	last=x;
    }
    return 0;
}