#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x;
    string a;
    cin>>x>>a;
    set<string> gone;
    vector<string> inorder;
    while(!gone.count(a)){
        inorder.push_back(a);
        gone.insert(a);
        int l=0,r=sz(a)-1;
        string te(sz(a),'0');
        int ind=0;
        while(l<=r){
            if(ind%2==0)te[ind++]=a[l++];
            else te[ind++]=a[r--];
        }
        a=te;
    }
    x%=sz(inorder);
    cout<<inorder[(sz(inorder)-x)%sz(inorder)];
    return 0;
}