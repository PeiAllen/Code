#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int val[27];
int cnt[27];
int tecnt[27];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>k;
    char a;
    for(int i=0;i<k;i++){
        cin>>a;
        cin>>val[a-'a']>>cnt[a-'a'];
    }
    int n;
    cin>>n;
    string s;
    int ans=0;
    for(int i=0;i<n;i++){
        vector<int> todel;
        cin>>s;
        int sum=0;
        bool work=true;
        for(auto x:s){
            todel.push_back(x-'a');
            tecnt[x-'a']++;
            if(tecnt[x-'a']>cnt[x-'a'])work=false;
            sum+=val[x-'a'];
        }
        if(work)ans=max(ans,sum);
        for(int x:todel)tecnt[x]=0;
    }
    printf("%d\n",ans);
    return 0;
}