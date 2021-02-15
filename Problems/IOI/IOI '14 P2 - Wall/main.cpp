#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e6+1;
struct seg{
    struct node{
        int lazyl,lazyr;
        node(){
            lazyl=-1,lazyr=INT_MAX;
        }
        void apply(int l, int r){
            lazyl = max(lazyl, l);
            lazyr = min(lazyr, r);
            if(lazyl>lazyr){
                if(lazyl==l)lazyr=lazyl;
                else lazyl=lazyr;
            }
        }
    }t[2*MAXN];
    void prop(int ind, int le, int ri){
        if(t[ind].lazyl==-1&&t[ind].lazyr==INT_MAX)return;
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        t[left].apply(t[ind].lazyl,t[ind].lazyr),t[right].apply(t[ind].lazyl,t[ind].lazyr);
        t[ind].lazyl=-1,t[ind].lazyr=INT_MAX;
    }
    void update(int ind, int le, int ri, int l, int r, int ma, int mi){
        if(r<le||l>ri)return;
        if(le>=l&&ri<=r){
            t[ind].apply(ma,mi);
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        update(left,le,mid,l,r,ma,mi),update(right,mid+1,ri,l,r,ma,mi);
    }
    void getans(int ind, int le, int ri, int *arr){
        if(le==ri){
            arr[le]=min(t[ind].lazyr,max(arr[le],t[ind].lazyl));
            return;
        }
        prop(ind,le,ri);
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        getans(left,le,mid,arr),getans(right,mid+1,ri,arr);
    }
}tree;
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    for(int i=0;i<k;i++){
        if(op[i]==1)tree.update(0,0,n-1,left[i],right[i],height[i],INT_MAX);
        else tree.update(0,0,n-1,left[i],right[i],-1,height[i]);
    }
    tree.getans(0,0,n-1,finalHeight);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int op[6]={1,2,2,1,1,2},left[6]={1,4,3,0,2,6},right[6]={8,9,6,5,2,7},height[6]={4,1,5,3,5,0},arr[10]={};
    buildWall(10,6,op,left,right,height,arr);
    for(int i=0;i<10;i++)printf("%d%c",arr[i]," \n"[i==10-1]);
    return 0;
}