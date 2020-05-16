#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1001;
vector<pii> matrix[MAXN];
ll dist[MAXN];
ll len[MAXN];
vector<int> recieve[MAXN];
vector<ll> dists;
vector<int> peeps;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int c,d;
        cin>>c>>d;
        for(int i=1;i<=c;i++)matrix[i].clear(),dist[i]=-1,recieve[i].clear();
        dist[1]=0;
        ll x;
        dists.clear(),peeps.clear();
        for(int i=2;i<=c;i++){
            cin>>x;
            if(x>0)dist[i]=x,dists.push_back(x),peeps.push_back(i);
            else recieve[-x].push_back(i);
        }
        int a,b;
        for(int i=0;i<d;i++){
            len[i]=-1;
            cin>>a>>b;
            matrix[a].push_back({b,i});
            matrix[b].push_back({a,i});
        }
        int l=0;
        int people=1;
        ll lastlen=0;
        sort(dists.begin(),dists.end());
        for(int i=1;i<=c;i++){
            if(people<i){
                for(int j=0;j<i-people;j++){
                    lastlen=max(lastlen,dists[l+j]);
                }
                l+=i-people;
                people+=i-people;
            }
            for(int x:recieve[i]){
                for(pii y:matrix[x]){
                    if(dist[y.first]!=-1&&dist[y.first]<lastlen+1){
                        len[y.second]=lastlen+1-dist[y.first];
                        break;
                    }
                }
                dist[x]=lastlen+1;
            }
            people+=sz(recieve[i]);
            if(sz(recieve[i]))lastlen++;
        }
        for(int x:peeps){
            for(pii y:matrix[x]){
                if(dist[y.first]!=-1&&dist[y.first]<dist[x]){
                    len[y.second]=dist[x]-dist[y.first];
                    break;
                }
            }
        }
        printf("Case #%d: ",cs);
        for(int i=0;i<d;i++){
            if(len[i]==-1)printf("1000000 ");
            else printf("%lli ",len[i]);
        }
        printf("\n");
        cs++;
    }
    return 0;
}