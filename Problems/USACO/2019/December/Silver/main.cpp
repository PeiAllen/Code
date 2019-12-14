#include <bits/stdc++.h>
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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("meetings.in","r",stdin);
    freopen("meetings.out","w",stdout);
    int n,l;
    sc(n,l);
    pair<int,pii> total[n];
    vector<int> pos[2];//1 is left
    int b;
    int a,c;
    int sumw=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> barn;
    rep(i,0,n){
        sc(a,b,c);
        sumw+=a;
        if(c<0){
            pos[1].push_back(b);
            barn.push({b,1});
        }
        else{
            pos[0].push_back(b);
            barn.push({l-b,0});
        }
        total[i]={b,{a,c}};
    }
    sort(total,total+n);
    sort(pos[0].begin(),pos[0].end());
    sort(pos[1].begin(),pos[1].end());
    int sofarw=0;
    sumw=(sumw+1)/2;
    int T=0;
    int lp=0;
    int rp=n-1;
    while(sofarw<sumw){
        auto cur=barn.top();
        barn.pop();
        T=cur.first;
        if(cur.second==1){
            sofarw+=total[lp].second.first;
            lp++;
        }
        else{
            sofarw+=total[rp].second.first;
            rp--;
        }
    }
    T=T*2;
    lli cnt=0;
    for(int x:pos[1]){
        int l=x-T;
        cnt+=lower_bound(pos[0].begin(),pos[0].end(),x)-lower_bound(pos[0].begin(),pos[0].end(),l);
    }
    prl(cnt);
    return 0;
}