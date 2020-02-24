#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<pair<int,int>> best[81][81];
int arr[81][81];
bool cant[81];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int mi=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(i!=j)mi=min(mi,arr[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                if(i!=l&&j!=l){
                    best[i][j].push_back({arr[i][l]+arr[l][j],l});
                }
            }
            sort(best[i][j].begin(),best[i][j].end());
            if(sz(best[i][j])>=5)best[i][j].resize(5);
        }
    }
    if(k==2){

        cant[1]=true;
        vector<int> path={1,1};
        int cur=0;
        for(int i=1;i<sz(path);i++) {
            auto te = best[path[i - 1]][path[i]].begin();
            while (te != best[path[i - 1]][path[i]].end() && cant[te->second])te++;
            if (te == best[path[i - 1]][path[i]].end()) {
                cur = INT_MAX;
                break;
            }
            cur += te->first;
        }
        printf("%d\n",cur);
        return 0;
    }
    else if(k==4){
        int ans=INT_MAX;
        cant[1]=true;
        for(int re=1;re<=n;re++){
            cant[re]=true;
            vector<int> path={1,re,1};
            int cur=0;
            for(int i=1;i<sz(path);i++){
                auto te=best[path[i-1]][path[i]].begin();
                while(te!=best[path[i-1]][path[i]].end()&&cant[te->second])te++;
                if(te==best[path[i-1]][path[i]].end()){
                    cur=INT_MAX;
                    break;
                }
                cur+=te->first;
            }
            cant[re]=false;
            ans=min(ans,cur);
        }
        printf("%d\n",ans);
    }
    else if(k==6){
        int ans=INT_MAX;
        cant[1]=true;
        for(int re=1;re<=n;re++){
            for(int j=1;j<=n;j++){
                cant[re]=true;
                cant[j]=true;
                vector<int> path={1,re,j,1};
                int cur=0;
                for(int i=1;i<sz(path);i++){
                    auto te=best[path[i-1]][path[i]].begin();
                    while(te!=best[path[i-1]][path[i]].end()&&cant[te->second])te++;
                    if(te==best[path[i-1]][path[i]].end()){
                        cur=INT_MAX;
                        break;
                    }
                    cur+=te->first;
                }
                ans=min(ans,cur);
                cant[re]=false;
                cant[j]=false;
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    else if(k==8){
        int ans=INT_MAX;
        cant[1]=true;
        for(int re=1;re<=n;re++){
            for(int j=1;j<=n;j++) {
                for(int l=1;l<=n;l++){
                    cant[re]=true;
                    cant[j]=true;
                    cant[l]=true;
                    vector<int> path={1,re,j,l,1};
                    int cur=0;
                    for(int i=1;i<sz(path);i++){
                        auto te=best[path[i-1]][path[i]].begin();
                        while(te!=best[path[i-1]][path[i]].end()&&cant[te->second])te++;
                        if(te==best[path[i-1]][path[i]].end()){
                            cur=INT_MAX;
                            break;
                        }
                        cur+=te->first;
                    }
                    ans=min(ans,cur);
                    cant[re]=false;
                    cant[j]=false;
                    cant[l]=false;
                }
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    else{
        int ans=INT_MAX;
        cant[1]=true;
        for(int re=1;re<=n;re++) {
            for (int j = 1; j <= n; j++) {
                for (int l = 1; l <= n; l++) {
                    for(int kek=1;kek<=n;kek++){
                        cant[re]=true;
                        cant[j]=true;
                        cant[l]=true;
                        cant[kek]=true;
                        vector<int> path={1,re,j,l,kek,1};
                        int cur=0;
                        for(int i=1;i<sz(path);i++){
                            auto te=best[path[i-1]][path[i]].begin();
                            while(te!=best[path[i-1]][path[i]].end()&&cant[te->second])te++;
                            if(te==best[path[i-1]][path[i]].end()){
                                cur=INT_MAX;
                                break;
                            }
                            cur+=te->first;
                            if(cur>=ans){
                                cur=INT_MAX;
                                break;
                            }
                        }
                        ans=min(ans,cur);
                        if(ans==mi*10){
                            printf("%int\n",ans);
                            return 0;
                        }
                        cant[re]=false;
                        cant[j]=false;
                        cant[l]=false;
                        cant[kek]=false;
                    }
                }
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    return 0;
}