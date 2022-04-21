#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=11;
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string n;
    int k;
    cin>>n>>k;
    for(int i=sz(n)-1;i>=-1;i--){
        for(int j=0;j<10;j++)cnt[j]=0;
        for(int j=0;j<=i;j++){
            cnt[n[j]-'0']++;
        }
        bool work=true;
        for(int j=0;j<10;j++){
            if(cnt[j]>k)work=false;
        }
        if(!work)continue;
        if(i==sz(n)-1){
            printf("%s\n",n.c_str());
            return 0;
        }
        string ans=n;
        work=false;
        for(int j=n[i+1]-'0'+1;j<=9;j++){
            if(cnt[j]+1<=k){
                ans[i+1]='0'+j;
                cnt[j]++;
                bool done=true;
                for(int l=i+2;l<sz(n);l++){
                    bool one=false;
                    for(int p=0;p<10;p++){
                        if(cnt[p]+1<=k){
                            one=true;
                            cnt[p]++;
                            ans[l]='0'+p;
                            break;
                        }
                    }
                    if(!one){
                        done=false;
                        break;
                    }
                }
                if(done){
                    work=true;
                    break;
                }
            }
        }
        if(!work)continue;
        printf("%s\n",ans.c_str());
        return 0;
    }
    for(int j=0;j<10;j++)cnt[j]=0;
    string ans="1";
    cnt[1]++;
    bool work=true;
    for(int j=1;j<=sz(n);j++){
        bool one=false;
        for(int p=0;p<10;p++){
            if(cnt[p]+1<=k){
                one=true;
                cnt[p]++;
                ans.push_back('0'+p);
                break;
            }
        }
        if(!one){
            work=false;
            break;
        }
    }
    if(work){
        printf("%s\n",ans.c_str());
    }
    else printf("-1\n");
    return 0;
}