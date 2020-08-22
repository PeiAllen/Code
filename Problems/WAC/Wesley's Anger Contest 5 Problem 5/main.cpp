#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const ll mod=998244353;
int n,e,k;
inline void matrixmult(vector<vector<ll>> &a,const vector<vector<ll>> &b){
    vector<vector<__int128>> ret(sz(a),vector<__int128>(sz(a)));
    for (int i = 0; i < sz(a); i++){
        for (int j = ((max(1,i)-1)/(n-2)*(n-2))+2; j < sz(a); j++){
            int top=min(sz(a),(((max(1,j)-1)/(n-2)+1)*(n-2))+2);
            for (int m = ((max(1,i)-1)/(n-2)*(n-2))+2; m < top; m++) {
                ret[i][j] += a[i][m] * b[m][j];
            }
            ret[i][j]%=mod;
        }
    }
    for(int i = 0; i < sz(a); i++)for(int j = 0; j < sz(a); j++){
            a[i][j]=ret[i][j];
    }
}
vector<vector<ll>> fp(const vector<vector<ll>> &a, ll b){
    b-=1;
    vector<vector<ll>> ans=a;
    vector<vector<ll>> mut=a;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)matrixmult(ans,mut);
        matrixmult(mut,mut);
    }
    return ans;
}
bool matrix[46][46];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>e>>k;
    char a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            matrix[i][j]=a=='1';
        }
        swap(matrix[i][1],matrix[i][3]);
    }
    swap(matrix[1],matrix[3]);
    int msz=2+(n-2)*(k+1);
    vector<vector<ll>> base(msz,vector<ll>(msz));
    for(int j=1;j<n-1;j++)if(matrix[0][j]&&j+(j==1?(n-2):0)<msz-1)base[0][j+(j==1?(n-2):0)]=1;
    vector<vector<ll>> tomut(msz,vector<ll>(msz));
    for(int i=1;i<msz-1;i++){
        for(int j=1;j<n-1;j++){
            if(matrix[((i-1)%(n-2))+1][j]){
                if(((i-1)/(n-2)+(j==1?1:0))*(n-2)+j<msz-1)tomut[i][((i-1)/(n-2)+(j==1?1:0))*(n-2)+j]=1;
            }
        }
        if((i-1)/(n-2)==k&&matrix[((i-1)%(n-2))+1][n-1])tomut[i][msz-1]=1;
    }
    fill(tomut[1].begin(),tomut[1].end(),0);
    auto te=base;
    matrixmult(te,fp(tomut,e-2));
    ll ans=te[0][msz-1];
    vector<vector<ll>> store=tomut;
    for(int i=3;i<msz-1;i+=n-2){
        fill(tomut[i].begin(),tomut[i].end(),0);
        for(int j=1;j<msz-1;j++)tomut[j][i]=0;
    }
    te=base;
    matrixmult(te,fp(tomut,e-2));
    ans-=te[0][msz-1];
    if(ans<0)ans+=mod;
    tomut=store;
    for(int i=2;i<msz-1;i+=n-2){
        fill(tomut[i].begin(),tomut[i].end(),0);
        for(int j=1;j<msz-1;j++)tomut[j][i]=0;
    }
    te=base;
    matrixmult(te,fp(tomut,e-2));
    ans-=te[0][msz-1];
    if(ans<0)ans+=mod;
    for(int i=3;i<msz-1;i+=n-2){
        fill(tomut[i].begin(),tomut[i].end(),0);
        for(int j=1;j<msz-1;j++)tomut[j][i]=0;
    }
    te=base;
    matrixmult(te,fp(tomut,e-2));
    ans+=te[0][msz-1];
    if(ans>=mod)ans-=mod;
    printf("%lli\n",ans);
    return 0;
}