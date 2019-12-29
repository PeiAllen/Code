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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    vector<pair<lli,int>> nums;
    lli ans=LLONG_MAX;
    pii ind;
    lli in;
    rep(i,0,n){
        sc(in);
        nums.push_back({in,i});
    }
    sort(nums.begin(),nums.end());
    rep(i,0,n){
        auto loc=lower_bound(nums.begin(),nums.end(),pair<lli,int>{nums[i].first,i})-nums.begin();
            if(loc!=n){
                if(ans>abs(nums[loc].first+in)){
                    ans=abs(nums[loc].first+in);
                    ind={nums[loc].second,i};
                }
                else if(ans==abs(nums[loc].first+in)&&make_pair(nums[loc].second,i)<ind){
                    ind={nums[loc].second,i};
                }
            }
            if(loc!=0) {
                loc--;
                if (ans > abs(nums[loc].first + in)) {
                    ans = abs(nums[loc].first + in);
                    ind = {nums[loc].second, i};
                } else if (ans == abs(nums[loc].first + in) && make_pair(nums[loc].second, i) < ind) {
                    ind = {nums[loc].second, i};
                }
            }
    }
    prl(ans);
    prl(ind.first+1,ind.second+1);
    return 0;
}