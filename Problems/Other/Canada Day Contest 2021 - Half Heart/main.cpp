#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
vector<int> xs,ys,zs;
int ans[MN];
struct seg{

}tree;
void cdq(vector<pair<int,pii>> points, vector<pair<pair<int,pii>,pii>> queries){



    int mid=(sz(points)-1)/2;
    int ptr=mid;
    for(auto x:queries){
        while(ptr+1<sz(points)&&points[ptr+1].first<=x.first.first){
            ptr++;
            tree.update(0,0,sz(ys)-1,points[ptr].second.first,points[ptr].second.second);
        }
    }
    tree.clear();
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector<pair<int,pii>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
        xs.push_back(arr[i].first);
        ys.push_back(arr[i].second.first);
        zs.push_back(arr[i].second.second);
    }
    sort(xs.begin(),xs.end()),xs.erase(unique(xs.begin(),xs.end()),xs.end());
    sort(ys.begin(),ys.end()),ys.erase(unique(ys.begin(),ys.end()),ys.end());
    sort(zs.begin(),zs.end()),zs.erase(unique(zs.begin(),zs.end()),zs.end());
    sort(arr.begin(),arr.end());
    vector<pair<pair<int,pii>,pii>> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i].first.first>>queries[i].first.second.first>>queries[i].first.second.second;
        queries[i].second={i,INT_MAX};
    }
    cdq(arr,queries);
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}