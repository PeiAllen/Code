#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int bit[(int)1e5+1];
vector<int> nums;
void update(int loc){
    for(;loc<=sz(nums);loc+=loc&-loc)bit[loc]+=1;
}
int am(int loc){
    int ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
   // freopen("sort.in","r",stdin);
   // freopen("sort.out","w",stdout);
    int n;
    sc(n);
    int arr[n];
    int thingy[n];
    rep(i,0,n){
        sc(arr[i]);
        thingy[i]=0;
        nums.push_back(arr[i]);
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    int cnt=1;
    for(int i=n-1;i>=0;i--){
        int loc=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin();
        loc+=1;
        int te=am(loc-1);
        thingy[i]=te;
        update(loc);
    }
    memset(bit,0,sizeof(bit));
    for(int i=0;i<n;i++){
        int loc=lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin();
        loc+=1;
        int te=am(sz(nums))-am(loc);
        te=min(te,thingy[i]);
        cnt=max(te,cnt);
        update(loc);
    }
    prl((cnt));
    return 0;
}