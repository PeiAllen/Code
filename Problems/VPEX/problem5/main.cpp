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
lli gcd(lli a,lli b){
    if(a==0)return b;
    return gcd(b%a,a);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli w,h,a,b,x,y,xd,yd;
    cin>>w>>h>>a>>b>>x>>y>>xd>>yd;
    lli abxd=xd,abyd=yd;
   // w-=1,h-=1;
    lli gc=gcd(abs(xd),abs(yd));
    xd/=gc,yd/=gc;
///    assert(xd!=0&&yd!=0);
    //assert(xd>=0&&yd>=0);
    //  x-=a,y-=b;
//     while(xd<0)xd+=w;
//lli mut=1;
//if(xd<0)mut=-1,xd*=-1;
//    xd%=w;
//    xd*=mut;
////    while(yd<0)yd+=h;
//mut=1;
//    if(yd<0)mut=-1,yd*=-1;
//    yd%=h;
//    yd*=mut;
    lli cur=1;
    while(1){
        if(fix((x+xd*cur),w)==(abs((x+xd*cur+w)/w)%2?w-x+a:x)&&fix(y+(yd*cur),h)==(abs((y+yd*cur+h)/h)%2?h-y+b:y)){
            long double time=sqrt((long double)(xd*cur)/gc*(long double)(xd*cur)/gc+(long double)(yd*cur)/gc*(long double)(yd*cur)/gc);
//            time/=(long double)gc;
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
/*
 * 11 11
1 1
5 5
0 1
 */