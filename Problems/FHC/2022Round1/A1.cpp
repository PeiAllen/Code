#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
int arr[3*MN];
int kmp[3*MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>arr[i];
        arr[n]=-1;
        for(int i=n+1;i<n+n+1;i++)cin>>arr[i],arr[i+n]=arr[i];
        if(n==2){
            if(k%2==1){
                swap(arr[0],arr[1]);
            }
            if(arr[0]==arr[n+1]&&arr[1]==arr[n+2]){
                printf("Case #%d: YES\n",cs);
            }
            else{
                printf("Case #%d: NO\n",cs);
            }
            continue;
        }
        bool start=false;
        bool nonstart=false;
        for(int i=1;i<n+n+n;i++){
            int j=kmp[i-1];
            while(j>0&&arr[j]!=arr[i])j=kmp[j-1];
            if(arr[i]==arr[j])j++;
            kmp[i]=j;
            if(kmp[i]==n){
                if(i==n+n){
                    start=true;
                }
                else{
                    nonstart=true;
                }
            }
        }
        if(k==0){
            if(start){
                printf("Case #%d: YES\n",cs);
            }
            else{
                printf("Case #%d: NO\n",cs);
            }
        }
        else if(k==1){
            if(nonstart){
                printf("Case #%d: YES\n",cs);
            }
            else{
                printf("Case #%d: NO\n",cs);
            }
        }
        else{
            if(start||nonstart){
                printf("Case #%d: YES\n",cs);
            }
            else{
                printf("Case #%d: NO\n",cs);
            }
        }
    }
    return 0;
}