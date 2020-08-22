#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e3+1;
pii scores[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,c;
    cin>>n>>k>>c;
    vector<int> poss;
    for(int i=0;i<n;i++){
        cin>>scores[i].first>>scores[i].second;
        for(int j=0;j<i;j++){
            poss.push_back(max(scores[i].first,scores[j].first)+max(scores[i].second,scores[j].second));
        }
    }
    sort(poss.begin(),poss.end(),greater<>());
    printf("%d\n",poss[c-1]);
    return 0;
}