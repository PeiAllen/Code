#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct SQRT {
    struct block {
        vector<int> arr;
        int ind;
        block(){
            arr={};
            ind=0;
        }
    };
    vector<block> t;
    int mbs;
    SQRT(){
        t={block()};
        mbs=0;
    }
    void reind(int ind){for(;ind<sz(t);ind++)t[ind].ind=t[ind-1].ind+sz(t[ind-1].arr);}
    pii getith(int ind){
        int bl=upper_bound(t.begin(),t.end(),0)-t.begin()-1;
        return {bl,ind-t[bl].ind};
    }
    void insert(int ind, int val) {
        pii loc=getith(ind);
        t[loc.first].arr.insert(t[loc.first].arr.begin()+loc.second,val);
        if(sz(t[loc.first].arr)>=2*mbs){
            t.insert(t.begin()+loc.first+1,block());
            t[loc.first+1].arr.insert(t[loc.first+1].arr.begin(),t[loc.first].arr.begin()+mbs,t[loc.first].arr.end());
            t[loc.first].arr.resize(mbs);
        }
        reind(loc.first+1);
    }
    void erase(int ind){
        pii loc=getith(ind);
        t[loc.first].arr.erase(t[loc.first].arr.begin()+loc.second);
        if(sz(t[loc.first].arr)==0&&sz(t)>1)t.erase(t.begin()+loc.first);
        reind(loc.first);
    }
    void getmaxsubarray(){

    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}