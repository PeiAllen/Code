#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

string ree[11]={"","max, do","dhruv, fold","abayomi, open","snjezana, write","yuxuan, close","mohamed, move","scarlet, crush","anastasia, tear","aksana, press","alejandro, cut"};

int divide(int a, int b){
    return a/b;
}

int count_occurrences(string s, string pattern){
    string te=pattern+"$"+s;
    vector<int> kmp(sz(te));
    int ans=0;
    for(int i=1;i<sz(te);i++){
        int j=kmp[i-1];
        while(j>0&&te[j]!=te[i])j=kmp[j-1];
        if(te[j]==te[i])j++;
        kmp[i]=j;
        if(kmp[i]==sz(pattern))ans++;
    }
    return ans;
}

vector<int> sort_array(vector<int> arr){
    sort(arr.begin(),arr.end());
    return arr;
}

int max_size_k(vector<int> arr, int k){
    int totsum=0;
    int best=0;
    for(int i=0;i<sz(arr);i++){
        totsum+=arr[i];
        if(i-k>=0)totsum-=arr[i-k];
        best=max(best,totsum);
    }
    return best;
}

char find_upper(char ch){
    return toupper(ch);
}

bool is_prime(int n){
    if(n==1)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int distinct_integers(vector<int> arr){
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    return sz(arr);
}

bool is_inside(int x, int y, int rx, int ry, int w, int h){
    if(rx>=x&&rx<=x+w&&ry>=y&&ry<=y+h)return true;
    return false;
}

bool is_even(int n){
    return !(n&1);
}

bool is_bit_on(int bit, int num){
    return num&(1<<bit);
}

int create_max(vector<int> dig){
    sort(dig.begin(),dig.end(),greater<>());
    int val=0;
    for(auto x:dig){
        val=val*10+x;
    }
    return val;
}

int factorial(int n, int m){
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*ll(i)%ll(m);
    }
    return ans;
}

bool should_feed(int h, int m, int th){
    return h*m>=th;
}

pair<int, int> lowest_terms(int num, int denom){
    int gc=__gcd(num,denom);
    return {num/gc,denom/gc};
}

int find_sum(int n){
    return n*(n+1)/2;
}

string find_type(int type){
    return ree[type];
}

string largest_lex(vector<string> arr){
    return *max_element(arr.begin(),arr.end());
}

vector<int> add_colours(vector<int> c1, vector<int> c2){
    vector<int> te(sz(c1));
    for(int i=0;i<sz(c1);i++)te[i]=min(255,c1[i]+c2[i]);
    return te;
}

string remove_occurrences(string s, string pattern){
    string fin;
    for(int i=0;i<sz(s);i++){
        if(i+sz(pattern)<=sz(s)&&s.substr(i,sz(pattern))==pattern){
            i+=sz(pattern)-1;
        }
        else fin+=s[i];
    }
    return fin;
}

bool AC(){
    return true;
}