#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli width[MAXN];
lli oth[MAXN];
lli widthpsa[MAXN];
lli height[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>height[i];
    }
    for(int i=1;i<=n;i++){
        cin>>width[i];
        oth[i]=min(width[i],height[i]);
        oth[i]+=oth[i-1];
        widthpsa[i]=width[i]+widthpsa[i-1];
    }
    int l,r;
    while(q--){
        cin>>l>>r;
        if(r-l==1){
            printf("%lli\n",width[l]*(lli)2+width[r]*(lli)2+height[l]+height[r]+max(height[l],height[r]));
        }
        else if(r==l){
            printf("%lli\n",width[l]*(lli)2+height[l]*(lli)2);
        }
        else{
            printf("%lli\n",height[0]*(lli)(r-l+2)+(lli)2*(widthpsa[r]-widthpsa[l-1])+min(height[0]*(lli)(r-l),min(widthpsa[r]-widthpsa[l],widthpsa[r-1]-widthpsa[l-1])));
        }
    }
    return 0;
}