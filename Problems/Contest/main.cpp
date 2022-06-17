#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int arr[MN];
struct seg{
    struct node{
        int mi,micnt,lazy;
        node(){
            mi=0,micnt=1,lazy=0;
        }
        void apply(int val){
            mi+=val;
            lazy+=val;
        }
    }t[2*MN];
    void reset(int ind, int le, int ri){
        if(le==ri){
            t[ind]=node();
            t[ind].mi=le;
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        reset(left,le,mid),reset(right,mid+1,ri);
        t[ind].lazy=0;
        t[ind].mi=min(t[left].mi,t[right].mi);
        t[ind].micnt=(t[left].mi==t[ind].mi?t[left].micnt:0)+(t[right].mi==t[ind].mi?t[right].micnt:0);
    }
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy),t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int v){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,v),update(right,mid+1,ri,l,r,v);
        t[ind].mi=min(t[left].mi,t[right].mi);
        t[ind].micnt=(t[left].mi==t[ind].mi?t[left].micnt:0)+(t[right].mi==t[ind].mi?t[right].micnt:0);
    }
}tree;
ll solve(vector<int> per){
    tree.reset(0,0,sz(per)-1);
    stack<pii> mist,mast;
    mist.push({INT_MIN,-1});
    mast.push({INT_MAX,-1});
    ll ans=0;
    for(int i=0;i<sz(per);i++){
        tree.update(0,0,sz(per)-1,0,i-1,-1);
        tree.update(0,0,sz(per)-1,i,i,-i);
        while(mist.top().first>=per[i]){
            auto cur=mist.top();
            mist.pop();
            tree.update(0,0,sz(per)-1,mist.top().second+1,cur.second,cur.first);
        }
        tree.update(0,0,sz(per)-1,mist.top().second+1,i,-per[i]);
        mist.push({per[i],i});
        while(mast.top().first<=per[i]){
            auto cur=mast.top();
            mast.pop();
            tree.update(0,0,sz(per)-1,mast.top().second+1,cur.second,-cur.first);
        }
        tree.update(0,0,sz(per)-1,mast.top().second+1,i,per[i]);
        mast.push({per[i],i});
        if(tree.t[0].mi==0)ans+=tree.t[0].micnt;
    }
    return ans;
}
bool done[MN];
map<int,int> happened;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<int> te;
    for(int i=1;i<=k;i++){
        cin>>arr[i];
        done[arr[i]]=true;
        te.push_back(arr[i]);
    }
    if(k==n) {
        printf("%lli\n", solve(te));
        for (int i = 1; i <= n; i++)printf("%d%c", arr[i], " \n"[i == n]);
        return 0;
    }
    vector<vector<int>> missing;
    missing.push_back({});
    for(int i=1;i<=n;i++){
        if(!done[i]){
            missing.back().push_back(i);
        }
        else{
            if(sz(missing.back()))missing.push_back({});
        }
    }
    if(k<=1){
        for(int i=te[0]-1;i>=1;i--)te.push_back(i);
        for(int i=te[0]+1;i<=n;i++)te.push_back(i);
        printf("%lli\n", solve(te));
        for (int i = 1; i <= n; i++)printf("%d%c", te[i-1], " \n"[i == n]);
        return 0;
    }
    if(sz(missing.back())==0)missing.pop_back();
    map<int,int> activateone;
    map<int,vector<int>> activatetwo;
    vector<int> makehappen;
    set<int> both;
    set<int> done;
    set<int> lmfao;
    for(auto x:te)lmfao.insert(x);
    for(int i=0;i<sz(missing);i++){
        if(missing[i][0]<te.back()){
            reverse(missing[i].begin(),missing[i].end());
            makehappen.push_back(missing[i].back()-1);
            activatetwo[missing[i][0]+1].push_back(i);
            activateone[missing[i].back()-1]=i;
        }
        else{
            makehappen.push_back(missing[i].back()+1);
            activatetwo[missing[i][0]-1].push_back(i);
            activateone[missing[i].back()+1]=i;
        }
    }
    vector<int> best=te;
    happened[te.back()]=1;
    for(int i=sz(te)-1;i>=0;i--){
        happened[te[i]]++;
        queue<pii> q;
        if(activateone.count(te[i])) {
            if (both.count(activateone[te[i]])) {
                q.push({activateone[te[i]],0});
            } else {
                both.insert(activateone[te[i]]);
            }
        }
        if(happened[te[i]]==2){
            q.push({te[i],1});
        }
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            if(cur.second==0) {
                for (auto x: missing[cur.first]) {
                    best.push_back(x);
                }
                done.insert(cur.first);
                both.erase(cur.first);
                happened[makehappen[cur.first]]++;
                if (happened[makehappen[cur.first]] == 2) {
                    q.push({makehappen[cur.first],1});
                }
            }
            else{
                if(activatetwo.count(cur.first)) {
                    for(auto x:activatetwo[cur.first]) {
                        if (both.count(x)) {
                            q.push({x, 0});
                        } else {
                            both.insert(x);
                        }
                    }
                }
                else if(cur.first!=te.back()){
                    if(lmfao.count(cur.first+(cur.first>te.back()?1:-1))){
                        happened[cur.first+(cur.first>te.back()?1:-1)]++;
                        if(happened[cur.first+(cur.first>te.back()?1:-1)]==2){
                            q.push({cur.first+(cur.first>te.back()?1:-1),1});
                        }
                    }
                }
                if(cur.first==te.back()){
                    if(lmfao.count(cur.first+1)){
                        happened[cur.first+1]++;
                        if(happened[cur.first+1]==2){
                            q.push({cur.first+1,1});
                        }
                    }
                    if(lmfao.count(cur.first-1)){
                        happened[cur.first-1]++;
                        if(happened[cur.first-1]==2){
                            q.push({cur.first-1,1});
                        }
                    }
                }
            }
        }
    }
    vector<int> bruh=best;
    vector<int> tobe;
    for(auto x:both){
        tobe.push_back(x);
        for(auto y:missing[x])best.push_back(y);
    }
    reverse(tobe.begin(),tobe.end());
    for(auto x:tobe){
        for(auto y:missing[x])bruh.push_back(y);
    }
    ll bestans=solve(best),bruhans=solve(bruh);
    if(bruhans>bestans){
        bestans=bruhans;
        best=bruh;
    }
    printf("%lli\n",solve(best));
    for(auto x:best)printf("%d%c",x," \n"[x==best.back()]);
    return 0;
}