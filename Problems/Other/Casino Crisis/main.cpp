#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2001;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>arr[1];
    vector<pii> moves;
    for(int i=2;i<=n;i++){
        cin>>arr[i];
        int j=i-1;
        while(j>0&&arr[j]>arr[i])j--;
        if(j+1<i-1){
            moves.push_back({j+1,i-1});
            reverse(arr+j+1,arr+i);
        }
        if(j+1<i){
            moves.push_back({j+1,i});
            reverse(arr+j+1,arr+i+1);
        }
    }
    printf("%d\n",sz(moves));
    for(auto x:moves)printf("%d %d\n",x.first,x.second);
    return 0;
}