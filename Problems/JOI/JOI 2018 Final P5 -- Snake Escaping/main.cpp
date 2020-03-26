#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=(1<<20);
int arr[MAXN];
int soson1[MAXN];
int soson0[MAXN];
int cnt[3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int l,q;
    cin>>l>>q;
    string a;
    cin>>a;
    int n=(1<<l);
    for(int i=0;i<n;i++)arr[i]=a[i]-'0',soson1[i]=arr[i],soson0[i]=arr[i];
    for(int i=0;i<l;i++)for(int j=0;j<n;j++){
        if(j&(1<<i))soson1[j]+=soson1[j^(1<<i)];
    }
    for(int i=0;i<l;i++)for(int j=n-1;j>=0;j--){
        if(!(j&(1<<i)))soson0[j]+=soson0[j+(1<<i)];
    }
    while(q--){
        cin>>a;
        reverse(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<3;i++)cnt[i]=0;
        for(char x:a)cnt[(x=='?'?2:x-'0')]++;
        if(cnt[2]<=6){
            int cur=0;
            vector<int> locs;
            for(int i=0;i<sz(a);i++){
                if(a[i]=='?'){
                    locs.push_back(i);
                }
                if(a[i]=='1')cur+=(1<<i);
            }
            for(int i=0;i<(1<<cnt[2]);i++){
                int te=cur;
                for(int j=0;j<cnt[2];j++){
                    if(i&(1<<j))te+=(1<<locs[j]);
                }
                ans+=arr[te];
            }
        }
        else if(cnt[1]<=6){
            int cur=0;
            vector<int> locs;
            for(int i=0;i<sz(a);i++){
                if(a[i]=='1'){
                    locs.push_back(i);
                    cur+=(1<<i);
                }
                if(a[i]=='?')cur+=(1<<i);
            }
            for(int i=0;i<(1<<cnt[1]);i++){
                int te=cur;
                for(int j=0;j<cnt[1];j++){
                    if(i&(1<<j))te-=(1<<locs[j]);
                }
                ans+=(__builtin_popcount(i)%2?-1:1)*soson1[te];
            }
        }
        else{
            int cur=0;
            vector<int> locs;
            for(int i=0;i<sz(a);i++){
                if(a[i]=='0'){
                    locs.push_back(i);
                }
                if(a[i]=='1')cur+=(1<<i);
            }
            for(int i=0;i<(1<<cnt[0]);i++){
                int te=cur;
                for(int j=0;j<cnt[0];j++){
                    if(i&(1<<j))te+=(1<<locs[j]);
                }
                ans+=(__builtin_popcount(i)%2?-1:1)*soson0[te];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}