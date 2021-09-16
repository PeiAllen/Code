#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("weak_typing_chapter_1_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int n;
        string a;
        cin>>n>>a;
        string b;
        for(auto x:a){
            if(x!='F'&&(SZ(b)==0||x!=b.back()))b.push_back(x);
        }
        printf("Case #%d: %d\n",cs,max(0,SZ(b)-1));
    }
    return 0;
}