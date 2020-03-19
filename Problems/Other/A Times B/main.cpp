#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
typedef complex<double> cd;
const int MAXN=1e6+1e5;
double pi=acos(-1);
cd precalc[2][3][MAXN];
int flip[3][2*MAXN];
void dft(vector<cd>& a, bool inv){
    int lg=log2(sz(a));
    if(lg>=19) {
        for (int i = 1; i < sz(a); i++) {
            if (flip[lg-19][i] > i)swap(a[i], a[flip[lg-19][i]]);
        }
    }
    else{
        for(int i=0,j=0;i<sz(a);i++){
            if(j>i)swap(a[i],a[j]);
            int b=sz(a)>>1;
            for(;j&b;b>>=1)j^=b;
            j^=b;
        }
    }
    int ind=1;
    for(int lay=2;lay<=sz(a);lay<<=1){
        if(ind>=19){
            for(int i=0;i<sz(a);i+=lay){
                for(int j=0;j<lay/2;j++){
                    cd u=a[i+j], v=precalc[inv][ind-19][j]*a[i+j+lay/2];
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
vector<int> arr[2];
vector<int> ans;
void fft(int at, int bt, vector<int>& fin){
    vector<cd> a(arr[at].begin(),arr[at].end()),b(arr[bt].begin(),arr[bt].end());
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
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    for(int i=0;i<2;i++){
        for(int j=19;j<22;j++) {
            long double ang = 2 * pi / (1<<j) * (i ? -1 : 1);
            cd mut(cos(ang), sin(ang));
            cd cur(1);
            for(int k=0;k<(1<<(j-1));k++){
                precalc[i][j-19][k]=cur;
                cur*=mut;
            }
        }
    }
    for(int i=19;i<22;i++){
        int k=0;
        for(int j=0;j<(1<<i);j++){
            flip[i-19][j]=k;
            int b=(1<<(i-1));
            for(;k&b;b>>=1)k^=b;
            k^=b;
        }
    }
    for(char x:a)arr[0].push_back(x-'0');
    for(char x:b)arr[1].push_back(x-'0');
    reverse(arr[0].begin(),arr[0].end());
    reverse(arr[1].begin(),arr[1].end());
    fft(0,1,ans);
    reverse(ans.begin(),ans.end());
    int s=0;
    while(ans[s]==0&&s<sz(ans)-1)s++;
    for(;s<sz(ans);s++)printf("%d",ans[s]);
    return 0;
}