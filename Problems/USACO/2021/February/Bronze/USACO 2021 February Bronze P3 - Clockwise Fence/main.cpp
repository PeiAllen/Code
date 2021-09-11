#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        pii cur={0,0};
        int leftdist=0,rightdist=0;
        for(auto x:a){
            if(x=='N'){
                cur.first++;
                leftdist=max(leftdist,abs(cur.first)+abs(cur.second-1));
                rightdist=max(rightdist,abs(cur.first)+abs(cur.second+1));
            }
            else if(x=='S'){
                cur.first--;
                leftdist=max(leftdist,abs(cur.first)+abs(cur.second+1));
                rightdist=max(rightdist,abs(cur.first)+abs(cur.second-1));
            }
            else if(x=='E'){
                cur.second++;
                leftdist=max(leftdist,abs(cur.first+1)+abs(cur.second));
                rightdist=max(rightdist,abs(cur.first-1)+abs(cur.second));
            }
            else{
                cur.second--;
                leftdist=max(leftdist,abs(cur.first-1)+abs(cur.second));
                rightdist=max(rightdist,abs(cur.first+1)+abs(cur.second));
            }
        }
        if(leftdist<rightdist)printf("CCW\n");
        else printf("CW\n");
    }
    return 0;
}