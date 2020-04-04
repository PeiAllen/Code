#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
//#define lli __uint128_t
const int MAXN=7501;
lli mod;
lli fp(lli a,lli b){
    lli tot=1;
    for(lli i=1;i<=b;i*=(lli)2){
        if(b&i)tot= (tot * a) % mod;
        a = (a * a) % mod;
    }
    return tot;
}
lli ans=1;
vector<lli> nums;
lli fact[MAXN];
lli inv[MAXN];
lli oinv[MAXN];
lli n;
lli arr[MAXN];
lli arr2[MAXN];
lli arr3[MAXN];
map<lli,lli> fin;
lli gcd(lli a , lli b){
    if(b==0)return a;
    return gcd(b,a%b);
}
lli lcm(lli a,lli b){
    return a*b/gcd(a,b);
}
void way(lli cur, lli largest){
    if(cur==0){
        lli ways=fact[n];
        fin.clear();
        for(lli x:nums){
            if(fin.count(x))fin[x]+=(lli)1;
            else fin[x]=(lli)1;
            ways= (ways*inv[x]) %  (mod-1);
            ways= (((ways * fact[x]) %  (mod-1)) * oinv[x]) % (mod-1);
        }
        lli cur2=nums[0];
        for(lli i=1;i<sz(nums);i++)cur2=lcm(cur2,nums[i]);
        for(auto x:fin){
            ways= (ways*inv[x.second]) % (mod-1);
        }
        ans= (ans*fp(cur2 % mod, ways)) % mod;
        return;
    }
    for(lli i=largest;i<=cur;i++){
        nums.push_back(i);
        way(cur-i,i);
        nums.pop_back();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    freopen("exercise.in", "r", stdin);
//    freopen("exercise.out", "w", stdout);
    long long int n1,m1;
    cin >> n1 >> m1;
    n=n1,mod=m1;
    fact[0]=1;
    inv[0]=1;
    for(lli i=1;i<=n;i++){
        fact[i]= (fact[i-1]*i) %  (mod-1);
        oinv[i]=fp(i, mod - 2);
        inv[i]=fp(fact[i], mod - 2);
        assert(inv[i]==inv[i-1]*oinv[i]%mod);
    }

    way(n,1);
    long long int anste=ans;
    assert(anste>=0);
    cout<<anste<<"\n";
//    for(int i=1;i<=n;i++)arr[i]=i,arr2[i]=i;
//    lli ree=1;
//    do{
//        lli steps=1;
//        for(int i=1;i<=n;i++)arr3[arr[i]]=arr2[i];
//        for(int i=1;i<=n;i++)arr2[i]=arr3[i];
//        while(!is_sorted(arr2+1,arr2+1+n)){
//            steps++;
//            for(int i=1;i<=n;i++)arr3[arr[i]]=arr2[i];
//            for(int i=1;i<=n;i++)arr2[i]=arr3[i];
//        }
//        ree=ree*steps%mod;
//    }while(next_permutation(arr+1,arr+n+1));
//    cout<<ree;
    return 0;
}