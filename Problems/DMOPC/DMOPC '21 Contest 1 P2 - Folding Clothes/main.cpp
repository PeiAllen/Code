#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int SZ(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pii> te(n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>te[i].A,te[i].B=i;
    }
    sort(te.begin(),te.end());
    for(int i=0;i<n;i++)arr[te[i].B]=i;
    vector<int> moves;
    for(int i=n-1;i>=0;i--){
        int ind=find(arr.begin(),arr.end(),i)-arr.begin();
        moves.push_back(ind+1);
        arr.erase(arr.begin()+ind);
        if(ind>0)moves.push_back(-ind);
    }
    moves.push_back(-n);
    printf("%d\n",SZ(moves));
    for(auto x:moves)printf("%d\n",x);
    return 0;
}