#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int MAXR=2511;
const int MAXN=1511;
int bit[MAXR][MAXR];
int l,t;
bool arr[MAXN][1001];
pii rotate(pii point){
   return {point.first-point.second+1000,point.first+point.second};
}
void update(pii loc, int am){
    for(;loc.first<=2510;loc.first+=loc.first&-loc.first){
        int te=loc.second;
        for(;te<=2510;te+=te&-te)bit[loc.first][te]+=am;
    }
}
int query(pii loc){
    int ans=0;
    for(;loc.first>0;loc.first-=loc.first&-loc.first){
        int te=loc.second;
        for(;te>0;te-=te&-te)ans+=bit[loc.first][te];
    }
    return ans;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>l>>t;
    char a;
    int r,c;
    while(t--){
        cin>>a>>r>>c;
        if(a=='E'){
            if(r<=1510) {
                update(rotate({r, c}), 1);
                arr[r][c] = true;
            }
        }
        else if(a=='L'){
            if(r<=1510) {
                update(rotate({r, c}), -1);
                arr[r][c] = false;
            }
        }
        else{
            if(arr[r][c]||arr[r][c+1])printf("No\n");
            else printf("%d\n",query(rotate({r,c}))+query(rotate({r,c+1})));
        }
    }
    vector<int> best;
    for(int i=l+1;i<=l+510;i++){
        for(int j=1;j<=1000;j++){
            if(!arr[i][j])best.push_back(query(rotate({i,j})));
        }
    }
    sort(best.begin(),best.end());
    printf("%d\n",best[0]+best[1]);
    return 0;
}