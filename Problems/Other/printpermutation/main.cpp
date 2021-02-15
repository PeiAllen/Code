#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int n;
int arr[20];
void permute(int st){
  if(st==n){
      for(int i=0;i<n;i++)printf("%d%c",arr[i]," \n"[i==n-1]);
      return;
  }
  for(int i=st;i<n;i++){
      swap(arr[st],arr[i]);
      permute(st+1);
  }
  for(int i=n-1;i>=st;i--)swap(arr[i],arr[st]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)arr[i]=i+1;
    permute(0);
    return 0;
}