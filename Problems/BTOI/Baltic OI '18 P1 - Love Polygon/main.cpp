#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
map<string,int> conver;
int pind=1;
int change(string a){
    if(conver.count(a))return conver[a];
    return conver[a]=pind++;
}
int matrix[MAXN];
bool done[MAXN];
int ind[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n%2){
        printf("-1\n");
        return 0;
    }
    string s,t;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        a=change(s),b=change(t);
        matrix[a]=b;
        ind[b]++;
        if(matrix[matrix[a]]==a&&a!=matrix[a])done[a]=true,done[matrix[a]]=true;
    }
    queue<int> q;
    for(int i=1;i<pind;i++)if(ind[i]==0)q.push(i);
    int ans=0;
    while(sz(q)){
        int cur=q.front();
        q.pop();
        ans++;
        done[cur]=true;
        if(!done[matrix[cur]]){
            done[matrix[cur]]=true;
            ind[matrix[matrix[cur]]]--;
            if(ind[matrix[matrix[cur]]]==0)q.push(matrix[matrix[cur]]);
            matrix[matrix[cur]]=cur;
        }
    }
    for(int i=1;i<pind;i++){
        if(!done[i]){
            int am=1;
            done[i]=true;
            int cur=matrix[i];
            while(cur!=i){
                am++;
                done[cur]=true;
                cur=matrix[cur];
            }
            ans+=(am+1)/2;
        }
    }
    printf("%d\n",ans);
    return 0;
}