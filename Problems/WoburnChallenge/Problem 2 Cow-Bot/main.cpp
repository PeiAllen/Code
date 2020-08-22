#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
bool prime(ll a){
    if(a==1)return false;
    for(ll i=2;i*i<=a;i++)if(a%i==0)return false;
    return true;
}
bool ispfs(ll a){
    for(ll i=0;i*i<=a;i++){
        if(i*i==a)return true;
    }
    return false;
}
bool pali(const string& a){
    for(int i=0;sz(a)-i-1>=i;i++){
        if(a[i]!=a[sz(a)-i-1])return false;
    }
    return true;
}
bool has7(const string& a){
    for(int i=0;i<sz(a);i++)if(a[i]=='7')return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    string a;
    int b;
    ll ree;
    while(t--){
        cin>>ree>>b;
        a=to_string(ree);
        assert(stoll(a)<=214783647);
        while(b--){
            assert(sz(a));
            ll te=stoll(a);
            if(prime(te))a=to_string(te*ll(11));
            else if(ispfs(te)){
                reverse(a.begin(),a.end());
                a=to_string(te+stoll(a));
            }
            else if(pali(a))a.push_back('4');
            else if(a[0]=='2')a="5"+a;
            else if(has7(a))a.pop_back();
            else if(te%ll(6)==0)a=to_string(stoll(a.substr(1)));
            else if(sz(a)%2==0)a.insert(sz(a)/2,"1");
            else if(sz(a)%2)a=to_string(te+ll(231));
        }
        assert(sz(a));
        cout<<a<<"\n";
    }
    return 0;
}