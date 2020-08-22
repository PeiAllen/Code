#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
    }t[2*MAXN];
    void rl(int ind, int le, int ri){
        t[ind].data+=t[ind].lazy;
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;

        }
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}