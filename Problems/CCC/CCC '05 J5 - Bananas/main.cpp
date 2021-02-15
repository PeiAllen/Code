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
    string a;
    cin>>a;
    while(a!="X"){
        int cnt=0;
        bool work=true;
        for(int i=sz(a)-1;i>=0&&work;i--){
            if(a[i]=='S'){
                cnt++;
                if(!(i-1>=0&&(a[i-1]=='A'||a[i-1]=='S')))work=false;
            }
            else if(a[i]=='A'){
                if(!(i-1<0||a[i-1]=='N'||a[i-1]=='B'))work=false;
            }
            else if(a[i]=='B'){
                cnt--;
                if(!(i-1<0||a[i-1]=='N'||a[i-1]=='B'))work=false;
            }
            else if(a[i]=='N'){
                if(!(i-1>=0&&(a[i-1]=='A'||a[i-1]=='S')))work=false;
            }
            else work=false;
            if(cnt<0){
                work=false;
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
        cin>>a;
    }
    return 0;
}