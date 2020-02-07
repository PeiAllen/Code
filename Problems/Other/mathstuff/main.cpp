#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int arr[5]={1,2,3,4,5};
    int scnt=0;
    int gcnt=0;
    int cnt=0;
    do{
        cnt++;
        if(arr[0]!=1){
            scnt++;
            if(arr[1]==2)gcnt++;
        }
    }while(next_permutation(arr,arr+5));
    printf("%d %d %d\n",scnt,gcnt,cnt);
    return 0;
}