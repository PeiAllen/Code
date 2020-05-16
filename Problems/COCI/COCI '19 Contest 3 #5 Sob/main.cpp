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
    int n,m;
    cin>>n>>m;
    set<int> nums;
    for(int i=0;i<n;i++){
        nums.insert(i+m);
    }
    n-=1;
    if(n)for(int i=31-__builtin_clz(n);i>=0;i--){
        map<int,vector<int>> cur;
        for(int x:nums)cur[x&((1<<(i+1))-1)].push_back(x);
        while(31-__builtin_clz(n)==i&&n){
            printf("%d %d\n",n,*cur[n].rbegin());
            nums.erase(*cur[n].rbegin());
            cur[n].pop_back();
            n--;
        }
    }
    printf("%d %d\n",n,*nums.begin());
    return 0;
}