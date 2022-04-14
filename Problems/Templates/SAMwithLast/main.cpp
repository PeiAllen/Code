#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
struct sam{
    struct node{
        int link,len;
        vector<pii> index;
        unordered_map<char,int> to;
        node(){
            link=-1,len=0;
            index=vector<pii>();
            to=unordered_map<char,int>();
        }
    };
    sam(){
        t={node()};
    }
    vector<node> t;
    int addchar(char c, int word, int wordindex, int p){
        int cur=sz(t);
        t.push_back(node());
        t[cur].len=t[p].len+1,t[cur].index.push_back({word,wordindex});
        while(p!=-1&&!t[p].to.count(c))t[p].to[c]=cur,p=t[p].link;
        if(p==-1)t[cur].link=0;
        else{
            int oth=t[p].to[c];
            if(t[oth].len==t[p].len+1){
                if(t[oth].len==t[cur].len){
                    t[oth].index.push_back({word,wordindex});
                    t.pop_back();
                    return oth;
                }
                else t[cur].link=oth;
            }
            else{
                if(t[cur].len==t[p].len+1){
                    t[cur].link = t[oth].link, t[cur].to = t[oth].to;
                    t[oth].link = cur;
                    while (p != -1 && t[p].to[c] == oth)t[p].to[c] = cur, p = t[p].link;
                }
                else {
                    int clone = sz(t);
                    t.push_back(node());
                    t[clone].len = t[p].len + 1;
                    t[clone].link = t[oth].link, t[clone].to = t[oth].to;//here -> no
                    t[oth].link = t[cur].link = clone;
                    while (p != -1 && t[p].to[c] == oth)t[p].to[c] = clone, p = t[p].link;
                }
            }
        }
        return cur;
    }
}solver;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        int last=0;
        for(int j=0;j<sz(a);j++){
            last=solver.addchar(a[j],i,j,last);
        }
    }
    return 0;
}