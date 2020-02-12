/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Allen
 *
 * Created on February 19, 2019, 6:40 PM
 */

#include <bits/stdc++.h>

using namespace std;
struct dis{
    int parent,size;
    dis(){
        parent=0;
        size=1;
    }
    dis(int a, int b):parent(a),size(b){
    }
};
dis disjoint[102];
int find(int a){
    if(disjoint[a].parent==a){
        return a;
    }
    return find(disjoint[a].parent);
}
void uni(int a, int b){
    int aparent=find(a);
    int bparent=find(b);
    if(disjoint[aparent].size>disjoint[bparent].size){
        disjoint[bparent].parent=aparent;
        disjoint[aparent].size+=disjoint[bparent].size;
    }
    else{
        disjoint[aparent].parent=bparent;
        disjoint[bparent].size+=disjoint[aparent].size;
    }
}
struct pa{
    int pen,dist,num;
    pa(){
        pen=0;
        dist=0;
        num=0;
    }
    pa(int a, int c, int d):pen(a),dist(c),num(d){
    }
};
struct ihate{
    int one,other,dist;
    ihate(){
        one=0;
        other=0;
        dist=0;
    }
    ihate(int x,int y,int z):one(x),other(y),dist(z){
    }
    bool operator<(const ihate& rhs) const {
        return dist>rhs.dist;
    }
};
/*
 * 
 */
    pa arr[1001][1001];
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int in;
    priority_queue<ihate> qu;
    for(int i=1;i<=n;i++){
        disjoint[i].parent=i;
        cin>>in;
        int temp[in];
        for(int j=0;j<in;j++){
            cin>>temp[j];
        }
        int te;
        for(int j=0;j<in;j++){
            cin>>te;
            if(arr[min(temp[j],temp[(j+1)%in])][max(temp[j],temp[(j+1)%in])].num){
                qu.push(ihate(arr[min(temp[j],temp[(j+1)%in])][max(temp[j],temp[(j+1)%in])].pen,i,arr[min(temp[j],temp[(j+1)%in])][max(temp[j],temp[(j+1)%in])].dist));
                arr[min(temp[j],temp[(j+1)%in])][max(temp[j],temp[(j+1)%in])].num=2;
            }
            else{
                arr[min(temp[j],temp[(j+1)%in])][max(temp[j],temp[(j+1)%in])]=pa(i,te,1);
            }
        }
    }
    for(int i=0;i<=1000;i++){
    for(int j=i+1;j<=1000;j++){
        if(arr[i][j].num==1){
            qu.push(ihate(0,arr[i][j].pen,arr[i][j].dist));
        }
    }
    }
    int edges=0;
    int tot=0;
    bool outside=false;
    while(!qu.empty()&&((outside&&edges<n)||(!outside&&edges<n-1))){
        ihate cur=qu.top();
        qu.pop();
        if(find(cur.one)!=find(cur.other)){
            if(cur.one==0){
                outside=true;
            }
            uni(cur.one,cur.other);
            tot+=cur.dist;
            edges+=1;
        }
    }
    printf("%d",tot);
    return 0;
    
}