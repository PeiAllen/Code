#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=5001;
struct SAM{
    struct node{
        int len,link;
        map<char,int> to;
        node(int l){
            len=l,link=-1,to=map<char,int>();
        }
    };
    vector<node> t;
    int last;
    SAM(){
        t={node(0)};
        last=0;
    }
    void clear(){
        t=vector<node>();
        last=0;
        t={node(0)};
    }
    void addchar(char a){
        int cur=sz(t);
        t.push_back(t[last].len+1);
        int p=last;
        while(p!=-1&&!t[p].to.count(a))t[p].to[a]=cur,p=t[p].link;
        if(p==-1)t[cur].link=0;
        else{
            int oth=t[p].to[a];
            if(t[oth].len==t[p].len+1)t[cur].link=oth;
            else{
                int clone=sz(t);
                t.push_back(node(t[p].len+1));
                t[clone].link=t[oth].link,t[clone].to=t[oth].to;
                t[oth].link=t[cur].link=clone;
                while(p!=-1&&t[p].to[a]==oth)t[p].to[a]=clone,p=t[p].link;
            }
        }
        last=cur;
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        tree.clear();
        string a;
        cin>>a;
        for(auto x:a)tree.addchar(x);
        ll ans=0;
        for(int i=1;i<sz(tree.t);i++){
            ans+=tree.t[i].len-tree.t[tree.t[i].link].len;
        }
        printf("%lli\n",ans+1);
    }
    return 0;
}