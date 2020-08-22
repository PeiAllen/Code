#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int t=10;
    printf("%d\n",t);
    while(t--){
        int n=10,m=20;
        printf("%d %d\n",n,m);
        for(int i=2;i<=n;i++){
            int p=rnd.next(1,i-1);
            printf("%d %d\n",i,p);
        }
        for(int i=n;i<=m;i++){
            int a=rnd.next(1,n);
            int b=rnd.next(1,n);
            printf("%d %d\n",a,b);
        }
        int q=100;
        printf("%d\n",q);
        while(q--){
            int s=rnd.next(2,n);
            set<int> stff;
            while(sz(stff)<s)stff.insert(rnd.next(1,n));
            printf("%d ",s);
            vector<int> ree;
            for(auto x:stff)ree.push_back(x);
            for(int i=1;i<s;i++)printf("%d ",ree[i]);
            printf("%d\n",ree[0]);
        }
    }
    return 0;
}