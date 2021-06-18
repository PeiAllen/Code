#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MR=5001,MC=201,fatsize=10;
template <class T> using matrix = vector<vector<T>>;
template <class T> matrix<T> operator*(const matrix<T> &a, const matrix<T> &b){
    matrix<T> ans(sz(a),vector<T>(sz(b[0]),0));
    for(int i=0;i<sz(a);i++){
        function<void(int,int,int,int)> solve=[&](int ql, int qr, int al, int ar){
            int mid=(ql+qr)/2,bind=-1;
            int best=INT_MAX;
            for(int j=al;j<=ar;j++){
                if(a[i][j]+b[j][mid]<best){
                    best=a[i][j]+b[j][mid];
                    bind=j;
                }
            }
            if(ql==qr)ans[i][ql]=best;
            else solve(ql,mid,al,bind),solve(mid+1,qr,bind,ar);
        };
        solve(0,sz(b[0])-1,0,sz(a[0])-1);
    }
    return ans;
}
int hor[MR][MC],ver[MR][MC],n,m;
matrix<int> calc(int l, int r){
    matrix<int> dp(m,vector<int>(m,0));
    for(int i=0;i<m;i++){
        dp[i][i]=0;
        for(int j=i+1;j<m;j++)dp[i][j]=dp[i][j-1]+hor[l][j-1];
        for(int j=i-1;j>=0;j--)dp[i][j]=dp[i][j+1]+hor[l][j];
        for(int j=l+1;j<=r;j++){
            for(int k=0;k<m;k++)dp[i][k]+=ver[j-1][k];
            for(int k=1;k<m;k++)dp[i][k]=min(dp[i][k],dp[i][k-1]+hor[j][k-1]);
            for(int k=m-2;k>=0;k--)dp[i][k]=min(dp[i][k],dp[i][k+1]+hor[j][k]);
        }
    }
    return dp;
}
struct seg{
    matrix<int> t[2*MR];
    void mt(int ind, int le, int ri){
        if(ri-le<=fatsize)t[ind]=calc(le,ri+1);
        else{
            int mid=(le+ri)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            mt(left,le,mid),mt(right,mid+1,ri);
            t[ind]=t[left]*t[right];
        }
    }
    void update(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return;
        if(ri-le<=fatsize){
            t[ind]=calc(le,ri+1);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r),update(right,mid+1,ri,l,r);
        t[ind]=t[left]*t[right];
    }
}tree;
void init(int R, int C, vector<vector<int>> H, vector<vector<int>> V){
    n=R,m=C;
    for(int i=0;i<n;i++)for(int j=0;j<m-1;j++)hor[i][j]=H[i][j];
    for(int i=0;i<n-1;i++)for(int j=0;j<m;j++)ver[i][j]=V[i][j];
    tree.mt(0,0,n-2);
}
void changeH(int P, int Q, int W){
    hor[P][Q]=W;
    tree.update(0,0,n-2,P-1,P);
}
void changeV(int P, int Q, int W){
    ver[P][Q]=W;
    tree.update(0,0,n-2,P,P);
}
int escape(int V1, int V2){
    return tree.t[0][V1][V2];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    vector<vector<int>> H(r,vector<int>(c-1,0)),V(r-1,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c-1;j++){
            cin>>H[i][j];
        }
    }
    for(int i=0;i<r-1;i++)for(int j=0;j<c;j++)cin>>V[i][j];
    init(r,c,H,V);
    int q;
    cin>>q;
    int a,b,t;
    while(q--){
        cin>>t>>a>>b;
        if(t==1){
            cin>>c;
            changeH(a,b,c);
        }
        else if(t==2){
            cin>>c;
            changeV(a,b,c);
        }
        else printf("%d\n",escape(a,b));
    }
    return 0;
}