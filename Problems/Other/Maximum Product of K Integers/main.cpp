#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXL=1e6+1e5;
typedef complex<double> cd;
cd precalc[5][6][MAXL];
int flip[6][2*MAXL];
double pi=acos(-1);
void dft(vector<cd>& a, bool inv){
    int lg=log2(sz(a));
    if(lg>=14) {
        for (int i = 1; i < sz(a); i++) {
            if (flip[lg-14][i] > i)swap(a[i], a[flip[lg-14][i]]);
        }
    }
    else {
        for (int i = 0, j = 0; i < sz(a); i++) {
            if (j > i)swap(a[i], a[j]);
            int b = sz(a) >> 1;
            for (; j & b; b >>= 1)j ^= b;
            j ^= b;
        }
    }
    int ind=1;
    for(int lay=2;lay<=sz(a);lay<<=1){
        if(ind>=14){
            for(int i=0;i<sz(a);i+=lay){
                for(int j=0;j<lay/2;j++){
                    cd u=a[i+j], v=precalc[inv][ind-14][j]*a[i+j+lay/2];
                    a[i+j]=u+v,a[i+j+lay/2]=u-v;
                }
            }
        }
        else {
            long double ang = 2 * pi / lay * (inv ? -1 : 1);
            cd mut(cos(ang), sin(ang));
            for (int i = 0; i < sz(a); i += lay) {
                cd cur(1);
                for (int j = 0; j < lay / 2; j++) {
                    cd u = a[i + j], v = cur * a[i + j + lay / 2];
                    a[i + j] = u + v, a[i + j + lay / 2] = u - v;
                    cur *= mut;
                }
            }
        }
        ind++;
    }
    if(inv){
        for(int i=0;i<sz(a);i++)a[i]/=sz(a);
    }
}
vector<vector<int>> tomut;
void fft(int at, int bt, vector<int>& fin){
    vector<cd> a(tomut[at].begin(),tomut[at].end()),b(tomut[bt].begin(),tomut[bt].end());
    int n=1;
    while(n<sz(a)+sz(b))n<<=1;
    a.resize(n),b.resize(n);
    dft(a,0),dft(b,0);
    for(int i=0;i<n;i++)a[i]*=b[i];
    dft(a,1);
    fin.resize(n);
    for(int i=0;i<n;i++)fin[i]=round(a[i].real());
    int carry=0;
    for(int i=0;i<n;i++){
        fin[i]+=carry;
        carry=fin[i]/10,fin[i]%=10;
    }
    int len=sz(fin);
    while(fin[len-1]==0&&len>1)len--;
    fin.resize(len);
}
const int MAXN=1e5+1;
pii arr[MAXN];
struct comp{
    bool operator()(int lhs, int rhs){return sz(tomut[lhs])<sz(tomut[rhs]);};
};
string mutiply(vector<int> a){
    priority_queue<int,vector<int>,comp> q;
    tomut.resize(sz(a));
    for(int i=0;i<sz(a);i++){
        string te=to_string(a[i]);
        tomut[i].resize(sz(te));
        for(int j=0;j<sz(te);j++)tomut[i][sz(te)-j-1]=te[j]-'0';
        q.push(i);
    }
    while(sz(q)>1){
        int fi=q.top();
        q.pop();
        int se=q.top();
        q.pop();
        fft(fi,se,tomut[fi]);
        q.push(fi);
    }
    int cur=q.top();
    reverse(tomut[cur].begin(),tomut[cur].end());
    string ans(sz(tomut[cur]),'3');
    for(int i=0;i<sz(tomut[cur]);i++){
        ans[i]='0'+tomut[cur][i];
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<2;i++){
        for(int j=14;j<20;j++) {
            long double ang = 2 * pi / (1<<j) * (i ? -1 : 1);
            cd mut(cos(ang), sin(ang));
            cd cur(1);
            for(int k=0;k<(1<<(j-1));k++){
                precalc[i][j-14][k]=cur;
                cur*=mut;
            }
        }
    }
    for(int i=14;i<20;i++){
        int k=0;
        for(int j=0;j<(1<<i);j++){
            flip[i-14][j]=k;
            int b=(1<<(i-1));
            for(;k&b;b>>=1)k^=b;
            k^=b;
        }
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=(arr[i].first<0?1:0);
        arr[i].first=abs(arr[i].first);
    }
    sort(arr,arr+n,greater<>());
    int oddcnt=0;
    for(int i=0;i<k;i++)oddcnt+=arr[i].second;
    if(oddcnt%2){
        bool done=false;
        vector<int> te;
        long double ch=1;
        for(int i=k-1;i>=0;i--){
            if(arr[i].second==1&&!done){
                ch=ch/(long double)arr[i].first;
                done=true;
            }
            else te.push_back(arr[i].first);
        }
        done=false;
        for(int i=k;i<n;i++){
            if(arr[i].second==0){
                ch=ch*(long double)arr[i].first;
                te.push_back(arr[i].first);
                done=true;
                break;
            }
        }
        string ans="";
        bool baf=done;
        vector<int> te1={};
        done=false;
        long double ch2=1;
        for(int i=k-1;i>=0;i--){
            if(arr[i].second==0&&!done){
                ch2=ch2/(long double)arr[i].first;
                done=true;
            }
            else te1.push_back(arr[i].first);
        }
        if(done) {
            done = false;
            for (int i = k; i < n; i++) {
                if (arr[i].second == 1) {
                    ch2=ch2*(long double)arr[i].first;
                    te1.push_back(arr[i].first);
                    done = true;
                    break;
                }
            }
            if(done){
                if(ch>ch2&&baf)ans=mutiply(te);
                else ans=mutiply(te1);
            }
            else if(baf)ans=mutiply(te);
        }
        else if(baf)ans=mutiply(te);
        if(ans==""){
            te={};
            for(int i=n-1;i>=n-k;i--)te.push_back(arr[i].first);
            ans=mutiply(te);
            if(ans=="0")cout<<ans<<"\n";
            else cout<<"-"<<ans<<"\n";
        }
        else cout<<ans<<"\n";
    }
    else{
        vector<int> te;
        for(int i=0;i<k;i++)te.push_back(arr[i].first);
        string a=mutiply(te);
        cout<<a<<"\n";
    }
    return 0;
}