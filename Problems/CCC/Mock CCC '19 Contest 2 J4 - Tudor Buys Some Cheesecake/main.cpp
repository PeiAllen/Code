#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    for(char x:a){
        arr[x-'A']++;
    }
    int cnt=sz(a);
    for(char x:b){
        if(arr[x-'A'])cnt--,arr[x-'A']--;
    }
    printf("%d\n",cnt);
    return 0;
}