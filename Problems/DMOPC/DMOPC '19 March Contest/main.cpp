#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+3;
lli val[MAXN];
vector<pii> queries[MAXN];
lli ans[MAXN];
lli ssa[MAXN];
pair<lli,pii> classes[MAXN];
lli best[MAXN];
//vector<int> lefts[MAXN];
//vector<int> rights[MAXN];
lli calc(int ind, int notsolved){
    return ssa[ind+1]+val[ind]*(lli)(ind-notsolved+1);
}
int n,m,d;
//struct seg {
//    struct node {
//        int lazy;
//        vector<int> ins[2];
//        vector<int> deq[2];
//        int lp[2], rp[2];
//        node(){
//            lazy=d+1;
//            deq[0]={};
//            deq[1]={};
//            lp[0]=0;
//            lp[1]=0;
//            rp[0]=-1;
//            rp[1]=-1;
//        }
//        void update(){
//            for(int i=0;i<2;i++){
//                while(rp[i]>=lp[i]+1&&calc(deq[i][lp[i]+1],lazy)>=calc(deq[i][lp[i]],lazy))lp[i]++;
//                while(sz(ins[i])&&ins[i].back()>=lazy){
//                    int cur=ins[i].back();
//                    ins[i].pop_back();
//                    while(rp[i]>=lp[i]&&val[cur]>val[lp[i]])lp[i]++;
//                    if(calc())
//                }
//            }
//        }
//    } t[2 * MAXN];
//    pair<vector<int>,vector<int>> mt(int ind, int le, int ri){
//        int mid=(le+ri)/2;
//        int left=ind+1,right=ind+(mid-le+1)*2;
//        if(le!=ri){
//            auto lr=mt(left,le,mid);
//            auto rr=mt(right,mid+1,ri);
//            set<int> te;
//            set<int> bad;
//            for(int x:lr.first)te.insert(x);
//            for(int x:rr.second)if(te.count(x))bad.insert(x);
//            for(int x:lr.first)if(!bad.count(x))t[ind].ins[0].push_back(x);
//            for(int x:rr.second)if(!bad.count(x))t[ind].ins[1].push_back(x);
//            for(int i=0;i<2;i++) {
//                t[ind].deq[i].resize(sz(t[ind].ins[i])+3);
//                t[ind].rp[i]=sz(t[ind].deq[i])-1;
//                t[ind].lp[i]=sz(t[ind].deq[i]);
//            }
//            vector<int> tel,ter;
//            for(int x:lr.first)if(!bad.count(x))tel.push_back(x);
//            for(int x:rr.second)if(!bad.count(x))ter.push_back(x);
//            for(int x:lr.second)ter.push_back(x);
//            for(int x:rr.first)tel.push_back(x);
//            sort(tel.begin(),tel.end());
//            sort(ter.begin(),ter.end());
//            return {tel,ter};
//        }
//        else{
//            t[ind].ins[0]=lefts[le];
//            sort(t[ind].ins[0].begin(),t[ind].ins[0].end());
//            t[ind].deq[0].resize(sz(t[ind].ins[0])+3);
//            t[ind].rp[0]=sz(t[ind].ins[0])+2;
//            t[ind].lp[0]=sz(t[ind].ins[0])+3;
//            return {t[ind].ins[0],rights[le]};
//        }
//    }
//    void rl(int ind, int le, int ri){
//        int mid=(le+ri)/2;
//        int left=ind+1,right=ind+(mid-le+1)*2;
//        t[ind].update();
//        if(le!=ri){
//            t[left].lazy=t[ind].lazy;
//            t[right].lazy=t[ind].lazy;
//        }
//    }
//    void update(int ind, int le, int ri, int day){
//        rl();
//        t[ind].lazy=day;
//    }
//};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>d;
    if(n<=5000) {
        int l, r;
        for (int i = 0; i < m; i++) {
            cin >> val[i] >> l >> r;
            classes[i] = {val[i], {l, r}};
        }
        for (int i = m - 1; i >= 0; i--) {
            ssa[i] = val[i] + ssa[i + 1];
        }
        int a, d;
        for (int i = 0; i < n; i++) {
            cin >> a >> d;
            lli tot = 0;
            lli cur = 1;
            lli ma = 0;
            for (int j = a; j < m; j++) {
                tot += val[j] * cur;
                cur++;
                if (d >= classes[j].second.first && d <= classes[j].second.second) {
                    ma = max(ma, calc(j, a));
                }
            }
            printf("%lli\n", tot - ma);
        }
    }
    else{
        int l, r;
        for (int i = 0; i < m; i++) {
            cin >> val[i] >> l >> r;
            classes[i] = {val[i], {l, r}};
        }
        for (int i = m - 1; i >= 0; i--) {
            ssa[i] = val[i] + ssa[i + 1];

        }
    }
    return 0;
}