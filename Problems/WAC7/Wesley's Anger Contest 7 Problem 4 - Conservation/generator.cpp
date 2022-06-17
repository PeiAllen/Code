#include "cstdio"
#include "iostream"
#include "vector"
#include "numeric"
#include "random"
#include "algorithm"
using namespace std;
using ll = long long;
template<typename T>
int sz(const T &a){return (int)a.size();}

void solve(vector<int> a){
    int n=sz(a);
    vector<vector<int>> arr(n+1,vector<int>());
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++){
        arr[a[i-1]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int ptr=0;
        for(int j=1;j<=sz(arr[i]);j++){
            dp[j]=dp[j-1];
            while(arr[i][ptr]<arr[i][j-1]-2)ptr++;
            dp[j]=max(dp[j],dp[ptr]+1);
        }
        ans+=dp[sz(arr[i])];
    }
    fprintf(stderr,"%d\n",ans);
}


mt19937_64 gen;

void randgen(int n, int maxV){
    printf("%d\n", n);
    uniform_int_distribution<int> agen(1,maxV);
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(agen(gen));
        printf("%d%c", arr.back(), " \n"[i == n]);
    }
    solve(arr);
}

void permgen(int n){
    printf("%d\n",n);
    vector<int> arr(n);
    iota(arr.begin(),arr.end(),1);
    shuffle(arr.begin(),arr.end(),gen);
    for(int i=1;i<=n;i++){
        printf("%d%c",arr[i-1]," \n"[i==n]);
    }
    solve(arr);
}

void groupgen(int n, int maxV, int l, int r){
    printf("%d\n",n);
    uniform_int_distribution<int> agen(1,maxV);
    vector<int> arr;
    for(int left=n;left>0;){
        int am=0;
        if(left>=l){
            uniform_int_distribution<int> amgen(l,min(left,r));
            am=amgen(gen);
        }
        else am=left;
        int type=agen(gen);
        for(int i=0;i<am;i++,left--){
            arr.push_back(type);
            printf("%d%c",arr.back()," \n"[left==1]);
        }
    }
    solve(arr);
}

int main(int argc, char* argv[]){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    gen.seed(atoi(argv[1]));
    if(atoi(argv[2])==0) {
        randgen(atoi(argv[3]),atoi(argv[4]));
    }
    else if(atoi(argv[2])==1){
        permgen(atoi(argv[3]));
    }
    else{
        groupgen(atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]));
    }
    return 0;
}