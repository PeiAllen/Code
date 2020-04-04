#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>2)odd++;
        else even++;
    }
    if(even%2==odd%2)printf("YES\n");
    else printf("NO\n");
    return 0;
}