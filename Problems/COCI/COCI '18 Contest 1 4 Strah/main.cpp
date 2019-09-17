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
const int MAXN=2001;
char in;
lli dp[MAXN];
lli sumofheights[MAXN];
lli distup[MAXN];
lli prefixsum[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    sc(n,m);
    for(int i=1;i<MAXN;i++)prefixsum[i]=i+prefixsum[i-1];
	lli ans=0;
    for(int i=1;i<=n;i++) {
	    stack<int> st;
	    st.push(0);
	    for (int j = 1; j <= m; j++) {
		    sc(in);
		    if(in=='#')distup[j]=0;
		    else distup[j]+=1;
		    while(st.size()>1&&distup[st.top()]>=distup[j])st.pop();
		    lli le=st.top();
		    dp[j]=prefixsum[(lli)j-le]*prefixsum[distup[j]];
		    dp[j]+=dp[le]+((lli)j-le)*sumofheights[le];
		    ans+=dp[j];
		    sumofheights[j]=((lli)j-le)*prefixsum[distup[j]]+sumofheights[le];
		    st.push(j);
	    }
    }
    pr(ans);
    return 0;
}