#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
struct seg{
    struct node{
        ll data,lazy;
    };
    node t[8*MAXN];
    void rl(int ind, int le, int ri){
        t[ind].data+=t[ind].lazy;
        if(le!=ri){
            int mid=(le+ri)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, ll val){
        rl(ind,le,ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,le,ri);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
}tree;
pair<pii,ll> arr[MAXN];
vector<int> xcoords,ycoords;
vector<pair<pii,ll>> todel;
int todelp=0;
vector<pair<pii,ll>> toins;
int toinsp=0;
ll ans=LLONG_MIN;
int r,c,n,m;
void linesweep(){
    for(auto x:xcoords){
        while(toinsp<sz(toins)&&toins[toinsp].first.first<=x+r-1){
            tree.update(0,0,sz(ycoords)-1,lower_bound(ycoords.begin(),ycoords.end(),toins[toinsp].first.second-c+1)-ycoords.begin(),(upper_bound(ycoords.begin(),ycoords.end(),toins[toinsp].first.second)-ycoords.begin())-1,toins[toinsp].second);
            toinsp++;
        }
        while(todelp<sz(todel)&&todel[todelp].first.first<x){
            tree.update(0,0,sz(ycoords)-1,lower_bound(ycoords.begin(),ycoords.end(),todel[todelp].first.second-c+1)-ycoords.begin(),(upper_bound(ycoords.begin(),ycoords.end(),todel[todelp].first.second)-ycoords.begin())-1,-todel[todelp].second);
            todelp++;
        }
        ans=max(ans,tree.t[0].data);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>r>>c>>n>>m;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
        xcoords.push_back(min(n-r+1,arr[i].first.first));
        xcoords.push_back(min(n-r+1,min(n,arr[i].first.first+1)));
        xcoords.push_back(min(n-r+1,max(1,arr[i].first.first-r+1)));
        xcoords.push_back(min(n-r+1,max(1,arr[i].first.first-r)));
        ycoords.push_back(min(m-c+1,arr[i].first.second));
        ycoords.push_back(min(m-c+1,min(m,arr[i].first.second+1)));
        ycoords.push_back(min(m-c+1,max(1,arr[i].first.second-c+1)));
        ycoords.push_back(min(m-c+1,max(1,arr[i].first.second-c)));
        todel.push_back(arr[i]);
        toins.push_back(arr[i]);
    }
    sort(todel.begin(),todel.end());
    sort(toins.begin(),toins.end());
    sort(xcoords.begin(),xcoords.end());
    xcoords.erase(unique(xcoords.begin(),xcoords.end()),xcoords.end());
    sort(ycoords.begin(),ycoords.end());
    ycoords.erase(unique(ycoords.begin(),ycoords.end()),ycoords.end());
    linesweep();
    printf("%lli\n",ans);
    return 0;
}