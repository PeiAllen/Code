#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int lift[18][MN];
int deq[MN];
int l, r,m,n;
void ms(){
    for(int i=1;i<18;i++){
       for(int j=0; j <= m; j++){
           lift[i][j]=lift[i-1][lift[i-1][j]];
       }
    }
}
int count(int a, int b){
    int am=1;
    for(int i=17;i>=0;i--){
        if(lift[i][a]<=b)am+=(1<<i),a=lift[i][a];
    }
    return am;
}
pii range[MN];
set<pii> used;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,b;
    cin >> n;
    vector<pair<pii,int>> arr;
    vector<pair<pii,int>> tearr;
    for(int i=0; i < n; i++){
        cin>>a>>b;
        range[i]={a,b};
        arr.push_back({{a,b},i});
    }
    sort(arr.begin(),arr.end());
    int last=INT_MIN;
    for(auto x:arr){
        while(sz(tearr)&&tearr.back().first.second>=x.first.second)tearr.pop_back();
        if(x.first.first!=last)tearr.push_back(x);
        last=x.first.first;
    }
    arr=tearr;
    m=sz(arr);
    sort(arr.begin(),arr.end(),[&](const auto& lhs, const auto& rhs){
        return lhs.first.second<rhs.first.second;
    });
    l=0,r=-1;
    deq[++r]=m;
    arr[m]={{INT_MAX, INT_MAX}, -1};
    lift[0][m]=m;
    for(int i= m - 1; i >= 0; i--){
        while(r-l>=1&&arr[deq[l+1]].first.first>=arr[i].first.second)l++;
        lift[0][i]=deq[l];
        while(l<=r&&arr[deq[r]].first.first<=arr[i].first.first)r--;
        deq[++r]=i;
    }
    ms();
    set<pii> intervals={{0, m - 1}};
    vector<int> touse;
    for(int i = 0; i < n; i++){
        auto it=used.lower_bound({range[i].first,range[i].first});
        if(it!=used.end()&&it->first<range[i].second)continue;
        if(it!=used.begin()&&prev(it,1)->second>range[i].first)continue;
        int firstbad=lower_bound(arr.begin(),arr.end(),range[i].first+1,[&](const auto& it, const int &val){
            return it.first.second<val;
        })-arr.begin();
        int lastbad=lower_bound(arr.begin(),arr.end(),range[i].first+1,[&](const auto& it, const int &val){
            return it.first.second<val;
        })-arr.begin();

    }
    printf("%d\n",sz(touse));
    for(auto x:touse)printf("%d ",x);
    printf("\n");
    return 0;
}