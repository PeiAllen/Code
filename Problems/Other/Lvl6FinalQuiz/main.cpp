#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
struct nodearr{
    int data;
    nodearr* l,*r;
    nodearr(int d=0,nodearr* lt=NULL,nodearr* rt=NULL){
        data=d,l=lt,r=rt;
    }

};
int get(int id, nodearr* cur, int le, int ri){
    int ind=(le+ri)/2;
    if(cur==NULL)return 0;
    if(ind==id)return cur->data;
    if(id>ind){
        return get(id,cur->r,ind+1,ri);
    }
    else{
        return get(id,cur->l,le,ind-1);
    }
}
nodearr* setr(int id, int val, nodearr* cur, int le, int ri){
    int ind=(le+ri)/2;
    if(ind==id)return new nodearr(val,(cur?cur->l:NULL),(cur?cur->r:NULL));
    if(id>ind)return new nodearr((cur?cur->data:0),(cur?cur->l:NULL),setr(id,val,(cur?cur->r:NULL),ind+1,ri));
    else return new nodearr((cur?cur->data:0),setr(id,val,(cur?cur->l:NULL),le,ind-1),(cur?cur->r:NULL));
}
int MAXV;
vector<nodearr*> bit;
int lastloc[MAXN];
void update(int loc, int val){
    for(;loc<=MAXV;loc+=loc&-loc)bit.back()=setr(loc,max(val,get(loc,bit.back(),1,MAXV)),bit.back(),1,MAXV);
}
int query(int loc){
    int ma=0;
    for(;loc>0;loc-=loc&-loc)ma=max(ma,get(loc,bit.back(),1,MAXV));
    return ma;
}
pii queries[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vals;
    for(int i=0;i<n;i++){
        cin>>queries[i].first>>queries[i].second;
        if(queries[i].first==0){
            vals.push_back(queries[i].second);
        }
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<n;i++){
        if(queries[i].first==0)queries[i].second=(lower_bound(vals.begin(),vals.end(),queries[i].second)-vals.begin())+1;
    }
    MAXV=sz(vals);
    int type,num;
    bit.push_back(new nodearr());
    lastloc[0]=0;
    int lastsize=0;
    for(int i=1;i<=n;i++){
        type=queries[i-1].first,num=queries[i-1].second;
        if(type==0){
            bit.push_back(bit[i-1]);
            int ma=query(num);
            update(num,ma+1);
            lastsize++;
            lastloc[lastsize]=i;
        }
        else{
            bit.push_back(bit[lastloc[num]]);
            lastloc[num]=i;
            lastsize=num;
        }
        printf("%d\n",query(MAXV));
    }
    return 0;
}