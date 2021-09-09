#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
unordered_map<string,int> dist;
string meow="meow";
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    queue<string> q;
    for (int i = 0; i < sz(s); i++) {
        for (int j = 1; j + i <= sz(s) && j <= 4; j++) {
            if(!dist.count(s.substr(i, j))) {
                dist[s.substr(i, j)] = 0;
                q.push(s.substr(i, j));
            }
        }
    }
    for (int i = 0; i < sz(s); i++) {
        for (int j = 5; j + i <= sz(s) && j <= 5; j++) {
            if(!dist.count(s.substr(i, 2)+s.substr(i+3, 2))) {
                dist[s.substr(i, 2)+s.substr(i+3, 2)] = 1;
                q.push(s.substr(i, 2)+s.substr(i+3, 2));
            }
        }
    }
    int ans=INT_MAX;
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        if(cur=="meow"){
            ans=min(ans,dist[cur]);
            break;
        }
        int cnt=0;
        if(cur.find('m')!=string::npos)cnt++;
        if(cur.find('e')!=string::npos)cnt++;
        if(cur.find('o')!=string::npos)cnt++;
        if(cur.find('w')!=string::npos)cnt++;
        if(cnt==0){
            ans=min(ans,4+dist[cur]);
            continue;
        }
        if(cnt==1){
            ans=min(ans,3+dist[cur]);
            continue;
        }
        if(sz(cur)+1<=4)for(int i=0;i<=sz(cur);i++){
            for(char a:meow) {
                if (!dist.count(cur.substr(0, i)+a+cur.substr(i))){
                    dist[cur.substr(0, i)+a+cur.substr(i)] = dist[cur] + 1;
                    q.push(cur.substr(0, i)+a+cur.substr(i));
                }
            }
        }
        string te=cur;
        for(int i=0;i<sz(cur);i++){
            char old=te[i];
            for(char a:meow) {
                te[i]=a;
                if (!dist.count(te)){
                    dist[te] = dist[cur] + 1;
                    q.push(te);
                }
            }
            te[i]=old;
        }
        for(int i=0;i+1<sz(cur);i++){
            swap(te[i],te[i+1]);
            if(!dist.count(te)){
                dist[te]=dist[cur]+1;
                q.push(te);
            }
            swap(te[i],te[i+1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}