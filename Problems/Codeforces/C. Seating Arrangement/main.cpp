#include <bits/stdc++.h>

using namespace std;
const int MAXN=3e5+1;
int arr[MAXN];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n<=4)printf("-1\n");
    else{
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i>1){
                if(i%2==0){
                    swap(arr[i],arr[i-1]);
                }
                else{
                    swap(arr[i],arr[i-2]);
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}