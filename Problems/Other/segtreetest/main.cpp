#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
struct seg{
    struct node{
        int data,lazy;
        void applylazy(){
            data+=lazy;
        }
    }t[2*MAXN];
    void mergelazy(int ind, int le, int ri){
        if(le!=ri) {
            int mid = le + (ri - le) / 2;
            int left = ind + 1, right = ind + (mid - le + 1) * 2;
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void pushup(int ind, int le, int ri){
        int mid = le + (ri - le) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        t[ind].data=t[left].data+t[right].data;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        if(t[ind].lazy)t[ind].applylazy();
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy+=val;
            if(t[ind].lazy)t[ind].applylazy();
            return;
        }
        if(t[ind].lazy)mergelazy(ind,le,ri);
        int mid = le + (ri - le) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        pushup(ind, le, ri);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}