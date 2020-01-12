#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
map<string,int> dist;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    while(n){
        string a;
        a.resize(n,' ');
        int in;
        string wanted;
        wanted.resize(n,' ');
        dist.clear();
        for(int i=0;i<n;i++){
            sc(in);
            in-=1;
            wanted[i]=i+'0';
            a[in]=i+'0';
        }
        dist[a]=0;
        queue<pair<string,int>> q;
        q.push({a,0});
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            if(cur.first==wanted){
                prl(cur.second);
                break;
            }
            int loc[n];
            int mi[n];
            for(int i=0;i<n;i++)mi[i]=9,loc[i]=cur.first[i]-'0';
            for(int i=0;i<n;i++){
                mi[loc[i]]=min(mi[loc[i]],i);
            }
            for(int i=0;i<n;i++){
                if(mi[loc[i]]==i){
                    if(loc[i]){
                        if(mi[loc[i]-1]>i){
                            loc[i]-=1;
                            string te;
                            te.resize(n,' ');
                            for(int i=0;i<n;i++)te[i]=loc[i]+'0';
                            if(!dist.count(te)){
                                dist[te]=cur.second+1;
                                q.push({te,cur.second+1});
                            }
                            loc[i]+=1;
                        }
                    }
                    if(loc[i]<n-1){
                        if(mi[loc[i]+1]>i){
                            loc[i]+=1;
                            string te;
                            te.resize(n,' ');
                            for(int i=0;i<n;i++)te[i]=loc[i]+'0';
                            if(!dist.count(te)){
                                dist[te]=cur.second+1;
                                q.push({te,cur.second+1});
                            }
                            loc[i]-=1;
                        }
                    }
                }
            }
        }
        if(!dist.count(wanted))prl("IMPOSSIBLE");
        sc(n);
    }
    return 0;
}