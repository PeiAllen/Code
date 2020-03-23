#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+2;
int arr[MAXN];
int permu[MAXN];
int ind[MAXN];
struct node{
    int data;
    int le,ri;
    struct node* left,*right;
    node(){
        data=0;
        le=0,ri=0;
        left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left = new node();
            right = new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
            data=max(left->data,right->data);
        }
        else{
            data=arr[le];
        }
    }
    int query(int loc){
        if(ri<=loc)return data;
        if(mid()<loc)return max(left->data,right->query(loc));
        else return left->query(loc);
    }
    void update(int loc, int val){
        if(le>loc||ri<loc)return;
        if(le==ri){
            data=val;
            return;
        }
        left->update(loc,val),right->update(loc,val);
        data=max(left->data,right->data);
    }
};
node tree;
vector<int> queries;
void solve(int l, int r, int le, int ri){
    if(l==r){
        for(int i=le;i<=ri;i++)printf("%d ",l);
        return;
    }
    int mid=(l+r)/2;

}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ind[arr[i]]=i;
    }
    tree.mt(1,n);
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        queries.push_back(a);
    }
    queries.pop_back();
    printf("%d ",tree.data);
    solve(1,n,0,n-1);
    return 0;
}