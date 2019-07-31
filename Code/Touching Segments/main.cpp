/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Allen
 *
 * Created on April 13, 2019, 5:24 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
struct pa{
    int cur,left;
    pa(int a=0, int d=-1):cur(a),left(d){}
    bool operator<(const pa &rhs)const{
        if(cur==rhs.cur){
            return left>rhs.left;
        }
        return cur>rhs.cur;
    }
};
struct node{
    int data;
    int lazy;
    int le;
    int ri;
struct node *left;
    struct node *right;
    node(){
        data=0;
        lazy=0;
        left=NULL;
        right=NULL;
        le=0;
        ri=0;
    }
    void make(int l, int r){
        le=l;
        ri=r;
        if(le!=ri){
            left= new node();
            right= new node();
            int mid=le+(ri-le)/2;
            left->make(le,mid);
            right->make(mid+1,ri);
        }
    }
    int maxin(int loc, int a){
        int mid=le+(ri-le)/2;
        if(le==ri){
            data=a;
        }
        else if(loc<=mid){
            int temp=left->maxin(loc,a);
            data=max(temp,right->data);
        }
        else{
            int temp=right->maxin(loc,a);
            data=max(temp,left->data);
        }
        return data;
    }
    void maxrange(int l,int r, int a){
        data+=lazy;
        if(left!=NULL){
        left->lazy+=lazy;
        }
        if(right!=NULL){
        right->lazy+=lazy;
        }
        lazy=0;
        if(le>ri||le>r||ri<l){
            return;
        }
        if(le>=l&&ri<=r){
            data+=a;
            if(right!=NULL){
            right->lazy+=a;
            }
            if(left!=NULL){
            left->lazy+=a;
            }
            return;
        }
        left->maxrange(l,r,a);
        right->maxrange(l,r,a);
        data=max(left->data,right->data);
    }
    int maxa(int l,int r){
        data+=lazy;
        if(left!=NULL){
        left->lazy+=lazy;
        }
        if(right!=NULL){
        right->lazy+=lazy;
        }
        lazy=0;
        if(le>ri||le>r||ri<l){
            return 0;
        }
        if(le>=l&&ri<=r){
            return data;
        }
        return max(left->maxa(l,r),right->maxa(l,r));
    }
}; 
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int tests=1;tests<=t;tests++){
        int n;
        cin>>n;
        int l,r;
        set<int> compress;
        unordered_map<int ,int> index;
        priority_queue<pa> qu;
        for(int i=0;i<n;i++){
            cin>>l>>r;
            compress.insert(l);
            compress.insert(r);
            qu.push(pa(l));
            qu.push(pa(r,l));
        }
        vector<int> hmm;
        for(int a:compress){
            hmm.push_back(a);
        }
        node tree;
        tree.make(1,compress.size());
        int touching=0;
        int ma=0;
        while(!qu.empty()){
            pa cur=qu.top();
            qu.pop();
            if(cur.left==-1){
                touching+=1;
            }
            else{
                touching-=1;
                cur.cur=1+(lower_bound(hmm.begin(),hmm.end(),cur.cur)-hmm.begin());
                tree.maxrange(1+(lower_bound(hmm.begin(),hmm.end(),cur.left)-hmm.begin()),cur.cur,1);
            }
            ma=max(ma,touching+tree.maxa(1,cur.cur-1));
        }
        ma=max(ma,tree.maxa(1,compress.size()));
        printf("Case %d: %d\n",tests,ma);
    }
    return 0;
}