#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[(int)1e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ma=arr[n-1];
    int longest=0;
    int cur=0;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<ma){
            cur++;
            longest=max(longest,cur);
        }
        else ma=arr[i],cur=0;
    }
    longest=max(longest,cur);
    printf("%d\n",longest);
    return 0;
}