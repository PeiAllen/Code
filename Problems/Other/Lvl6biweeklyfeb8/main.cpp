#include<bits/stdc++.h>
using namespace std;
template<typename T>
int sz(T &a){return (int)a.size();}
typedef long long int lli;
typedef pair<lli,lli> pll;
const int MAXN=3e5+1;

struct node{
    map<char,int> to;
    int link,len;
    int loc;
    bool clone;
    node(int p,int size,bool c, int l){
        link=p,len=size,clone=c,loc=l;
    }
};
lli best[MAXN];
struct seg{
    lli data,lazy;
    int  le, ri;
    struct seg* left,*right;
    seg(){
        data=-1e18,lazy=-1e18,le=0,ri=0,left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(l!=r){
            left=new seg();
            right=new seg();
            left->mt(le,mid());
            right->mt(mid()+1,ri);
        }
    }
    void rl(){
        data=max(data,lazy);
        if(left){
            left->lazy=max(left->lazy,lazy);
            right->lazy=max(right->lazy,lazy);
        }
        lazy=-1e18;
    }
    void update(int l, int r, lli val){
        rl();
        if(le>r||ri<l)return;
        if(le>=l&&ri<=r){
            lazy=val;
            rl();
            return;
        }
        left->update(l,r,val),right->update(l,r,val);
        data=max(left->data,right->data);
    }
    void pr(){
        rl();
        if(le==ri){
            best[le]=data;
            return;
        }
        left->pr(),right->pr();
    }
};
vector<node> sufauto;
lli arr[MAXN];
lli dp[3*MAXN];
int deg[3*MAXN];
lli presum[MAXN];
int last=0;
pll maxval[3*MAXN][2];
vector<int> order;
pll maxit(pll a, pll b){
    vector<lli> te={a.first,a.second,b.first,b.second};
    sort(te.begin(),te.end(),greater<lli>());
    return {te[0],te[1]};
}
void toposort(){
    queue<int> todo;
    for(int i=0;i<sz(sufauto);i++){
        if(deg[i]==0){
            todo.push(i);
        }
    }
    while(sz(todo)){
        int cur=todo.front();
        todo.pop();
        order.push_back(cur);
        if(cur){
            deg[sufauto[cur].link]--;
            if(deg[sufauto[cur].link]==0){
                todo.push(sufauto[cur].link);
            }
        }
    }
    order.pop_back();
}
void addchar(char c, int loc){
    int cur=sz(sufauto);
    sufauto.push_back(node(-1,sufauto[last].len+1,false,loc));
    int parent=last;
    while(parent!=-1&&!sufauto[parent].to.count(c)){
        sufauto[parent].to[c]=cur;
        parent=sufauto[parent].link;
    }
    if(parent==-1)sufauto[cur].link=0;
    else{
        int oth=sufauto[parent].to[c];
        if(sufauto[oth].len==sufauto[parent].len+1){
            sufauto[cur].link=oth;
        }
        else{
            int clone=sz(sufauto);
            sufauto.push_back(node(sufauto[oth].link,sufauto[parent].len+1,true,-1));
            sufauto[clone].to=sufauto[oth].to;
            sufauto[oth].link=clone;
            sufauto[cur].link=clone;
            while(parent!=-1&&sufauto[parent].to.count(c)&&sufauto[parent].to[c]==oth){
                sufauto[parent].to[c]=clone;
                parent=sufauto[parent].link;
            }
        }
    }
    last=cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    sufauto={node(-1,0,false,-1)};
    int loc=0;
    for(char x:s)addchar(x,loc),loc++;
    for(int i=0;i<n;i++)cin>>arr[n-i-1];
    maxval[0][0]={-1,-1};
    maxval[0][1]={-1,-1};
    for(int i=1;i<sz(sufauto);i++){
        if(!sufauto[i].clone)dp[i]=1;
        maxval[i][0]={-1,-1};
        maxval[i][1]={-1,-1};
        if(sufauto[i].loc!=-1){
            if(arr[sufauto[i].loc]>0)maxval[i][0]={arr[sufauto[i].loc],-1};
            else  maxval[i][1]={abs(arr[sufauto[i].loc]),-1};
        }
        deg[sufauto[i].link]++;
    }
    toposort();
    seg tree;
    tree.mt(0,n-1);
    for(int i:order){
        if(maxval[i][0].second==-1&&maxval[i][1].second==-1){
            if(maxval[i][0].first!=-1&&maxval[i][1].first!=-1)tree.update(sufauto[sufauto[i].link].len + 1,sufauto[i].len,-maxval[i][1].first*maxval[i][0].first);
        }
        else tree.update(sufauto[sufauto[i].link].len + 1,sufauto[i].len,max(maxval[i][0].first*maxval[i][0].second,maxval[i][1].first*maxval[i][1].second));
        presum[sufauto[sufauto[i].link].len + 1] += dp[i] * (dp[i] - 1) / 2;
        presum[sufauto[i].len + 1] -= dp[i] * (dp[i] - 1) / 2;
        dp[sufauto[i].link] += dp[i];
        maxval[sufauto[i].link][0]=maxit(maxval[sufauto[i].link][0],maxval[i][0]);
        maxval[sufauto[i].link][1]=maxit(maxval[sufauto[i].link][1],maxval[i][1]);
    }
    if(maxval[0][0].second==-1&&maxval[0][1].second==-1){
        if(maxval[0][0].first!=-1&&maxval[0][1].first!=-1)tree.update(0,0,-maxval[0][1].first*maxval[0][0].first);
    }
    else tree.update(0,0,max(maxval[0][0].first*maxval[0][0].second,maxval[0][1].first*maxval[0][1].second));
    presum[0] += dp[0] * (dp[0] - 1) / 2;
    presum[1] -= dp[0] * (dp[0] - 1) / 2;
    tree.pr();
    for(int i=0;i<n;i++){
        if(i)presum[i]+=presum[i-1];
        printf("%lli %lli\n",presum[i],(presum[i]?best[i]:0));
    }
    return 0;
}
/*
 *
2
aa
2 -2
 */