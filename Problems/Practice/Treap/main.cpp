#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
mt19937 ra(time(NULL));
struct node{
    int data,size;
    lli pri;
    node* child[2];
    node(int val){
        data=val,size=1,pri=ra(),child[0]=NULL,child[1]=NULL;
    }
    int getsz(int ch){return child[ch]?child[ch]->size:0;}
    lli getpri(int ch){return child[ch]?child[ch]->pri:-1;}
    void recalc(){size=1+getsz(0)+getsz(1);}
    node* rotate(int ch){
        auto te=child[ch];
        child[ch]=te->child[!ch];
        te->child[!ch]=this;
        recalc();
        te->recalc();
        return te;
    }
    node* insert(int val){
        int ch=(val>data);
        if(child[ch])child[ch]=child[ch]->insert(val),recalc();
        else child[ch]=new node(val),recalc();
        if(child[ch]->pri>pri)return rotate(ch);
        return this;
    }
    node* del(int val){
        if(val==data){
            int ch=(getpri(1)>=getpri(0));
            if(!child[ch]){
                free(this);
                return NULL;
            }
            auto te=rotate(ch);
            te->child[!ch]=del(val);
            te->recalc();
            return te;
        }
        int ch=(val>data);
        if(child[ch]){
            child[ch]=child[ch]->del(val);
            recalc();
            if(getpri(ch)>pri)return rotate(ch);
        }
        return this;
    }
    int at(int loc){
        if(getsz(0)+1==loc)return data;
        else if(getsz(0)>=loc)return child[0]->at(loc);
        return child[1]->at(loc-getsz(0)-1);
    }
    int find(int val){
        int ch=(val>data);
        int te=child[ch]?child[ch]->find(val):INT_MAX;
        return (te==INT_MAX?(data==val?getsz(0)+1:INT_MAX):te+(ch?getsz(0)+1:0));
    }
    void print(){
        if(child[0])child[0]->print();
        printf("%d ",data);
        if(child[1])child[1]->print();
    }
};
struct treap{
    node* data;
    void insert(int val){
        if(data)data=data->insert(val);
        else data=new node(val);
    }
    void del(int val){if(data)data=data->del(val);}
    int at(int loc){return data->at(loc);}
    int find(int val){
        if(data){
            int te=data->find(val);
            if(te==INT_MAX)return -1;
            return te;
        }
        return -1;
    }
    void print(){
        if(data)data->print();
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    treap tree;
    int in;
    for(int i=0;i<n;i++){
        cin>>in;
        tree.insert(in);
    }
    char a;
    int last=0;
    while(m--){
        cin>>a>>in;
        in^=last;
        if(a=='I')tree.insert(in);
        else if(a=='R')tree.del(in);
        else if(a=='S'){
            last=tree.at(in);
            printf("%d\n",last);
        }
        else{
            last=tree.find(in);
            printf("%d\n",last);
        }
    }
    tree.print();
    return 0;
}