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
    lli xe,ye,xh,yh,d;
    sc(xe,ye,xh,yh,d);
    lli dist=abs(xh-xe)+abs(yh-ye);
    if(dist>d){
    	prl("impossible");
    	return 0;
    }
    if(dist%2!=d%2){
    	prl("impossible");
	    return 0;
    }
    if(dist==d){
    	prl(0);
    	return 0;
    }
    if(dist==1){
    	prl("impossible");
    	return 0;
    }
    if(abs(xe-xh)==1&&abs(ye-yh)==1){
    	if(d==4){
		    prl("impossible");
		    return 0;
    	}
		lli needed=d-dist-2;
		if(needed>10000){
			prl("impossible");
			return 0;
		}
		if(xe>xh){
			swap(xe,xh);
			swap(ye,yh);
		}
		prl(needed);
		if(ye<yh){
			rep(i,0,needed/2){
				prl(xe+1,ye-i);
				prl(xe,ye+i+1);
			}
		}
		else{
			rep(i,0,needed/2){
				prl(xe+1,ye+i);
				prl(xe,ye-i-1);
			}
		}
    }
    else{
    	if(xe!=xh){
    		if(xh<xe){
    			swap(xe,xh);
    			swap(ye,yh);
    		}
    		lli diff=(d-dist)/2;
    		lli needed=1+(diff-1)*2+abs(ye-yh);
    		if(needed>10000){
    			prl("impossible");
    			return 0;
    		}
    		else{
    			prl(needed);
    			prl(xe+1,ye);
    			rep(i,1,diff){
    				prl(xe+1,ye+i);
				    prl(xe+1,ye-i);
    			}
    			if(ye<yh){
    				rep(i,diff,diff+abs(ye-yh)){
					    prl(xe+1,ye+i);
    				}
    			}
    			else{
				    rep(i,diff,diff+abs(ye-yh)){
					    prl(xe+1,ye-i);
				    }
    			}
    		}
    	}
    	else{
		    if(yh<ye){
			    swap(xe,xh);
			    swap(ye,yh);
		    }
		    lli diff=(d-dist)/2;
		    lli needed=1+(diff-1)*2+abs(xe-xh);
		    if(needed>10000){
			    prl("impossible");
			    return 0;
		    }
		    else{
			    prl(needed);
			    prl(xe,ye+1);
			    rep(i,1,diff){
				    prl(xe+i,ye+1);
				    prl(xe-i,ye+1);
			    }
			    if(xe<xh){
				    rep(i,diff,diff+abs(xe-xh)){
					    prl(xe+i,ye+1);
				    }
			    }
			    else{
				    rep(i,diff,diff+abs(xe-xh)){
					    prl(xe-i,ye+1);
				    }
			    }
		    }
    	}
    }
    return 0;
}