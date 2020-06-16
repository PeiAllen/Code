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
    int n,k;
    cin>>n>>k;
    priority_queue<ll,vector<ll>,greater<>> q;
    ll tot=0;
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        tot+=a;
        q.push(b-a);
    }
    for(int i=0;i<k;i++){
        tot+=q.top();
        q.pop();
    }
    printf("%lli\n",tot);
    return 0;
}