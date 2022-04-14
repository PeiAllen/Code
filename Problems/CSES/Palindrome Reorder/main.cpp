#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    map<char,int> am;
    for(auto x:a){
        am[x]++;
    }
    vector<char> odd;
    string ans;
    for(auto x:am){
        for(int i=0;i<x.second/2;i++)ans+=x.first;
        if(x.second%2==1)odd.push_back(x.first);
    }
    if(sz(odd)>1){
        printf("NO SOLUTION\n");
    }
    else{
        string x=ans;
        reverse(x.begin(),x.end());
        if(sz(odd))ans.push_back(odd[0]);
        ans+=x;
        printf("%s\n",ans.c_str());
    }
    return 0;
}