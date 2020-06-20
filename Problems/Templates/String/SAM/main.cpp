#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e5+1;
struct SAM {
    int last,sz;
    struct node {
        map<char, int> to;
        int link,len;
        node(int a=0, int b=-1, map<char,int> c={}){
            len=a;
            link=b;
            to=c;
        }
    } t[2*MAXN];
    SAM(){
        last=0,sz=1;
    }
    void addchar(char x){
        t[sz++]=node(t[last].len+1);
        int cur=sz-1,p=last;
        last=cur;
        while(p!=-1&&!t[p].to.count(x))t[p].to[x]=cur,p=t[p].link;
        if(p==-1){
            t[cur].link=0;
            return;
        }
        int q=t[p].to[x];
        if(t[q].len==t[p].len+1){
            t[cur].link=q;
            return;
        }
        t[sz++]=node(t[p].len+1,t[q].link,t[q].to);
        t[q].link=sz-1,t[cur].link=sz-1;
        while(p!=-1&&t[p].to[x]==q)t[p].to[x]=sz-1,p=t[p].link;
    }
}ssam;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    for(char x:s)ssam.addchar(x);
    ll ans=0;
    for(int i=1;i<ssam.sz;i++)ans+=ssam.t[i].len-ssam.t[ssam.t[i].link].len;
    printf("%lli\n",ans);
    return 0;
}