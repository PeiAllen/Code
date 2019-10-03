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
    int n;
    sc(n);
    while(n--){
    	string s,t;
    	sc(s,t);
    	if(t.size()==1){
    		if(s.size()%2){
			    bool done=false;
    			rep(i,max(0,(int)s.size()/2-1),(int)min((int)s.size(),(int)s.size()/2+2)){
    				if(s[i]==t[0]){
    					prl("William");
    					done=true;
    					break;
    				}
    			}
			    if(done)continue;
    		}
		    else{
		    	bool done=false;
			    rep(i,max(0,(int)s.size()/2-1),(int)min((int)s.size(),(int)s.size()/2+1)){
				    if(s[i]==t[0]){
					    prl("William");
					    done=true;
					    break;
				    }
			    }
			    if(done)continue;
		    }
    	}
    	int in=((int)s.size()-(int)t.size())/2;
    	if(((int)s.size()-(int)t.size())%2){
    		int cnt=0;
		    if(s.substr(in,(int)t.size())==t) cnt+=1;
		    if(s.substr(in + 1, (int) t.size()) == t)cnt+=1;
			if(cnt>=2)prl("William");
			else prl("Andrew");
	    }
	    else{
		    if (s.substr(in, (int) t.size()) == t)prl("William");
		    else if (in>0&&s.substr(in-1, (int) t.size()) == t&&s.substr(in+1, (int) t.size()) == t)prl("William");
		    else prl("Andrew");
	    }
    }
    return 0;
}