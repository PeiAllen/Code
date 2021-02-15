#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXL=1e6+1;
int n,w,h;
int ans;
bool create[MAXL];
void check(int x, int y){
    if(x%w&&x%h)return;
    if(x%w==0&&x%h==0){
        if(create[y])ans=min(ans,2*(x+y));
        return;
    }
    if(x%h==0)swap(w,h);
    if(y%h==0)ans=min(ans,2*(x+y));
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ans=INT_MAX;
        cin>>n>>w>>h;
        int totarea=w*h*n;
        create[0]=true;
        for(int i=1;i<MAXL;i++){
            create[i]=false;
            if(i>=w)create[i]|=create[i-w];
            if(i>=h)create[i]|=create[i-h];
        }
        for(int i=1;i*i<=totarea;i++){
            if(totarea%i==0){
                int othlen=totarea/i;
                check(i,othlen),check(othlen,i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}