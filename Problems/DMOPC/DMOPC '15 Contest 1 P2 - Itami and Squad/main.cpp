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
    int n,l,r;
    cin>>n>>l>>r;
    r--;
    priority_queue<int> peeps;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        peeps.push(a);
    }
    int tot=0;
    for(int i=0;i<n;i++){
        if(i%l==r)tot+=peeps.top();
        peeps.pop();
    }
    printf("%d\n",tot);
    return 0;
}