#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e3+1;
int dist[MN],from[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)dist[i]=INT_MAX,from[i]=-1;
    dist[0]=0,from[0]=-1;
    queue<int> q;
    q.push(0);
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(int i=0;i<=min(k,cur);i++){
            if(k-i<=n-cur){
                if(dist[cur-i+(k-i)]>dist[cur]+1){
                    dist[cur-i+(k-i)]=dist[cur]+1;
                    from[cur-i+(k-i)]=cur;
                    q.push(cur-i+(k-i));
                }
            }
        }
    }
    if(dist[n]==INT_MAX){
        printf("-1\n");
        fflush(stdout);
        return 0;
    }
    vector<int> ord;
    int cur=n;
    ord.push_back(n);
    while(cur){
        cur=from[cur];
        ord.push_back(cur);
    }
    reverse(ord.begin(),ord.end());
    int sum=0;
    vector<int> used,notused;
    for(int i=1;i<=n;i++)notused.push_back(i);
    int a;
    for(int i=1;i<sz(ord);i++){
        printf("?");
        int in=(ord[i-1]+k-ord[i])/2;
        int out=k-in;
        vector<int> toadd;
        for(int j=0;j<in;j++){
            printf(" %d",used.back());
            toadd.push_back(used.back());
            used.pop_back();
        }
        for(int j=0;j<out;j++){
            printf(" %d",notused.back());
            used.push_back(notused.back());
            notused.pop_back();
        }
        for(auto x:toadd)notused.push_back(x);
        toadd=vector<int>();
        printf("\n");
        fflush(stdout);
        cin>>a;
        if(a==-1)return 0;
        sum^=a;
    }
    printf("! %d\n",sum);
    fflush(stdout);
    return 0;
}