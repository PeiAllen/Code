#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=1e5+1;
const int MAXK=3e5+1;
template <typename T>
int sz(T &a){return (int)a.size();}
struct block{
    int pre,ind,realcnt;
    vector<int> arr;
    block(int p, int i){
        pre=p,ind=i,realcnt=0;
    }
};
int n,m,k;
int bs;
vector<block*> arr;
int who[MAXN];
int subtime[MAXN];
int pentime[MAXN];
int subcnt[MAXN];
vector<int> suborder[MAXN];
bool done[MAXN];
pii ans[MAXN][4];
pii toprint[MAXN][4];
vector<int> order[4];
block* where[MAXN];
bool isreal[MAXN];
int ind=1;
int override[MAXN];
int falsecnt=0;
pair<int,pii> subs[MAXK];
int getblock(int loc){
    return (upper_bound(arr.begin(),arr.end(),new block(loc-1,-1),[](block* lhs, block* rhs){
        return lhs->pre<rhs->pre;
    })-arr.begin())-1;
}
void insert(int val, int loc){
    int bl=getblock(loc);
    loc=loc-1-arr[bl]->pre;
    bool done=false;
    for(int i=0;i<sz(arr[bl]->arr)&&!done;i++){
        if(!loc){
            arr[bl]->arr.insert(arr[bl]->arr.begin()+i,val);
            done=true;
        }
        loc-=isreal[arr[bl]->arr[i]];
    }
    if(!done)arr[bl]->arr.insert(arr[bl]->arr.end(),val);
    arr[bl]->realcnt++;
    where[val]=arr[bl];
    if(arr[bl]->arr.size()>=2*bs){
        arr.insert(arr.begin()+bl+1,new block(-1,-1));
        arr[bl+1]->arr.insert(arr[bl+1]->arr.begin(),arr[bl]->arr.begin()+bs,arr[bl]->arr.end());
        for(int x:arr[bl+1]->arr)where[x]=arr[bl+1],arr[bl+1]->realcnt+=isreal[x],arr[bl]->realcnt-=isreal[x];
        arr[bl]->arr.resize(bs);
    }
    for(int i=bl+1;i<sz(arr);i++)arr[i]->pre=arr[i-1]->pre+arr[i-1]->realcnt,arr[i]->ind=arr[i-1]->ind+1;
}
void getinds(){
    for(int i=0;i<sz(arr);i++){
        for(int a:arr[i]->arr){
            who[ind]=a;
            ind++;
        }
    }
}
void nonreal(int val){
    isreal[val]=false;
    where[val]->realcnt--;
    for(int i=where[val]->ind+1;i<sz(arr);i++)arr[i]->pre=arr[i-1]->pre+arr[i-1]->realcnt;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    bs=sqrt(1.5*k);
    for(int i=1;i<=k;i++){
        cin>>subs[i].first>>subs[i].second.first>>subs[i].second.second;
        suborder[subs[i].first].push_back(subs[i].second.first);
        subs[i].second.first=++subcnt[subs[i].first];
    }
    for(int i=1;i<=n;i++)order[0].push_back(i);
    for(int p=1;p<=m;p++) {
        arr = {new block(0,0)};
        falsecnt=0;
        for(int i=1;i<=n;i++)override[i]=k;
        for(int i=1;i<=k;i++) {
            if(subs[i].second.first==p) {
                isreal[subs[i].first]=true;
                insert(subs[i].first, subs[i].second.second-falsecnt);
                subtime[subs[i].first]=i;
                pentime[subs[i].first]+=i;
            }
            if(subs[i].second.first>p){
                if(override[subs[i].first]==k) {
                    falsecnt++;
                    override[subs[i].first] = i;
                    nonreal(subs[i].first);
                }
            }
        }
        ind=1;
        getinds();
        int ma=0;
        for (int i = 1; i < ind; i++) {
            int diff = ma - pentime[who[i]] + 10;
            diff /= 10;
            diff = max(0, diff);
            ma = pentime[who[i]] + diff * 10;
            ans[who[i]][p]= {subtime[who[i]], diff};
            pentime[who[i]]=ma;
            order[p].push_back(who[i]);
        }
    }
    for(int p=m;p>=0;p--){
        for(int x:order[p]){
            if(!done[x]){
                done[x]=true;
                printf("%d",x);
                for(int i=1;i<=p;i++)toprint[x][suborder[x][i-1]]={ans[x][i].first,ans[x][i].second};
                for(int i=1;i<=m;i++){
                    if(toprint[x][i].first)printf(" %d/%d",toprint[x][i].first,toprint[x][i].second);
                    else printf(" -/-");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
/*
3 2 4
1 1 1
2 1 2
2 2 1
3 1 2
 */