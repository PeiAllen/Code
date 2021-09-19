#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=2e5+1;
int bit[MN];
int q;
void update(int loc, int val){
    for(;loc<=q;loc+=loc&-loc)bit[loc]+=val;
}
int get(int am){
    int pos=0;
    for(int i=(1<<20);i>=1;i>>=1){
        if(pos+i<=q&&bit[pos+i]<am)pos+=i,am-=bit[pos];
    }
    return pos+1;
}
int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    q=stoi(argv[1]);
    printf("%d\n",q);
    int maxloc=stoi(argv[2]),maxoth=stoi(argv[3]),up1=stoi(argv[4]),miuprange=stoi(argv[5]),tup2=stoi(argv[6]),maxstores=stoi(argv[7]),up3=stoi(argv[8]),miqurange=stoi(argv[9]);
    int stores=0;
    for(int i=1;i<=q;i++){
        int up2=tup2*stores/maxstores;
        int p=rnd.next(1,up1+up2+up3);
        if(p<=up1){
            int a=rnd.next(1,maxloc),b=rnd.next((miuprange-1)/2,maxloc),c=rnd.next(1,maxoth),d=rnd.next(1,maxoth);
            printf("1 %d %d %d %d\n",a,b,c,d);
            update(i,1);
            stores++;
        }
        else if(p<=up1+up2){
            int x=get(rnd.next(1,stores));
            printf("2 %d\n",x);
            update(x,-1);
            stores--;
        }
        else{
            int l=rnd.next(1,maxloc-miqurange+1);
            int r=rnd.next(l+miqurange-1,maxloc),c=rnd.next(1,maxoth);
            printf("3 %d %d %d\n",l,r,c);
        }
    }
    return 0;
}