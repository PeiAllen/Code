#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T> int sz(const T &a){return int(a.size());}
const int MN=3e5+2;
pii arr[2][MN];
int dp[2][MN][2];//best amount, if waited to millisecond before this point
int oth[2][MN];
int n[2];
struct seg{
    struct node{
        ll data;
        bool lazydel=0;
        int left,right;
        node(){
            data=0,lazy=false;
            left=-1,right=-1;
        }
        void apply(bool del){
            if(del)data=0;
            lazydel|=del;
        }
    };
    vector<node> t;
    int nn(){
        t.push_back(node());
        return sz(t)-1;
    }
    void rl(int ind, int le, int ri){
        if(t[ind].left==-1){int te=nn();t[ind].left=te;}
        if(t[ind].right==-1){int te=nn();t[ind].right=te;}
        t[t[ind].left].apply(t[ind].lazy);
        t[t[ind].right].apply(t[ind].lazy);
        t[ind].lazy=0;
    }
    int update(int ind, int le, int ri, int loc, ll v){
        if(loc>ri||loc<le)return ind;
        if(ind==-1)ind=nn();
        if(le==ri){
            t[ind].data=max(t[ind].data,v);
            return ind;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        {int te=update(t[ind].left,le,mid,loc,v);t[ind].left=te}
        {int te=update(t[ind].right,mid+1,ri,loc,v);t[ind].right=te}
        t[ind].data=t[t[ind].left].data=t[t[ind].right].data;
        return ind;
    }
    int update(int ind, int le, int ri, int l, int r, bool v){
        if(l>ri||r<le||l>r)return ind;
        if(ind==-1)ind=nn();
        if(le>=l&&ri<=r){
            t[ind].apply(v);
            return ind;
        }
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        {int te=update(t[ind].left,le,mid,l,r,v);t[ind].left=te}
        {int te=update(t[ind].right,mid+1,ri,l,r,v);t[ind].right=te}
        t[ind].data=t[t[ind].left].data=t[t[ind].right].data;
        return ind;
    }
    ll query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le||l>r||ind==-1)return 0;
        if(le>=l&&ri<=r)return t[ind].data;
        rl(ind,le,ri);
        int mid=(le+ri)/2;
        return max(query(t[ind].left,le,mid,l,r),query(right,mid+1,ri,l,r));
    }
}tree[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n1,n2,k;
    cin>>n1>>n2>>k;
    n[0]=n1,n[1]=n2;
    for(int i=1;i<=n1;i++) {
        cin >> arr[0][i].first >> arr[0][i].second;
    }
    for(int i=1;i<=n2;i++) {
        cin >> arr[1][i].first >> arr[1][i].second;
    }
    sort(arr[0]+1,arr[0]+n1+1);
    sort(arr[1]+1,arr[1]+n2+1);
    vector<int> times;
    map<int,pair<vector<pair<int,pii>>,vector<pair<int,pii>>>> changes;
    for(int i=1;i<=n1;i++){
        times.push_back(arr[0][i].first/k);
        times.push_back(arr[0][i].second/k);
        changes[arr[0][i].first/k].first.push_back({arr[0][i].first%k,{i,0}});
        changes[arr[0][i].second/k].first.push_back({arr[0][i].second%k,{i,1}});
    }
    for(int i=1;i<=n2;i++){
        times.push_back(arr[1][i].first/k);
        times.push_back(arr[1][i].second/k);
        changes[arr[1][i].first/k].second.push_back({arr[1][i].first%k,{i,0}});
        changes[arr[1][i].second/k].second.push_back({arr[1][i].second%k,{i,1}});
        int x=upper_bound(arr[0]+1,arr[0]+n1+1,pii{arr[1][i].first,INT_MAX})-arr[0];
        x--;
        if(x>=1&&arr[0][x].second>=arr[1][i].first)oth[1][i]=x;
        else oth[1][i]=-x;
    }
    for(int i=1;i<=n1;i++){
        int x=upper_bound(arr[1]+1,arr[1]+n2+1,pii{arr[0][i].first,INT_MAX})-arr[1];
        x--;
        if(x>=1&&arr[1][x].second>=arr[0][i].first)oth[0][i]=x;
        else oth[0][i]=-x;
    }
    dp[0][0][0]=0;
    dp[0][0][1]=INT_MIN;
    dp[1][0][0]=0;
    dp[1][0][1]=INT_MIN;
    for(int j=1;j<=max(n1,n2);j++){
        dp[0][j][0]=0;
        dp[0][j][1]=INT_MIN;
    }
    for(int j=1;j<=max(n1,n2);j++){
        dp[1][j][0]=(arr[1][j].first>=k?0:INT_MIN);
        dp[1][j][1]=INT_MIN;
    }
    oth[0][n1+1]=n2+1,oth[1][n2+1]=n1+1;
    arr[0][n1+1]={INT_MAX,INT_MAX};
    arr[1][n2+1]={INT_MAX,INT_MAX};
    tree[0].update(0,0,k-1,0,0);
    sort(times.begin(),times.end());
    times.erase(unique(times.begin(),times.end()),times.end());
    int prev=0;
    int activeinterval[2]={0,0};
    for(auto cur:times){
        int loc=(cur)%2;
        vector<vector<pair<int,pii>>> curchanges;
        curchanges.push_back(changes[cur].first);
        curchanges.push_back(changes[cur].second);
        for(int i=0;i<2;i++){
            //accounting for all intervals between
            if(prev<cur-1){

            }
            sort(curchanges[i].begin(),curchanges[i].end());
            if(!sz(curchanges[i])||curchanges[i].front().first>0){
                curchanges[i].insert(curchanges[i].begin(),{0,{-1,-1}});
            }
            curchanges[i].push_back({k,{-1,-1}});
            for(int j=0;j<sz(curchanges[i])-1;j++){
                if(curchanges[i][j].second.second==0){//insert
                    activeinterval[i]=curchanges[i][j].second.first;

                }
                else if(curchanges[i][j].second.second==1){//delete
                    activeinterval[i]=0;
                }
                int nextstart=lower_bound(arr[i]+1,arr[i]+n[i]+1,pii{curchanges[i][j].first+1,INT_MAX})-arr[i];
                if(nextstart==n[i]+1||oth[i][nextstart]<=0||arr[!i][oth[i][nextstart]].first>=curchanges[i][j+1].first+(cur-1)*k){
                    dp[i][nextstart][0]=max(dp[i][nextstart][0],int(cur+tree[loc].query(0,0,k-1,curchanges[i][j].first,curchanges[i][j+1].first)));
                }
                else{
                    if(arr[!i][oth[i][nextstart]].first<=curchanges[i][j].first+(cur-1)*k) {
                        dp[i][nextstart][1] = max(dp[i][nextstart][1], int(cur + tree[loc].query(0, 0, k - 1, curchanges[i][j].first, curchanges[i][j + 1].first)));
                    }
                    else{

                    }
                }
            }
            loc=!loc;
        }
        prev=cur;
    }
    printf("%d\n",);
    return 0;
}