#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=4e5+1;
ll arr[MAXN];
pair<int,pll> queries[MAXN];
vector<ll> weights;
struct seg{// query size, range turn off, range turn on, solo turn on, solo turn off
    struct node{
        ll soloon, rangeon;
        int solocnt,rangecnt;
        int lazy;
        node(){
            soloon=0,rangeon=0,lazy=0;
        }
    }t[2*MAXN];
    void rl(int ind, int le, int ri){
        if(t[ind].lazy==0)return;
        if(t[ind].lazy==1)t[ind].rangeon=t[ind].soloon,t[ind].rangecnt=t[ind].solocnt;
        if(t[ind].lazy==2)t[ind].rangeon=0,t[ind].rangecnt=0;
        if(le!=ri){
            int mid=le+(ri-le)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy=t[ind].lazy;
            t[right].lazy=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void range(int ind, int le, int ri, int l, int r, int type){
        rl(ind,le,ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=type;
            rl(ind,le,ri);
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        range(left,le,mid,l,r,type),range(right,mid+1,ri,l,r,type);
        t[ind].rangeon=t[left].rangeon+t[right].rangeon;
        t[ind].rangecnt=t[left].rangecnt+t[right].rangecnt;
    }
    void update(int ind, int le, int ri, int loc){
        rl(ind,le,ri);
        if(loc>ri||loc<le)return;
        if(le==ri){
            if(t[ind].soloon==0)t[ind].soloon=weights[loc],t[ind].solocnt=1;
            else t[ind].soloon=0,t[ind].solocnt=0;
            t[ind].rangeon=t[ind].soloon;
            t[ind].rangecnt=t[ind].solocnt;
            return;
        }
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,loc),update(right,mid+1,ri,loc);
        t[ind].soloon=t[left].soloon+t[right].soloon;
        t[ind].rangeon=t[left].rangeon+t[right].rangeon;
        t[ind].solocnt=t[left].solocnt+t[right].solocnt;
        t[ind].rangecnt=t[left].rangecnt+t[right].rangecnt;
    }
    ll sum(int ind, int le, int ri, int l, int r){
        rl(ind,le,ri);
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].rangeon;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return sum(left,le,mid,l,r)+sum(right,mid+1,ri,l,r);
    }
    ll cnt(int ind, int le, int ri, int l, int r){
        rl(ind,le,ri);
        if(l>ri||r<le)return 0;
        if(le>=l&&ri<=r)return t[ind].rangecnt;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return cnt(left,le,mid,l,r)+cnt(right,mid+1,ri,l,r);
    }
    int query(int ind, int le, int ri, ll val){
        rl(ind,le,ri);
        if(t[ind].rangeon<=val)return ri;
        if(le==ri)return le-1;
        int mid=le+(ri-le)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        rl(left,le,mid);
        if(t[left].rangeon<=val)return query(right,mid+1,ri,val-t[left].rangeon);
        else return query(left,le,mid,val);
    }
}tree;
map<ll,vector<int>> notused,used;
set<pair<ll,int>> fishies;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        weights.push_back(arr[i]);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>queries[i].first;
        if(queries[i].first==1)cin>>queries[i].second.first>>queries[i].second.second;
        else{
            cin>>queries[i].second.first;
            if(queries[i].first==2)weights.push_back(queries[i].second.first);
        }
    }
    sort(weights.begin(),weights.end());
    for(int i=0;i<sz(weights);i++)notused[weights[i]].push_back(i);
    for(int i=0;i<n;i++){
        fishies.insert({arr[i],notused[arr[i]].back()});
        tree.update(0,0,sz(weights),notused[arr[i]].back());
        used[arr[i]].push_back(notused[arr[i]].back());
        notused[arr[i]].pop_back();
    }
    for(int i=0;i<q;i++){
        if(queries[i].first==1){
            ll cur=queries[i].second.first;
            bool done=false;
            int am=0;
            while(cur<queries[i].second.second){
                auto it=fishies.lower_bound({cur,0});
                ll nxtfish=min(queries[i].second.second-1,(it==fishies.end()?queries[i].second.second-1:it->first));
                ll neededweight=nxtfish-cur+1;
                if(it==fishies.begin()){
                    printf("-1\n");
                    done=true;
                    break;
                }
                int right=prev(it,1)->second;
                ll totweight=tree.sum(0,0,sz(weights),0,right);
                if(totweight<neededweight){
                    printf("-1\n");
                    done=true;
                    break;
                }
                int left=tree.query(0,0,sz(weights),totweight-neededweight)+1;
                am+=tree.cnt(0,0,sz(weights),left,right);
                cur+=tree.sum(0,0,sz(weights),left,right);
                tree.range(0,0,sz(weights),left,right,2);
                if(cur<queries[i].second.second){
                    it=prev(fishies.lower_bound({cur,0}),1);
                    cur+=it->first;
                    am++;
                    tree.range(0,0,sz(weights),it->second,it->second,2);
                }
            }
            if(!done)printf("%d\n",am);
            tree.range(0,0,sz(weights),0,sz(weights),1);
        }
        else if(queries[i].first==2){
            fishies.insert({queries[i].second.first,notused[queries[i].second.first].back()});
            tree.update(0,0,sz(weights),notused[queries[i].second.first].back());
            used[queries[i].second.first].push_back(notused[queries[i].second.first].back());
            notused[queries[i].second.first].pop_back();
        }
        else{
            fishies.erase(fishies.find({queries[i].second.first,used[queries[i].second.first].back()}));
            tree.update(0,0,sz(weights),used[queries[i].second.first].back());
            notused[queries[i].second.first].push_back(used[queries[i].second.first].back());
            used[queries[i].second.first].pop_back();
        }
    }
    return 0;
}