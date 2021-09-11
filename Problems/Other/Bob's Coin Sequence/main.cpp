#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    vector<int> len;
    int last=-1;
    for(int i=0;i<n;i++){
        cin>>a;
        a=(i%2==a%2);
        if(a==last)len.back()++;
        else len.push_back(1);
        last=a;
    }
    if(sz(len)<=3)printf("%d\n",n);
    else {
        int best = 0;
        for (int i = 0; i + 2 < sz(len); i++)best = max(best, len[i] + len[i + 1] + len[i + 2]);
        printf("%d\n", best);
    }
    return 0;
}