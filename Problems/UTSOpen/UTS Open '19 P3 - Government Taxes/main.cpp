#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=5e5+1;
ll salary[MAXN];
int n,q;
struct seg {
    struct node {
        ll rev, sal, lazypc, lazyextra, lazysaladd;
        node() {
            rev = 0, sal = 0, lazypc = 0, lazyextra = 0, lazysaladd = 0;
        }
    }t[2*MAXN];
    void mt(int ind, int le, int ri) {
        if (le != ri) {
            int mid = (le + ri) / 2;
            int left = ind + 1, right = ind + (mid - le + 1) * 2;
            mt(left, le, mid), mt(right, mid + 1, ri);
        } else t[ind].sal = salary[le];
    }

    void rl(int ind, int le, int ri) {
        t[ind].rev += t[ind].lazyextra + t[ind].lazypc * t[ind].sal;
        t[ind].sal += t[ind].lazysaladd;
        int mid = (le + ri) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        if (le != ri) {
            t[left].lazypc += t[ind].lazypc;
            t[left].lazyextra += t[ind].lazyextra + t[left].lazysaladd * t[ind].lazypc;
            t[left].lazysaladd += t[ind].lazysaladd;
            t[right].lazypc += t[ind].lazypc;
            t[right].lazyextra += t[ind].lazyextra + t[right].lazysaladd * t[ind].lazypc;
            t[right].lazysaladd += t[ind].lazysaladd;
        }
        t[ind].lazypc = 0,t[ind].lazyextra = 0,t[ind].lazysaladd = 0;
    }

    void update(int ind, int le, int ri, int l, int r, ll pc, ll raise) {
        rl(ind,le,ri);
        if (le > r || ri < l)return;
        if (le >= l && ri <= r) {
            t[ind].lazypc += pc;
            t[ind].lazyextra += pc * t[ind].lazysaladd;
            t[ind].lazysaladd += raise;
            rl(ind,le,ri);
            return;
        }
        int mid = (le + ri) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        update(left,le,mid,l, r, pc, raise), update(right,mid+1,ri,l, r, pc, raise);
    }

    void print(int ind, int le, int ri) {
        int mid = (le + ri) / 2;
        int left = ind + 1, right = ind + (mid - le + 1) * 2;
        rl(ind,le,ri);
        if (le == ri) {
            printf("%lli%c", t[ind].rev, " \n"[le == n]);
            return;
        }
        print(left,le,mid), print(right,mid+1,ri);
    }
}citizens;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>salary[i];
    citizens.mt(0,1,n);
    int a,l,r;
    ll x;
    while(q--){
        cin>>a>>l>>r;
        if(a==1){
            cin>>x;
            citizens.update(0,1,n,l,r,0,x);
        }
        else citizens.update(0,1,n,l,r,1,0);
    }
    citizens.print(0,1,n);
    return 0;
}