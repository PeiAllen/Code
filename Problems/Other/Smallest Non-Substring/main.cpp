#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
struct trie{
    struct node{
        int to[26];
        bool empty;
        node(){
            empty=true;
            for(int i=0;i<26;i++)to[i]=-1;
        }
    };
    vector<node> t;
    trie(){
        t={node()};
    }
    void del(){
        t=vector<node>();
        t={node()};
    }
    int nn(){
        t.push_back(node());
        return sz(t)-1;
    }
    void insert(int ind, int loc, const string &a){
        if(loc==sz(a))return;
        t[ind].empty=false;
        if(t[ind].to[a[loc]-'a']==-1) {
            int te=nn();
            t[ind].to[a[loc] - 'a']=te;
        }
        insert(t[ind].to[a[loc]-'a'],loc+1,a);
    }
    string getans(int ind, int left){
        if(t[ind].empty)return "-1";
        for(int i=0;i<26;i++){
            if(t[ind].to[i]==-1){
                return string(1,'a'+i)+string(left-1,'a');
            }
            string te=getans(t[ind].to[i],left-1);
            if(te!="-1")return string(1,'a'+i)+te;
        }
        return "-1";
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int len=1;;len++){
        tree.del();
        for(int i=0;i+len<=sz(s);i++){
            tree.insert(0,0,s.substr(i,len));
        }
        string ans=tree.getans(0,len);
        if(ans!="-1"){
            printf("%s\n",ans.c_str());
            return 0;
        }
    }
    return 0;
}