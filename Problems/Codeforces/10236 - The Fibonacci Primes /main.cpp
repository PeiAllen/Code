#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli a=1;
    lli b=1;
    vector<lli> list;
    for(int i=1;i<=50;i++){
    	bool work=true;
    	if(a!=1) {
		    for (lli x:list) {
			    if (a % x == 0) {
				    work = false;
			    }
		    }
		    if (work)printf("%d:%lli\n", i,a);
	    }
    	if(a!=1)list.push_back(a);
	    lli c=b;
	    b+=a;
	    a=c;
    }
    return 0;
}