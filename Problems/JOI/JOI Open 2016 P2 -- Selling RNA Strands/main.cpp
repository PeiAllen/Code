#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
struct node{
    map<pair<char,char>,node*> go;
    int am;
    node(){
        am=0;
        go={};
    }
    void insert(string &a, int cur){
        am++;
        if(cur!=sz(a)){
            if(!go.count({a[cur],a[sz(a)-cur-1]})){
                go[{a[cur],a[sz(a)-cur-1]}]=new node();
            }
            go[{a[cur],a[sz(a)-cur-1]}]->insert(a,cur+1);
        }
    }
    void query(string &a, string&b)
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;

    return 0;
}