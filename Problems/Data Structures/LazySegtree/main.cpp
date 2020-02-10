#include <bits/stdc++.h>
using namespace std;

struct node{
    int data,le,ri,lazy;
    struct node* left, *right;
    node(){
        data=0,le=0,ri=0,lazy=0;
        left=NULL,right=NULL;
    }
    int mid(){return (le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left= new node();
            right= new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
        }
    }
    void rl(){
        if(le!=ri){
            left->lazy+=lazy;
            right->lazy+=lazy;
        }
        data+=lazy;
        lazy=0;
    }
    void update(int l, int r, int val){
        rl();
        if(le>r||ri<l)return;
        if(le>=l&&ri<=r){
            lazy=val;
            rl();
            return;
        }
        left->update(l,r,val),right->update(l,r,val);
        data=left->data+right->data;
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    return 0;
}