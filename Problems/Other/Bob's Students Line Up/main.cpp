#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int lcnt=0,rcnt=0;
    string a;
    cin>>a;
    for(int i=1;i<n;i++){
        if(a[i]=='R')rcnt++;
    }
    int best=INT_MAX;
    for(int i=0;i<n;i++){
        best=min(best,lcnt+rcnt);
        if(a[i]=='L')lcnt++;
        if(a[i+1]=='R')rcnt--;
    }
    printf("%d\n",best);
    return 0;
}