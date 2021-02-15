#include<bits/stdc++.h>
using namespace std;
const int MN = 404;
int N, arr[MN], psa[MN], ssa[MN] ,dp [MN][MN];

int f(int l, int r){
    if(r<l)return 1;
    if(dp[l][r]){
        return dp[l][r];
    }
    if((r-l<=2) && arr[l] == arr[r]){
        return dp[l][r] = 1;
    }
    int a = l, b = r;
    dp[l][r]=2;
    while(b-a>0){
        if(l == 2 && r == 7){
            cout<<a<<" "<<b<<"\n";
            cout<<psa[a]-psa[l-1]<<" "<<ssa[b] - ssa[r+1]<<"\n";
        }
        if(psa[a]-psa[l-1] == ssa[b] - ssa[r+1]){
            dp[l][r] = f(l,a)*f(a+1,b-1)*f(b,r);
        }
        else if(psa[a]-psa[l-1] > ssa[b] - ssa[r+1]){
            b--;
        }
        else{
            a++;
        }
    }
    return dp[l][r];
}

int main(){
    scanf("%d", &N);
    for(int i = 1;i<=N;i++){
        scanf("%d", &arr[i]);
        psa[i] = psa[i-1]+arr[i];
    }
    for(int i = N;i>=1;i--){
        ssa[i]=ssa[i+1]+arr[i];
    }
    for(int i = 1;i<=N;i++){
        for(int j = i;j<=N;j++){
            dp[i][j]=f(i,j);
        }
    }
    int ans = 0;
    for(int i = 1;i<=N;i++){
        for(int j = i;j<=N;j++){
            ans = max(ans,(dp[i][j]%2)*(psa[j]-psa[i-1]));
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<i;j++){
            cout<<"  ";
        }
        for(int j = i;j<=N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    printf("%d\n", ans);
    return 0;
}