#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,[](auto & lhs, auto & rhs){
       if(lhs%10==rhs%10)return rhs<lhs;
       return lhs%10<rhs%10;
    });
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}