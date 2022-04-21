#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5001;
struct sam{
    struct node{
        unordered_map<char,int> to;
        int link,len;
        node(int l=0){
            len=l;
            link=-1;
            to=unordered_map<char,int>();
        }
    };
    vector<node> t;
    int last;
    sam(){
        t={node()};
        last=0;
    }
    void clear(){
        t=vector<node>();
        t={node()};
        last=0;
    }
    void addchar(char c){
        int cur=sz(t);
        t.push_back(t[last].len+1);
        int p=last;
        last=cur;
        while(p!=-1&&!t[p].to.count(c))t[p].to[c]=cur,p=t[p].link;
        if(p==-1){
            t[cur].link=0;
            return;
        }
        int oth=t[p].to[c];
        if(t[oth].len==t[p].len+1){
            t[cur].link=oth;
            return;
        }
        int clone=sz(t);
        t.push_back(t[p].len+1);
        t[clone].to=t[oth].to,t[clone].link=t[oth].link;
        t[oth].link=clone,t[cur].link=clone;
        while(p!=-1&&t[p].to[c]==oth)t[p].to[c]=clone,p=t[p].link;
        return;
    }
}solver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        solver.clear();
        string t;
        cin>>t;
        for(auto x:t){
            solver.addchar(x);
        }
        int ans=0;
        for(int i=1;i<sz(solver.t);i++){
            ans+=solver.t[i].len-solver.t[solver.t[i].link].len;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}