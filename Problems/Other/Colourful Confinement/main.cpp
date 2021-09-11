#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=4001;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n<=2000){
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=n;i<2*n;i++)arr[i]=arr[i-n];
        for(int i=0;i<2*n;i++){
            for(int j=i+2;j<i+n;j++){
                if(arr[i]==arr[j]&&(i+j)%2==0&&arr[(i+j)/2]==arr[i]){
                    printf("%d %d %d\n",(i%n)+1,(((i+j)/2)%n)+1,(j%n)+1);
                    return 0;
                }
            }
        }
    }
    else {
        for (int i = 0; i < 2000; i++) {
            cin>>arr[i];
        }
        for(int i=0;i<2000;i++){
            for(int j=i+2;j<2000;j++){
                if(arr[i]==arr[j]&&(i+j)%2==0&&arr[(i+j)/2]==arr[i]){
                    printf("%d %d %d\n",i+1,(i+j)/2+1,j+1);
                    return 0;
                }
            }
        }
    }
    printf("0 0 0\n");
    return 0;
}