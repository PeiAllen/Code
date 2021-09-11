#include "bits/stdc++.h"
#include "dungeons.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+1,B=11,ML=8;
vector<vector<pair<int,pair<ll,int>>>> lift[ML];//minimum to get to the lifted node and win against any >=pc[i]
int pc[ML],n,win[MN],lose[MN],strength[MN],lgain[MN];
void init(int N, vector<int> s, vector<int> p, vector<int> w, vector<int> l){
    n=N;
    pc[0]=1;
    win[n]=n,lose[n]=n,strength[n]=0,lgain[n]=0;
    for(int i=0;i<n;i++)win[i]=w[i],lose[i]=l[i],strength[i]=s[i],lgain[i]=p[i];
    for(int i=0;i<ML;i++){
        if(i)pc[i]=pc[i-1]*B;
        lift[i].resize(__lg(max(0,int(1e7)-pc[i])+n)+1,vector<pair<int,pair<ll,int>>>(n+1));
        lift[i][0][n]={n,{0,INT_MAX}};
        for(int j=0;j<n;j++){
            if(s[j]>=pc[i])lift[i][0][j]={l[j],{p[j],s[j]}};
            else lift[i][0][j]={w[j],{s[j],INT_MAX}};
        }
        for(int j=1;j<sz(lift[i]);j++){
            for(int k=0;k<=n;k++){
                lift[i][j][k].first=lift[i][j-1][lift[i][j-1][k].first].first;
                lift[i][j][k].second.first=lift[i][j-1][k].second.first+lift[i][j-1][lift[i][j-1][k].first].second.first;
                lift[i][j][k].second.second=min(lift[i][j-1][k].second.second,(lift[i][j-1][lift[i][j-1][k].first].second.second==INT_MAX?INT_MAX:max(0,int(lift[i][j-1][lift[i][j-1][k].first].second.second-min(lift[i][j-1][k].second.first,ll(1e7))))));
            }
        }
    }
}

ll simulate(int cur, int z){
    ll str=z;
    while(cur!=n){
        int level=upper_bound(pc,pc+ML,str)-pc-1;
        while(cur!=n&&str<(level==ML-1?LLONG_MAX:pc[level+1])){
            for(int i=sz(lift[level])-1;i>=0;i--){
                if(lift[level][i][cur].second.second>str||lift[level][i][cur].second.second==INT_MAX){
                    str+=lift[level][i][cur].second.first;
                    cur=lift[level][i][cur].first;
                }
            }
            if(str>=strength[cur]){
                str+=strength[cur];
                cur=win[cur];
            }
            else{
                str+=lgain[cur];
                cur=lose[cur];
            }
        }
    }
    return str;
}


//int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    return 0;
//}