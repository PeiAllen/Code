#include "bits/stdc++.h"
#include "Benjamin.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
int finalY=0;
string SendB(int N, int X, int Y){
    int firstbits=(__lg(N+100)+1);
    string s(20,'0');
    int ptr=0;
    for(int i=0;i<firstbits;i++){
        s[ptr++]='0'+(X%2);
        X/=2;
    }
    for(int i=firstbits;i<20;i++){
        s[ptr++]='0'+(Y%2);
        Y/=2;
    }
    finalY=Y;
    return s;
}


int Answer(string T){
    int firstbits=4;
    int ptr=0;
    int numofbits=0;
    int p2=1;
    for(int i=0;i<4;i++){
        numofbits+=(T[ptr++]-'0')*p2;
        p2*=2;
    }
    ptr+=numofbits*finalY;
    int val=0;
    p2=1;
    for(int i=0;i<numofbits;i++){
        val+=(T[ptr++]-'0')*p2;
        p2*=2;
    }
    return val;
}
//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    return 0;
//}