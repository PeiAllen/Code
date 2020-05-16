#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
struct seg{
    struct node{
        int data,lazy,leftam,rightam,maam,data2;
        node(){
            data=0,lazy=0,leftam=0,rightam=0,maam=0,data2=0;
        }
    };
    vector<node> t;
    seg(){
        t={};
    }
    void mt(int ind, int le, int ri){
        t[ind].data2=(ri-le+1);
        if(le!=ri){
            int mid=(le+ri)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            mt(left,le,mid),mt(right,mid+1,ri);
        }
    }
    void rl(int ind, int le, int ri){
        if(!t[ind].lazy)return;
        t[ind].data+=t[ind].lazy*(ri-le+1);
        t[ind].data2-=t[ind].lazy*(ri-le+1);
        if(t[ind].data)t[ind].leftam=(ri-le+1),t[ind].rightam=(ri-le+1),t[ind].maam=(ri-le+1);
        else t[ind].leftam=0,t[ind].rightam=0,t[ind].maam=0;
        if(le!=ri){
            int mid=(le+ri)/2;
            int left=ind+1,right=ind+(mid-le+1)*2;
            t[left].lazy+=t[ind].lazy;
            t[right].lazy+=t[ind].lazy;
        }
        t[ind].lazy=0;
    }
    void update(int ind, int le, int ri, int l, int r, int val){
        rl(ind,le,ri);
        if(l>ri||r<le)return;
        if(le>=l&&ri<=r){
            t[ind].lazy=val;
            rl(ind,le,ri);
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,val),update(right,mid+1,ri,l,r,val);
        t[ind].data=t[left].data+t[right].data;
        t[ind].data2=t[left].data2+t[right].data2;
        t[ind].maam=max(t[left].maam,t[right].maam);
        t[ind].leftam=t[left].leftam+(t[left].leftam==mid-le+1?t[right].leftam:0);
        t[ind].rightam=t[right].rightam+(t[right].rightam==ri-mid?t[left].rightam:0);
        t[ind].maam=max({t[ind].maam,t[ind].leftam,t[ind].rightam,t[left].rightam+t[right].leftam});
    }
    pair<int,pii> query(int ind, int le, int ri, int l, int r){
        rl(ind,le,ri);
        if(l>ri||r<le)return {-1,{-1,-1}};
        if(le>=l&&ri<=r)return {t[ind].maam,{t[ind].leftam,t[ind].rightam}};
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        if(r<=mid)return query(left,le,mid,l,r);
        if(l>=mid+1)return query(right,le,mid,l,r);
        auto leans=query(left,le,mid,l,r),rians=query(right,mid+1,ri,l,r);
        if(rians.first==-1)return leans;
        if(leans.first==-1)return rians;
        int curans=max(leans.first,rians.first);
        int leftans=leans.second.first+(leans.second.first==mid-max(le,l)+1?rians.second.first:0);
        int rightans=rians.second.second+(rians.second.second==min(ri,r)-mid?leans.second.second:0);
        curans=max({curans,leftans,rightans,leans.second.second+rians.second.first});
        return {curans,{leftans,rightans}};
    }
    int query2(int ind, int le, int ri, int loc){
        rl(ind,le,ri);
        if(loc>ri||loc<le)return 0;
        if(le==ri)return t[ind].data2;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return query2(left,le,mid,loc)+query2(right,mid+1,ri,loc);
    }
    int lb(int ind, int le, int ri, int val){
        rl(ind,le,ri);
        if(le==ri)return le;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        rl(left,le,mid);
        if(t[left].data2>=val)return lb(left,le,mid,val);
        else return lb(right,mid+1,ri,val-t[left].data2);
    }
    int up(int ind, int le, int ri, int val){
        rl(ind,le,ri);
        if(le==ri){
            if(val>=t[ind].data2)return le+1;
            return le;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        rl(left,le,mid);
        if(t[left].data2>val)return up(left,le,mid,val);
        else return up(right,mid+1,ri,val-t[left].data2);
    }
};
vector<seg> rbit;
vector<seg> cbit;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    rbit.resize(n+1);
    cbit.resize(m+1);
    for(int i=1;i<=n;i++)rbit[i].t.resize(m*2),rbit[i].mt(0,1,m);
    for(int i=1;i<=m;i++)cbit[i].t.resize(n*2),cbit[i].mt(0,1,n);
    int x,y,z,a;
    while(q--){
        cin>>a>>x>>y>>z;
        if(a==3){
            int ans=0;
            for(int i=0;i<z;i++){
                auto te=rbit[x+i].query(0,1,m,y,y+z-1);
                int leam=y-rbit[x+i].lb(0,1,m,rbit[x+i].query2(0,1,m,y));
                int riam=max(0,rbit[x+i].up(0,1,m,rbit[x+i].query2(0,1,m,y+z-1))-(y+z));
                ans=max({ans,te.first,(te.second.first?te.second.first+leam:0),(te.second.second?riam+te.second.second:0),(te.second.first==z?leam+riam+z:0)});
                te=cbit[y+i].query(0,1,n,x,x+z-1);
                leam=x-cbit[y+i].lb(0,1,n,cbit[y+i].query2(0,1,n,x));
                riam=max(0,cbit[y+i].up(0,1,n,cbit[y+i].query2(0,1,n,x+z-1))-(x+z));
                ans=max({ans,te.first,(te.second.first?te.second.first+leam:0),(te.second.second?riam+te.second.second:0),(te.second.first==z?leam+riam+z:0)});
            }
            printf("%d\n",ans);
        }
        else{
            for(int i=0;i<z;i++){
                rbit[x+i].update(0,1,m,y,y+z-1,(a==1?1:-1));
                cbit[y+i].update(0,1,n,x,x+z-1,(a==1?1:-1));
            }
        }
    }
    return 0;
}