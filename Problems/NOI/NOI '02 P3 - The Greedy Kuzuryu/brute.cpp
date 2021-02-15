#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ld, int>;
const int MM = 305;
const ld eps = 1e-7;

pii operator+(pii a, pii b){
    return {a.first+b.first, a.second+b.second};
}

ld C;
int n, m, k;
pii dp[MM][2];
vector<pair<int, int>> adj[MM];

void dfs(int cur, int pre){

    dp[cur][0] = pii(-C, 1);
    dp[cur][1] = pii(0, 0);

    for(auto [u, w]: adj[cur]){
        if(u == pre) continue;
        dfs(u, cur);
        dp[cur][0] = dp[cur][0] + min(dp[u][1], dp[u][0]+pii(w, 0));
        dp[cur][1] = dp[cur][1] + min(dp[u][0], dp[u][1]+pii(w*(m == 2), 0));
    }
    // pr("dfs", cur, dp[cur][0].first, dp[cur][0].second, "|", dp[cur][1].first, dp[cur][1].second);
}

int main(){
    scan(n, m, k);
    for(int i = 0,a,b,c; i < n-1; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    if(k+m-1 > n){
        print(-1);
        return 0;
    }

    ld lo = -1e35, mid, hi = 1e35;
    while(lo+eps < hi){
        mid = (lo+hi)/2;
        C = mid;
        // pr("go", C);
        dfs(1, 0);
        // pr("k", dp[1][0].second);
        if(dp[1][0].second < k)
            lo = mid+eps;
        else
            hi = mid-eps;
    }
    C = lo;
    dfs(1, 0);
    // pr(lo, dp[1][0].first, dp[1][0].second);
    // print(lo, dp[1][0].first, dp[1][0].second);
    print((ll)roundl(dp[1][0].first) + k*(ll)roundl(C));
}