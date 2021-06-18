#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
struct seg{
    struct node{
        int data,lazy;
        node(){
            data=0,lazy=0;
        }
        void apply(int a){
            lazy+=a;
            data+=a;
        }
    }t[2*MN];
    void rl(int ind, int le, int ri){
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazy);
        t[right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        if(l>ri||r<le||l>r)return;
        if(le>=l&&ri<=r){
            t[ind].apply(val);
            return;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=max(t[left].data,t[right].data);
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return max(query(left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree;
int suffix[MN];
vector<pair<pii,int>> updates[MN];
vector<int> kmp(const string &a){
    vector<int> arr(sz(a));
    for(int i=1;i<sz(a);i++){
        int j=arr[i-1];
        while(j>0&&a[i]!=a[j])j=arr[j-1];
        arr[i]=j+(a[i]==a[j]);
    }
    return arr;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b,s;
    cin>>a>>s>>b;
    reverse(a.begin(),a.end());
    vector<int> te=kmp(b+"^%"+s);
    for(int i=0;i<sz(s);i++)suffix[i]=te[i+2+sz(b)];
    reverse(s.begin(),s.end());
    te=kmp(a+"^%"+s);
    int ans=0;
    int last=-1,lastsuf=-1;
    for(int i=0;i<sz(s);i++){
        int end=te[sz(a)+2+(sz(s)-1-i)]+i;
        tree.update(0,0,sz(s)-1,i,sz(s)-1,-1);
        for(int j=min(last,end);j<max(last,end);j++){
            if(j<i)tree.update(0,0,sz(s)-1,i,sz(s)-1,(last<end?1:-1));
            else updates[j].push_back({{i,sz(s)-1},(last<end?1:-1)});
        }
        for(auto x:updates[i])tree.update(0,0,sz(s)-1,x.first.first,x.first.second,x.second);
        int suf=i-suffix[i];
        tree.update(0,0,sz(s)-1,max(lastsuf,suf)+1,i,1);
        tree.update(0,0,sz(s)-1,0,min(lastsuf,suf),-(i-1-lastsuf)+suffix[i]);
        for(int j=max(lastsuf,suf);j>min(lastsuf,suf);j--){
            tree.update(0,0,sz(s)-1,j,j,(lastsuf>suf?(-(i-1-lastsuf)+(i-j+1)):(-(i-1-j+1)+suffix[i])));
        }
        ans=max(ans,tree.query(0,0,sz(s)-1,0,i));
        last=end,lastsuf=suf;
    }
    printf("%d\n",ans);
    return 0;
}