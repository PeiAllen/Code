#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef complex<long double> cld;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int arr[MAXN];
bool cent[MAXN];
cld precalc[2][18][MAXN];
int flip[18][2*MAXN];
int sts[MAXN];
long double pi=acos(-1);
vector<int> matrix[MAXN];
int dfss(int loc, int parent){
    sts[loc]=1;
    for(int x:matrix[loc])if(x!=parent&&!cent[x])sts[loc]+=dfss(x,loc);
    return sts[loc];
}
int dest(int loc, int parent,int size){
    for(int x:matrix[loc]){
        if(x!=parent&&!cent[x]&&sts[x]>size)return dest(x,loc,size);
    }
    return loc;
}
lli ans[MAXN];
vector<vector<lli>> paths;
void dfs(int loc, int parent, int val, int ind){
    val+=arr[loc];
    if(val>=sz(paths[ind]))paths[ind].resize(val+1);
    paths[ind][val]+=1;
    for(int x:matrix[loc]){
        if(x!=parent&&!cent[x])dfs(x,loc,val,ind);
    }
}
void dft(vector<cld>& a, bool inv){
    int lg=log2(sz(a));
    for(int i=1;i<sz(a);i++){
        if(flip[lg][i]>i)swap(a[i],a[flip[lg][i]]);
    }
    for(int lay=1;lay<=lg;lay++){
        int t=(1<<lay);
        for(int i=0;i<sz(a);i+=t){
            for(int j=0;j<t/2;j++){
                cld u=a[i+j], v=precalc[inv][lay][j]*a[i+j+t/2];
                a[i+j]=u+v,a[i+j+t/2]=u-v;
            }
        }
    }
    if(inv){
        for(int i=0;i<sz(a);i++)a[i]/=sz(a);
    }
}
void fft(int at, int bt, vector<lli>& fin){
    vector<cld> a(paths[at].begin(),paths[at].end()),b(paths[bt].begin(),paths[bt].end());
    int n=1;
    while(n<sz(a)+sz(b))n<<=1;
    a.resize(n),b.resize(n);
    dft(a,0),dft(b,0);
    for(int i=0;i<n;i++)a[i]*=b[i];
    dft(a,1);
    fin.resize(n);
    for(int i=0;i<n;i++)fin[i]=round(a[i].real());
}
void deft(int loc) {
    int next = dest(loc, 0, dfss(loc, 0) / 2);
    cent[next] = true;
    for (int x:matrix[next]) {
        if (!cent[x]) {
            paths.push_back({});
            dfs(x, 0, 0, sz(paths) - 1);
        }
    }
    if (sz(paths)) {
        int add = arr[next];
        sort(paths.begin(), paths.end(), [&](auto lhs, auto rhs) {
            return sz(lhs) < sz(rhs);
        });//thus the polynomial of i-1 is always smaller than or equal polynomial of i so calculation time for i is the depth of i worst case
        for (int j = 0; j < sz(paths[0]); j++) {
            ans[j + add] += paths[0][j];
        }
        for (int i = 1; i < sz(paths); i++) {
            for (int j = 0; j < sz(paths[i]); j++) {
                ans[j + add] += paths[i][j];
            }
            vector<lli> fin;
            fft(i, i - 1, fin);
            for (int j = 0; j < sz(fin); j++)ans[j + add] += fin[j];
            for (int j = 0; j < sz(paths[i - 1]); j++)paths[i][j] += paths[i - 1][j];
        }
        paths.clear();
        for(int x:matrix[next]){
            if(!cent[x])deft(x);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<2;i++){
        for(int j=1;j<18;j++) {
            long double ang = 2 * pi / (1<<j) * (i ? -1 : 1);
            cld mut(cos(ang), sin(ang));
            cld cur(1);
            for(int k=0;k<(1<<(j-1));k++){
                precalc[i][j][k]=cur;
                cur*=mut;
            }
        }
    }
    for(int i=1;i<18;i++){
        int k=0;
        for(int j=0;j<(1<<i);j++){
            flip[i][j]=k;
            int b=(1<<(i-1));
            for(;k&b;b>>=1)k^=b;
            k^=b;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    deft(1);
    for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
    int q;
    cin>>q;
    while(q--){
        cin>>a>>b;
        printf("%lli\n",ans[b]-(a-1>=0?ans[a-1]:0));
    }
    return 0;
}
