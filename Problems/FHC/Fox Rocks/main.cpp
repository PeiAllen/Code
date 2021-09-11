#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=6e4+1;
struct mat{
    vector<vector<double>> o;
    mat(){o=vector<vector<double>>();}
    mat(int n, int m, int v=0, bool i=false){
        o=vector<vector<double>>(n,vector<double>(m,(i?0:v)));
        if(i)for(int a=0;a<n;a++)o[a][a]=v;
    }
    mat operator*(const mat &a){
        mat ret=mat(sz(o),sz(a.o[0]));
        for(int i=0;i<sz(o);i++)for(int j=0;j<min(sz(o[0]),sz(a.o));j++)if(o[i][j])for(int k=0;k<sz(a.o[0]);k++)ret.o[i][k]+=o[i][j]*a.o[j][k];
        return ret;
    }
};
mat fp(mat a, ll b){
    mat ans=mat(8,8,1,1);
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a;
        a=a*a;
    }
    return ans;
}
double rocks[MN][8];
double tot[MN];
mat base[MN];
struct seg{
    mat t[MN];
    void mt(int ind, int le, int ri){
        if(le==ri)t[ind]=base[le];
        else{
            int mid=(le+ri)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            mt(left,le,mid),mt(right,mid+1,ri);
            t[ind]=t[left]*t[right];
        }
    }
    void update(int ind, int le, int ri, int loc){
        if(le==ri){t[ind]=base[le];return;}
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(loc<=mid)update(left,le,mid,loc);
        else update(right,mid+1,ri,loc);
        t[ind]=t[left]*t[right];
    }
    mat query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return mat(4,4,1,1);
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query(left,le,mid,l,r)*query(right,mid+1,ri,l,r);
    }
}tree;
void calc(int loc){
    mat cur(8,8);
    for(int j=0;j<4;j++){
        for(int k=0;k<8;k++){
            if(tot[loc*4+j])cur.o[j][k]=rocks[loc*4+j][k]/tot[loc*4+j];
        }
    }
    for(int j=0;j<4;j++)cur.o[4+j][4+j]=1;
    cur=fp(cur,1024);
    base[loc]=mat(4,4);
    for(int j=0;j<4;j++)for(int k=0;k<4;k++)base[loc].o[j][k]=cur.o[j][4+k];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("fox_rocks_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n,p,q;
        cin>>n>>p>>q;
        int a,b,c,d;
        for(int i=0;i<p;i++){
            cin>>a>>b>>c;
            rocks[a][b%4+(a/4==b/4?0:4)]=c,tot[a]+=c;
        }
        for(int i=0;i*4<n;i++)calc(i);
        tree.mt(0,0,(n-1)/4);
        printf("Case #%d:",cs);
        while(q--){
            cin>>a>>b>>c;
            if(a==1){
                cin>>d;
                rocks[b][c%4+(b/4==c/4?0:4)]=d,tot[b]+=d;
                calc(b/4),tree.update(0,0,(n-1)/4,b/4);
            }
            else if(a==2){
                tot[b]-=rocks[b][c%4+(b/4==c/4?0:4)],rocks[b][c%4+(b/4==c/4?0:4)]=0;
                calc(b/4),tree.update(0,0,(n-1)/4,b/4);
            }
            else{
                if(c/4<b/4){
                    printf(" 0.000000");
                    continue;
                }
                mat cur=tree.query(0,0,(n-1)/4,b/4,c/4-1);
                mat mut(4,4);
                for(int j=0;j<4;j++){
                    if(j!=c%4)for(int k=0;k<4;k++){
                        if(tot[c/4*4+j])mut.o[j][k]=rocks[c/4*4+j][k]/tot[c/4*4+j];
                    }
                    else mut.o[j][j]=1;
                }
                cur=cur*fp(mut,1024);
                printf(" %.6f",cur.o[b%4][c%4]);
            }
        }
        printf("\n");
        for(int i=0;i<n;i++)for(int j=0;j<8;j++)rocks[i][j]=0,tot[i]=0;
    }
    return 0;
}