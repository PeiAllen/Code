#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MN=2001;
int am[MN];

vector<int> generatearray(int n, int mval, int type){
    vector<int> arr(n);
    if(type==1) {//decreasing
        for (int i = 0; i < n; i++) {
            arr.push_back(rnd.next(1, mval));
        }
        sort(arr.begin(),arr.end(),greater<>());
        int cnt=max(1,int(n*0.03));
        for(int i=0;i<cnt;i++){
            int a=rnd.next(1,n),b=rnd.next(1,n);
            swap(arr[a],arr[b]);
        }
    }
    else if(type==2){//increasing
        for (int i = 0; i < n; i++) {
            arr.push_back(rnd.next(1, mval));
        }
        sort(arr.begin(),arr.end());
        int cnt=max(1,int(n*0.03));
        for(int i=0;i<cnt;i++){
            int a=rnd.next(1,n),b=rnd.next(1,n);
            swap(arr[a],arr[b]);
        }
    }
    else if(type==3){//extreme
        for (auto i = 0; i < n; i++) {
            int m = -1 + 2*rnd.next(0, 1);
            arr[i]=rnd.wnext(1, mval, 40*m);
        }
    }
    else if(type==4){//close
        int offset=0.01*n;
        int mid=rnd.next(offset+1,n-offset);
        for(int i=0;i<n;i++){
            arr[i]=rnd.next(mid-offset,mid+offset);
        }
    }
    else{//random
        for(int i=0;i<n;i++){
            arr[i]=rnd.next(1,n);
        }
    }
    return arr;
}



int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    registerGen(argc,argv,0);
    int n=stoi(argv[1]),m=stoi(argv[2]),p=stoi(argv[3]),t=stoi(argv[4]);
//    int n=20,m=10,p=rnd.next(1,50),t=1;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a=(rnd.next(1,100)<=p?'#':'.');
            printf("%c",a);
            if(a=='#')am[j]++;
        }
        printf("\n");
    }
    for(int i=1;i<=m;i++){
        if(t==1)printf("%d%c",rnd.next(0,am[i])," \n"[i==m]);
        else if(t==2)printf("%d%c",rnd.next(0,n)," \n"[i==m]);
        else printf("%d%c",rnd.next(am[i]+1,n)," \n"[i==m]);
    }
    return 0;
}