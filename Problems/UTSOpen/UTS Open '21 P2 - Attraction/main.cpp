#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=0;i<a;i++)cin>>arr[i];
        sort(arr,arr+a);
        vector<int> get;
        get.push_back(arr[0]-1);
        get.push_back(n-arr[a-1]);
        int threes=0;
        for(int i=1;i<a;i++){
            if(arr[i]-arr[i-1]==1)continue;
            else if(arr[i]-arr[i-1]==2)get.push_back(1);
            else if(arr[i]-arr[i-1]==4){
                get.push_back(2);
                threes++;
            }
            else {
                get.push_back((arr[i] - arr[i - 1]) / 2);
                get.push_back( arr[i] - arr[i - 1] - 1 - (arr[i] - arr[i - 1]) / 2 - ((arr[i] - arr[i - 1] - 1) % 2));
                if ((arr[i] - arr[i - 1] - 1) % 2)get.push_back(1);
            }
        }
        sort(get.begin(),get.end(),greater<>());
        while(sz(get)&&get.back()==0)get.pop_back();
        printf("%d\n",accumulate(get.begin(),get.begin()+min(sz(get),b),0)+min(threes,max(0,(b-sz(get))/2)));
    }
    return 0;
}