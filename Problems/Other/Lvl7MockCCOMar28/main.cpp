#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
pair<long double,long double> points[4];
long double s;
long double a,b,c,d;
long double at,bt,ct,dt;
long double m,inter;
long double distv(long double a, long double b, int p){
    return sqrt((a-points[p].first)*(a-points[p].first)+(b-points[p].second)*(b-points[p].second));
}
bool valid(long double a, long double b, int p){
    if(a<=-s){
        if(b>=s){
            if(p!=2)return true;
            return false;
        }
        else if(b<=-s){
            if(p!=1)return true;
            return false;
        }
        else{
            if(p==0||p==3)return true;
            return false;
        }
    }
    else if(a>=s){
        if(b>=s){
            if(p!=3)return true;
            return false;
        }
        else if(b<=-s){
            if(p!=0)return true;
            return false;
        }
        else{
            if(p==1||p==2)return true;
            return false;
        }
    }
    else if(b>=s){
        if(p==0||p==1)return true;
        return false;
    }
    else{
        if(p==2||p==3)return true;
        return false;
    }
}
long double dist(long double a, long double b, int p){
    long double mi=INT_MAX;
    for(int i=0;i<1000000;i++){
        if(!(a>=min(at,ct)&&a<=max(at,ct)))break;
        if(valid(a,b,p))mi=min(mi,distv(a,b,p));
        a-=0.01;
        b=m*a+inter;
    }
    return mi;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>s;
    long double ans=s*(long double)8;
    long double ans2=s*(long double)8;

    points[0]={-s,s};
    points[1]={s,s};
    points[2]={s,-s};
    points[3]={-s,-s};
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        at=a,bt=b,ct=c,dt=d;
        m=(d-b)/(c-a);
        inter=b-m*a;
        a=-m,b=1,c=-inter;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(j!=k) {
                    if(valid(at,bt,j)&&valid(ct,dt,k)){
                        ans2=min(ans2,(long double)2*s*(long double)(abs(j+k)%2?3:2)+dist(at,bt,j)+dist(ct,dt,k));
//                        ans2=min(ans2,(long double)2*s*(long double)(abs(j+k)%2?3:2)+distv(at,bt,j)+distv(ct,dt,k));
                    }
                }
            }
        }
    }
  //  if(ans!=ans2)printf("%.6f %.6f",ans,ans2);
    printf("%.6LF",ans2);
    return 0;
}