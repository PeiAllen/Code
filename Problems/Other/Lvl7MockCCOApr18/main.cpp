#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<int> getpath(const string& a){
    vector<pii> path;
    for(char x:a){
        if(x=='1'||x=='2'){
            if(sz(path)&&path.back().first==x-'0'){
                path.back().second++;
            }
            else{
                path.push_back({x-'0',1});
            }
        }
        else if(x=='U'){
            path.back().second--;
            if(path.back().second==0)path.pop_back();
        }
        else if(x=='L'){
            if(path.back().first==2){
                path.back().second--;
                if(path.back().second==0)path.pop_back();
                if(sz(path)&&path.back().first==1){
                    path.back().second++;
                }
                else path.push_back({1,1});
            }
            else{
                auto te=path.back();
                path.pop_back();
                path.back().second--;
                if(path.back().second==0)path.pop_back();
                if(sz(path)&&path.back().first==1){
                    path.back().second++;
                }
                else path.push_back({1,1});
                path.push_back({2,te.second});
            }
        }
        else{
            if(path.back().first==1){
                path.back().second--;
                if(path.back().second==0)path.pop_back();
                if(sz(path)&&path.back().first==2){
                    path.back().second++;
                }
                else path.push_back({2,1});
            }
            else{
                auto te=path.back();
                path.pop_back();
                path.back().second--;
                if(path.back().second==0)path.pop_back();
                if(sz(path)&&path.back().first==2){
                    path.back().second++;
                }
                else path.push_back({2,1});
                path.push_back({1,te.second});
            }
        }
    }
    vector<int> ret;
    for(auto x:path){
        for(int i=0;i<x.second;i++){
            ret.push_back(x.first);
        }
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    vector<int> ap=getpath(a),bp=getpath(b);
    if(sz(ap)<sz(bp))swap(ap,bp);
    lli ans=0;
    while(sz(ap)>sz(bp)){
        ap.pop_back();
        ans++;
    }
    lli diff=0;
    lli best=LLONG_MAX;
    best=min(best,diff+2*(sz(ap)));
    for(int i=0;i<sz(ap);i++){
        if(diff){
            diff+=(diff-1);
            if(ap[i]==1)diff++;
            if(bp[i]==2)diff++;
        }
        else{
            if(ap[i]!=bp[i]){
                if(bp[i]==1)swap(ap,bp);
                diff=1;
            }
        }
        if(diff>3e5)break;
        best=min(best,diff+2*(sz(ap)-(i+1)));
    }
    printf("%lli\n",ans+best);
    return 0;
}