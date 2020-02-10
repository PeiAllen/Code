#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli fix(lli a, lli b){
    if(a<0){
        lli te=abs(a/b);
        a+=b*te;
    }
    while(a<0)a+=b;
    return a%b;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli w,h,a,b,x,y,xd,yd;
    cin>>w>>h>>a>>b>>x>>y>>xd>>yd;
    lli abxd=xd,abyd=yd;
    w-=1,h-=1;
  //  x-=a,y-=b;
   // while(xd<0)xd+=w;
//    xd%=w;
   // while(yd<0)yd+=h;
//    yd%=h;
    lli cur=1;
    while(1){
        if(fix((xd*cur),w)==0&&fix((yd*cur),h)==0){
            long double time=sqrt((long double)(abxd*cur)*(long double)(abxd*cur)+(long double)(abyd*cur)*(long double)(abyd*cur));
            if((xd*cur/w)%2||(yd*cur/w)%2)time*=2;
            string ans=to_string(time);
            int loc=0;
            while(ans[loc]=='0'||ans[loc]=='.')loc++;
            int am=0;
            for(int i=loc;i<(int)ans.size();i++){
                if(ans[i]!='.'){
                    cout<<ans[i];
                    am++;
                }
                if(am==6)break;
            }
            assert(am==6);
            return 0;
        }
        cur++;
    }
    return 0;
}