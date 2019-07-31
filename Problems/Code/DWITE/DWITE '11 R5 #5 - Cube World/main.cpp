/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 20, 2019, 1:16 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int mi[21][21];
int arr[21][21];
struct pa{
    int x,y;
    pa(int a=0, int b=0):x(a),y(b){}
    bool operator==(const pa& rhs)const{
        return x==rhs.x&&y==rhs.y;
    }
};
pa dir[4]= {pa(0,1),pa(1,0),pa(-1,0),pa(0,-1)};
struct follow{
    int size;
    pa parent;
    follow(pa a=pa(), int c=1):parent(a),size(c){}
};
follow disjoint[21][21];
pa find(pa d){
   if(d.x!=disjoint[d.x][d.y].parent.x||d.y!=disjoint[d.x][d.y].parent.y){
   disjoint[d.x][d.y].parent=find(disjoint[d.x][d.y].parent);
   }
   return disjoint[d.x][d.y].parent;
   }

  void unio(pa a,pa b){
       pa aparent=find(a);
       pa bparent=find(b);
       if(aparent==bparent){
           return;
       }
       if(disjoint[aparent.x][aparent.y].size>disjoint[bparent.x][bparent.y].size){
   disjoint[bparent.x][bparent.y].parent=aparent;
   disjoint[aparent.x][aparent.y].size+=disjoint[bparent.x][bparent.y].size;
       }
       else{
       disjoint[aparent.x][aparent.y].parent=bparent;
       disjoint[bparent.x][bparent.y].size+=disjoint[aparent.x][aparent.y].size;
       }
   }
  int go(pa loc, pa par){
      pa parent=find(loc);
      if(mi[loc.x][loc.y]!=INT_MAX){
          mi[parent.x][parent.y]=min(mi[parent.x][parent.y],mi[loc.x][loc.y]);
          return mi[loc.x][loc.y]=mi[parent.x][parent.y];
      }
      int ans=INT_MAX;
      for(int i=0;i<4;i++){
          pa temp=pa(loc.x+dir[i].x,loc.y+dir[i].y);
          if(temp.x!=par.x&&temp.y!=par.y){
              int te=go(temp,loc);
            ans=min(ans,max(arr[temp.x][temp.y],te));
            if(arr[temp.x][temp.y]<te){
                unio(loc,temp);
            }
          }
      }
      parent=find(loc);
      mi[parent.x][parent.y]=min(mi[parent.x][parent.y],mi[loc.x][loc.y]);
      return mi[loc.x][loc.y]=mi[parent.x][parent.y];
  }
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    memset(mi,INT_MAX,sizeof(mi));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        mi[1][i]=arr[1][i];
    }
    for(int i=1;i<=n;i++){
        mi[i][1]=arr[i][1];
    }
    for(int i=1;i<=m;i++){
        mi[n][i]=arr[n][i];
    }
    for(int i=1;i<=n;i++){
        mi[i][m]=arr[i][m];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum+max(0,go(pa(i,j),pa(0,0))-arr[i][j]);
        }
    }
    printf("%d\n",sum);
    return 0;
}

