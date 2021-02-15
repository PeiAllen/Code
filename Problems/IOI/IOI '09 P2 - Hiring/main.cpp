#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e5+1;
struct FRAC{
     ll num,den;
     FRAC(){num=0,den=1;}
     FRAC(ll a, ll b){
         if(b<0)b*=-1,a*=-1;
         ll gc=__gcd(abs(a),abs(b));
         num=a/gc,den=b/gc;
     }
     bool operator<(const FRAC& a)const{
         return num*a.den<a.num*den;
     }
};
int n;
ll w;
FRAC bal;
pair<FRAC,pair<ll,int>> arr[MAXN];
vector<int> tohire;
bool work(int people, bool getans){
    if(people==0)return true;
    ll sum=0;
    FRAC best(LLONG_MAX,1);
    int loc=-1;
    vector<ll> topush;
    for(int i=0;i<people-1;i++)topush.push_back(arr[i].second.first),sum+=arr[i].second.first;
    priority_queue<ll> q(less<ll>(),topush);
    for(int i=people-1;i<n;i++){
        FRAC te((sum+arr[i].second.first)*arr[i].first.num,arr[i].first.den);
        if(te<best)best=te,loc=i;
        if(!getans&&!(bal<best))return true;
        if(people>1&&arr[i].second.first<q.top()) {
            sum -= q.top(), q.pop();
            q.push(arr[i].second.first), sum += arr[i].second.first;
        }
    }
    if(getans){
        vector<pair<ll, int>> vals;
        for (int i = 0; i < loc; i++)vals.push_back(arr[i].second);
        sort(vals.begin(), vals.end());
        tohire.push_back(arr[loc].second.second);
        for (int i = 0; i < people - 1; i++)tohire.push_back(vals[i].second);
        return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>w;
    bal=FRAC(w,1);
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[i]={FRAC(a,b),{b,i+1}};
    }
    sort(arr,arr+n);
    int lo=0,hi=n;
    while(lo!=hi){
        int mid=(lo+hi+1)/2;
        if(work(mid,0))lo=mid;
        else hi=mid-1;
    }
    work(lo,1);
    printf("%d\n",sz(tohire));
    for(auto x:tohire)printf("%d\n",x);
    return 0;
}