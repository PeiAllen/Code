/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 19, 2019, 6:10 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int bit[5001][5001];
int n;
struct queries{
    int a,b,c,d,t,type,index;
    queries(int a1,int b1,int t1,int type1,int c1=-1,int d1=-1, int index1=-1):a(a1),b(b1),t(t1),type(type1),c(c1),d(d1),index(index1){}
    bool operator<(const queries& rhs) const{
        if(t==rhs.t){
            return type>rhs.type;
        }
        return t>rhs.t;
    }
};
void update(int x, int y,int amount){
    for(;x<=n;x+=(x&(-x))){
        for(int j=y;j<=n;j+=(j&(-j))){
            bit[x][j]+=amount;
        }
    }
}
int start(int x, int y){
    int sum=0;
    for(;x>0;x-=(x&(-x))){
        for(int j=y;j>0;j-=(j&(-j))){
            sum+=bit[x][j];
        }
    }
    return sum;
}
int calc(int x,int y, int x1, int y1){
    if(x1<x||y1<y){
        return 0;
    }
    return start(x1,y1)-start(x1,y-1)-start(x-1,y1)+start(x-1,y-1);
}
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m,q;
    cin>>n>>m>>q;
    priority_queue<queries> qu;
    int a,b,c,d,t;
    char type;
    int ans[q];
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        a+=1;
        b+=1;
        qu.push(queries(a,b,c,0));
        qu.push(queries(a,b,d,1));
    }
    for(int i=0;i<q;i++){
        cin>>type;
        if(type=='R'){
            cin>>a>>b>>t;
            a+=1;
            b+=1;
            qu.push(queries(a,1,t,2,b,n,i));
        }
        else if(type=='C'){
            cin>>a>>b>>t;
            a+=1;
            b+=1;
            qu.push(queries(1,a,t,2,n,b,i));
        }
        else{
            cin>>a>>b>>c>>d>>t;
            a+=1;
            b+=1;
            c+=1;
            d+=1;
            qu.push(queries(a,c,t,3,b,d,i));
        }
    }
    while(!qu.empty()){
        queries cur=qu.top();
        qu.pop();
        if(cur.type==0){
            update(cur.a,cur.b,1);
        }
        else if(cur.type==1){
            update(cur.a,cur.b,-1);
        }
        else if(cur.type==2){
            ans[cur.index]=calc(cur.a,cur.b,cur.c,cur.d);
        }
        else{
            ans[cur.index]=calc(cur.a,1,cur.c,n)+calc(1,cur.b,n,cur.d)-calc(cur.a,cur.b,cur.c,cur.d);
        }
    }
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}

