#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=10002;
int arr[MN];
int psa[MN];
int psa2[MN][101];
int ord[101];
int lookup[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int q,a;
    cin>>q;
    vector<pii> queries;
    for(int i=1;i<=q;i++){
        cin>>a;
        queries.push_back({l-a,i});
    }
    sort(queries.begin(),queries.end());
    for(int i=0;i<sz(queries);i++){
        ord[queries[i].second]=i;
    }
    int ptr=sz(queries);
    for(int i=n;i>=0;i--){
        while(ptr-1>=0&&queries[ptr-1].first>i)ptr--;
        lookup[i]=ptr;
    }
    for(int offset=1;offset<=n-l;offset++){
        for(int i=1;i<=n;i++)psa[i]=0;
        for(int i=1;i<=n-offset;i++){
            if(arr[i]==arr[i+offset]){
                psa[max(1,i-l+1)]++;
                psa[i+1]--;
            }
        }
        for(int i=1;i+offset<=n-l+1;i++){
            psa[i]+=psa[i-1];
            int x=lookup[psa[i]];
            psa2[i][0]++;
            psa2[i][x]--;
            psa2[i+offset][0]++;
            psa2[i+offset][x]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<sz(queries);j++){
            psa2[i][j]+=psa2[i][j-1];
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n-l+1;j++){
            printf("%d%c",psa2[j][ord[i]]," \n"[j==n-l+1]);
        }
    }
    return 0;
}