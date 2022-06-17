#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
    lli parent, size;
    pa(lli a=0, lli b=1):parent(a),size(b){}
};
pa disjolli[100001];
lli find(lli d){
    if(d!=disjolli[d].parent){
        disjolli[d].parent=find(disjolli[d].parent);
    }
    return disjolli[d].parent;
}
void uni(lli a,lli b){
    lli aparent=find(a);
    lli bparent=find(b);
    if(disjolli[aparent].size>disjolli[bparent].size){
        disjolli[bparent].parent=aparent;
        disjolli[aparent].size+=disjolli[bparent].size;
    }
    else{
        disjolli[aparent].parent=bparent;
        disjolli[bparent].size+=disjolli[aparent].size;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,m;
    cin>>n>>m;
    pa bridges[m];
    lli a,b;
    for(lli i=0;i<m;i++){
        cin>>a>>b;
        bridges[i]=pa(a,b);
    }
    for(lli i=1;i<=n;i++){
        disjolli[i].parent=i;
    }
    lli ans[m];
    ans[m-1]=n*(n-1)/2;
    lli connected=0;
    for(lli i=m-1;i>=1;i--){
        if(find(bridges[i].parent)!=find(bridges[i].size)) {
            connected += disjolli[find(bridges[i].parent)].size * disjolli[find(bridges[i].size)].size;
            uni(bridges[i].size, bridges[i].parent);
        }
        ans[i - 1] = max((lli) 0, n * (n - 1) / 2 - connected);
    }
    for(lli i=0;i<m;i++){
        printf("%lli\n",ans[i]);
    }
    return 0;
}