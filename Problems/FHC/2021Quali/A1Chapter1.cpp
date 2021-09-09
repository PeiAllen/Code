#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
set<char> vowels={'A','E','I','O','U'};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("consistency_chapter_1_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        string s;
        cin>>s;
        int best=INT_MAX;
        for(char i='A';i<='Z';i++){
            int am=0;
            for(auto x:s){
                if(x==i)continue;
                if(vowels.count(x)==vowels.count(i))am+=2;
                else am+=1;
            }
            best=min(best,am);
        }
        printf("Case #%d: %d\n",cs,best);
    }
    return 0;
}