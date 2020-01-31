#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int sum=0;
    for(int i=2;i<=100;i+=2){
        sum+=i*i-(i-1)*(i-1);
        printf("%d\n",sum);
        //printf("%d\n",i*i-(i-1)*(i-1)-1);
    }
    printf("%d\n",sum);
    return 0;
}