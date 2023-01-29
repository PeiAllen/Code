#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cases;
    cin>>cases;
    for(int cs=1;cs<=cases;cs++){
        int n,k,a;
        cin>>n>>k;
        map<int,int> cnt;
        for(int i=0;i<n;i++){
            cin>>a;
            cnt[a]++;
        }
        int two=0,one=0;
        bool work=true;
        for(auto x:cnt){
            if(x.second==2){
                two++;
            }
            else if(x.second==1){
                one++;
            }
            else{
                work=false;
            }
        }
        printf("Case #%d: ",cs);
        if(!work){
            printf("NO\n");
            continue;
        }
        if((k-two)*2-one>=0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}