#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
pll arr[MAXN];
pll angles[3*MAXN];
lli len[3*MAXN];
int lcp[3*MAXN];
int n;
lli dist(lli a,lli b){
    return (arr[a].first-arr[b].first)*(arr[a].first-arr[b].first)+(arr[a].second-arr[b].second)*(arr[a].second-arr[b].second);
}
lli gcd(lli a,lli b){
    return (b<0?-1:1)*__gcd(abs(a),abs(b));
}
int fix(int a){
    if(a<0)a+=n;
    return a%n;
}
bool same(int a, int b){
    return angles[a]==angles[b]&&len[a]==len[b];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        lli gc=0;
        for(int i=0;i<n;i++){
            len[i]=dist(i,fix(i+1));
            gc=__gcd(gc,len[i]);
            angles[i].first=dist(i,fix(i+1))+dist(i,fix(i-1))-dist(fix(i-1),fix(i+1));
            angles[i].first*=angles[i].first;
            angles[i].second=4*dist(i,fix(i+1))*dist(i,fix(i-1));
            if(angles[i].first==0&&angles[i].second!=0)angles[i].second=1;
            if(angles[i].first!=0) {
                lli cf = gcd(angles[i].first, angles[i].second);
                angles[i].first /= cf, angles[i].second /= cf;
            }
        }
        if(gc){
            for(int i=0;i<n;i++)len[i]/=gc;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        gc=0;
        len[n]=-1;
        angles[n]={-1,-1};
        for(int i=0;i<n;i++){
            len[i+n+1]=dist(i,fix(i+1));
            len[i+2*n+1]=len[i+n+1];
            gc=__gcd(gc,len[i+n+1]);
            angles[i+n+1].first=dist(i,fix(i+1))+dist(i,fix(i-1))-dist(fix(i-1),fix(i+1));
            angles[i+n+1].first*=angles[i+n+1].first;
            angles[i+n+1].second=4*dist(i,fix(i+1))*dist(i,fix(i-1));
            if(angles[i+n+1].first==0&&angles[i+n+1].second!=0)angles[i+n+1].second=1;
            if(angles[i+n+1].first!=0) {
                lli cf = gcd(angles[i+n+1].first, angles[i+n+1].second);
                angles[i+n+1].first /= cf, angles[i+n+1].second /= cf;
            }
            angles[i+2*n+1]=angles[i+n+1];
        }
        if(gc){
            for(int i=0;i<n;i++){
                len[i+n+1]/=gc;
                len[i+2*n+1]/=gc;
            }
        }
        bool work=false;
        for(int i=1;i<=3*n;i++){
            int cur=lcp[i-1];
            while(cur>0&&!same(i,cur))cur=lcp[cur-1];
            if(same(i,cur))cur++;
            lcp[i]=cur;
            if(i>=2*n&&lcp[i]==n){
                printf("%d\n",i-2*n+1);
                work=true;
                break;
            }
        }
        assert(lcp[n]==0);
        if(!work)printf("%d\n",0);
    }
    return 0;
}