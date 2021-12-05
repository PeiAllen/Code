//#include "bits/stdc++.h"
//using namespace std;
//using ll = long long;
//using pii = pair<int,int>;
//using pll = pair<ll,ll>;
//#define A first
//#define B second
//template<typename T> int sz(const T &a){return int(a.size());}
//int cnt[20];
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    string a;
//    int tot=0;
//    int bitcnt=0;
//    while(cin>>a){
//        tot++;
//        bitcnt=sz(a);
//        for(int i=0;i<sz(a);i++){
//            if(a[i]=='1')cnt[i]++;
//        }
//    }
//    ll x=0,y=0;
//    for(int i=0;i<bitcnt;i++){
//        if(cnt[i]+cnt[i]>tot){
//            x=x*2+1;
//            y*=2;
//        }
//        else{
//            x*=2;
//            y=y*2+1;
//        }
//    }
//    printf("%lli\n",x*y);
//    return 0;
//}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

ll solveleast(vector<string> a){
    int bitcnt=sz(a[0]);
    for(int i=0;i<bitcnt;i++){
        vector<string> temp;
        int am=0;
        for(auto x:a){
            am+=x[i]=='1';
        }
        if(am+am<sz(a)){
            for(auto x:a){
                if(x[i]=='1')temp.push_back(x);
            }
        }
        else{
            for(auto x:a){
                if(x[i]!='1')temp.push_back(x);
            }
        }
        a=temp;
    }
    return stoi(a[0],nullptr,2);
}
ll solvemost(vector<string> a){
    int bitcnt=sz(a[0]);
    for(int i=0;i<bitcnt;i++){
        vector<string> temp;
        int am=0;
        for(auto x:a){
            am+=x[i]=='1';
        }
        if(am+am>=sz(a)){
            for(auto x:a){
                if(x[i]=='1')temp.push_back(x);
            }
        }
        else{
            for(auto x:a){
                if(x[i]!='1')temp.push_back(x);
            }
        }
        a=temp;
    }
    return stoi(a[0],nullptr,2);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    string a;
    vector<string> vals;
    while(cin>>a){
        vals.push_back(a);
    }
    printf("%lli\n",(solveleast(vals)*solvemost(vals)));
    return 0;
}