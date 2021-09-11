#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5e5+1;
struct seg{
    struct node{
        int data,left,right;
        node(){
            data=0,left=-1,right=-1;
        }
    };
    vector<node> t;
    int mt(int le, int ri){
        int ind=sz(t);
        t.push_back(node());
        if(le==ri)return ind;
        int mid=(le+ri)/2;
        int te=mt(le,mid);t[ind].left=te;
        te=mt(mid+1,ri);t[ind].right=te;
        return ind;
    }
    int update(int ind, int le, int ri, int loc, int val){
        if(loc>ri||loc<le)return ind;
        if(le==ri){
            int nn=sz(t);
            t.push_back(t[ind]);
            t[nn].data+=val;
            return nn;
        }
        int mid=(le+ri)/2;
        int nn=sz(t);
        t.push_back(t[ind]);
        int te=update(t[nn].left,le,mid,loc,val);t[nn].left=te;
        te=update(t[nn].right,mid+1,ri,loc,val);t[nn].right=te;
        t[nn].data=t[t[nn].left].data+t[t[nn].right].data;
        return nn;
    }
    int query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        int mid=(le+ri)/2;
        return query(t[ind].left,le,mid,l,r)+query(t[ind].right,mid+1,ri,l,r);
    }
    int walk(int indl, int indr, int le, int ri, int index){
        if(le==ri){
            if(t[indr].data-t[indl].data>=index)return le;
            return le+1;
        }
        int mid=(le+ri)/2;
        if(t[t[indr].left].data-t[t[indl].left].data>=index)return walk(t[indl].left,t[indr].left,le,mid,index);
        return walk(t[indl].right,t[indr].right,mid+1,ri,index-(t[t[indr].left].data-t[t[indl].left].data));
    }
}tree;
int n;
int root[MN];
vector<int> toinsert[MN];
//void init(int N, int A[], int B[]){
void init(int N, vector<int> A, vector<int> B){
    n=N;
    root[0]=tree.mt(1,n);
    for(int i=0;i<n;i++)toinsert[A[i]].push_back(B[i]);
    for(int i=1;i<=n;i++){
        root[i]=root[i-1];
        for(auto x:toinsert[i])root[i]=tree.update(root[i],1,n,x,1);
    }
}

//int can(int M, int K[]){
int can(int M, vector<int> K){
    vector<pair<pii,int>> st;//exc,inc
//    sort(K,K+M);
sort(K.begin(),K.end());
    int last=0;
    auto decrease=[&](){
        while(sz(st)>1&&tree.walk(root[st.back().first.first],root[st.back().first.second],1,n,st.back().second+1)>=tree.walk(root[st[sz(st)-2].first.first],root[st[sz(st)-2].first.second],1,n,st[sz(st)-2].second+1)){
            st[sz(st)-2].first.second=st.back().first.second,st[sz(st)-2].second+=st.back().second;
            st.pop_back();
        }
    };
    for(int i=0;i<M;i++){
        auto x=K[i];
        if(x!=last) {
            pair<pii, int> cur = {{last, x}, tree.query(root[x],1,n,1,x-1) - tree.query(root[last],1,n,1,x-1)};
            while(sz(st)&&tree.query(root[st.back().first.second],1,n,1,x-1)-tree.query(root[st.back().first.first],1,n,1,x-1)>st.back().second){
                cur.first.first=st.back().first.first;
                cur.second+=tree.query(root[st.back().first.second],1,n,1,x-1)-tree.query(root[st.back().first.first],1,n,1,x-1);
                st.pop_back();
            }
            st.push_back(cur);
            decrease();
        }
        int need=x;
        while(need){
            int nextval=(sz(st)>=2?tree.walk(root[st[sz(st)-2].first.first],root[st[sz(st)-2].first.second],1,n,st[sz(st)-2].second+1):n+1);
            int am=tree.query(root[st.back().first.second],1,n,1,nextval-1)-tree.query(root[st.back().first.first],1,n,1,nextval-1);
            int use=min(am-st.back().second,need);
            if(use==0)return 0;
            st.back().second+=use;
            need-=use;
            decrease();
        }
        last=x;
    }
    return 1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int gn;
    cin>>gn;
    vector<int> A(gn),B(gn);
    for(int i=0;i<gn;i++)cin>>A[i]>>B[i];
    init(gn,A,B);
    int q;
    cin>>q;
    while(q--){
        int m;
        cin>>m;
        vector<int> K(m);
        for(int i=0;i<m;i++)cin>>K[i];
        printf("%d\n",can(m,K));
    }
    return 0;
}