#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=101;
vector<vector<int>> arr;
vector<set<int>> ver;
vector<set<int>> hor;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int r,c;
        cin>>r>>c;
        arr.resize(r);
        ver.resize(c);
        hor.resize(r);
        for(int i=0;i<r;i++)hor[i].clear();
        for(int i=0;i<c;i++)ver[i].clear();
        for(int i=0;i<r;i++){
            arr[i].resize(c);
            for(int j=0;j<c;j++){
                cin>>arr[i][j];
                hor[i].insert(j);
                ver[j].insert(i);
            }
        }
        lli tot=0;
        while(1){
            vector<pii> toerase;
            for(int i=0;i<r;i++){
                for(int j:hor[i]){
                        tot+=arr[i][j];
                        int cnt=0;
                        int sum=0;
                        auto x=hor[i].upper_bound(j);
                        if(x!=hor[i].end()){
                            cnt+=1;
                            sum+=arr[i][*x];
                        }
                        x=hor[i].lower_bound(j);
                        if(x!=hor[i].begin()){
                            cnt+=1;
                            x--;
                            sum+=arr[i][*x];
                        }
                        x=ver[j].upper_bound(i);
                        if(x!=ver[j].end()){
                            cnt+=1;
                            sum+=arr[*x][j];
                        }
                        x=ver[j].lower_bound(i);
                        if(x!=ver[j].begin()){
                            cnt+=1;
                            x--;
                            sum+=arr[*x][j];
                        }
                        if(cnt&&(sum+cnt-1)/cnt>arr[i][j])toerase.push_back({i,j});
                }
            }
            if(!sz(toerase))break;
            for(auto x:toerase){
                arr[x.first][x.second]=0;
                ver[x.second].erase(x.first);
                hor[x.first].erase(x.second);
            }
        }
        printf("Case #%d: %lli\n",cs,tot);
        cs++;
    }
    return 0;
}