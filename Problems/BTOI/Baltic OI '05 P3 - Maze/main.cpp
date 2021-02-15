#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=501;
vector<pii> matrix[MAXN*MAXN*2];
int dist[MAXN*MAXN*2][3];
int w,h;
int index(int x, int y){
    return x*w+y;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>w>>h;
    w++,h++;
    pii st,en;
    cin>>st.second>>st.first>>en.second>>en.first;
    string a;
    for(int i=0;i<h;i++){
        cin>>a;
        for(int j=0;j<sz(a);j++){
            if(a[j]!='n'){
                matrix[index(i,j)].push_back({index(i,j+1),a[j]=='b'});
                matrix[index(i,j+1)].push_back({index(i,j),a[j]=='b'});
            }
        }
        if(i!=h-1){
            cin>>a;
            for(int j=0;j*2<sz(a);j++){
                if(a[j*2]!='n'){
                    matrix[index(i,j)].push_back({index(i+1,j),a[j*2]=='b'});
                    matrix[index(i+1,j)].push_back({index(i,j),a[j*2]=='b'});
                }
                if(j*2+1<sz(a)&&a[j*2+1]!='n'){
                    matrix[index(i,j+1)].push_back({index(i+1,j),a[j*2+1]=='b'});
                    matrix[index(i+1,j)].push_back({index(i,j+1),a[j*2+1]=='b'});
                }
            }
        }
    }
    for(int i=0;i<h*w*2;i++)dist[i][0]=INT_MAX,dist[i][1]=INT_MAX,dist[i][2]=INT_MAX;
    dist[index(st.first,st.second)][2]=0;
    dist[index(st.first,st.second)][1]=0;
    dist[index(st.first,st.second)][0]=0;
    queue<pii> q;
    q.push({index(st.first,st.second),2});
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(auto x:matrix[cur.first]){
            if(x.second!=cur.second){
                if(dist[x.first][x.second]>dist[cur.first][cur.second]+1){
                    dist[x.first][x.second]=dist[cur.first][cur.second]+1;
                    q.push(x);
                }
            }
        }
    }
    printf("%d\n",*min_element(dist[index(en.first,en.second)],dist[index(en.first,en.second)]+3));
    return 0;
}