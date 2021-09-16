#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int main(int argc, char* argv[]){//generator translated from https://blog.paulhankin.net/latinsquares/  https://github.com/chrweave/noodlings/blob/master/latinjm/main.c
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=300;
    printf("%d\n",n);
    vector<vector<int>> xy(n,vector<int>(n,0)),xz(n,vector<int>(n,0)),yz(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k=(i+j)%n;
            xy[i][j]=k;
            xz[i][k]=j;
            yz[j][k]=i;
        }
    }
    int mxy,mxz,myz;
    vector<int> m(3,0);
    bool proper=true;
    int miniter=n*n*n;
    for(int iter=0;iter<miniter||!proper;iter++){
        int i,j,k,i2,j2,k2;
        int i2_,j2_,k2_;
        if(proper){
            i=rnd.next(0,n-1),j=rnd.next(0,n-1),k=rnd.next(0,n-1);
            while(xy[i][j]==k)i=rnd.next(0,n-1),j=rnd.next(0,n-1),k=rnd.next(0,n-1);
            i2=yz[j][k],j2=xz[i][k],k2=xy[i][j];
            i2_=i,j2_=j,k2_=k;
        }
        else{
            i=m[0],j=m[1],k=m[2];
            i2=yz[j][k],i2_=myz;
            if(rnd.next(0,100)<=100)swap(i2,i2_);
            j2=xz[i][k],j2_=mxz;
            if(rnd.next(0,100)<=100)swap(j2,j2_);
            k2=xy[i][j],k2_=mxy;
            if(rnd.next(0,100)<=100)swap(k2,k2_);
        }
        proper=xy[i2][j2]==k2;
        if(!proper){
            m[0]=i2,m[1]=j2,m[2]=k2;
            mxy=xy[i2][j2];
            myz=yz[j2][k2];
            mxz=xz[i2][k2];
        }
        xy[i][j] = k2_;
        xy[i][j2] = k2;
        xy[i2][j] = k2;
        xy[i2][j2] = k;

        yz[j][k] = i2_;
        yz[j][k2] = i2;
        yz[j2][k] = i2;
        yz[j2][k2] = i;

        xz[i][k] = j2_;
        xz[i][k2] = j2;
        xz[i2][k] = j2;
        xz[i2][k2] = j;
    }
    vector<int> rows;
    for(int i=0;i<n;i++)rows.push_back(i);
    shuffle(rows.begin(),rows.end());
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c",(i==rows[0]||i==rows[1]?0:xy[i][j]+1)," \n"[j==n-1]);
        }
    }
    return 0;
}