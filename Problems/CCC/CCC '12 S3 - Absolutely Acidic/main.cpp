#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e6+1;
map<int,int> readings;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        readings[a]++;
    }
    vector<pii> arr;
    for(auto x:readings){
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),[&](const auto& lhs, const auto& rhs){
       if(lhs.second==rhs.second)return rhs.first<lhs.first;
       return rhs.second<lhs.second;
    });
    if(arr[0].second!=arr[1].second){
        int te=abs(arr[0].first-arr[1].first);
        int r=1;
        while(r+1<sz(arr)&&arr[r+1].second==arr[1].second)r++;
        printf("%d\n",te);
    }
    else{
        int r=1;
        while(r+1<sz(arr)&&arr[r+1].second==arr[0].second)r++;
        printf("%d\n",abs(arr[0].first-arr[r].first));
    }
    return 0;
}