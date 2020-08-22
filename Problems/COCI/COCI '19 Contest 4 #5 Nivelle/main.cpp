#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int firstoccur[27];
bool compare(int a, int b, int c, int d){
    return ll(a)*ll(d)<ll(c)*ll(b);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<pii> ree;
    for(int i=0;i<27;i++)firstoccur[i]=-1,ree.insert({-1,i});
    pair<pii,int> best={{-1,-1},10000000};
    for(int i=0;i<n;i++){
        ree.erase({firstoccur[s[i]-'a'],s[i]-'a'});
        firstoccur[s[i]-'a']=i;
        ree.insert({firstoccur[s[i]-'a'],s[i]-'a'});
        auto it=prev(ree.end(),2);
        for(int j=1;j<=26;j++){
            if(compare(j,i-(it->first+1)+1,best.second,best.first.second-best.first.first+1)){
                best={{it->first+1,i},j};
            }
            it--;
        }
    }
    printf("%d %d\n",best.first.first+1,best.first.second+1);
    return 0;
}