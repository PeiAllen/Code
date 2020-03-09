#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5e4+1;
int arr[MAXN];
vector<vector<int>> locs;
set<int> uses;
vector<bool> done[1001];
vector<vector<vector<int>>> best;
set<pii> use;
int precalc[1001];
vector<pii> toerase;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> coord;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        coord.push_back(arr[i]);
    }
    sort(coord.begin(),coord.end());
    coord.erase(unique(coord.begin(),coord.end()),coord.end());
    locs.resize(sz(coord));
    for(int i=0;i<n;i++){
        int loc=lower_bound(coord.begin(),coord.end(),arr[i])-coord.begin();
        locs[loc].push_back(i);
    }
    for(int i=0;i<sz(locs);i++)reverse(locs[i].begin(),locs[i].end()),uses.insert(i);
    int loc=0;
    bool dont=true;
    vector<int> primes;
    while(!sz(primes)&&loc<n) {
        if(!dont){
            int ind=lower_bound(coord.begin(),coord.end(),arr[loc])-coord.begin();
            locs[ind].pop_back();
            if(sz(locs[ind])==0)uses.erase(ind);
            loc++;
        }
        int cnt=0;
        for(int y:uses){
            if(coord[y]>=arr[loc])break;
            for (int x:locs[y]) {
                cnt++;
                int cur = x - loc;
                for (int i = 2; i <= sqrt(cur); i++) {
                    while (cur % i == 0) {
                        primes.push_back(i);
                        cur /= i;
                    }
                }
                if (cur != 1)primes.push_back(cur);
            }
            if(sz(primes))break;
        }
        dont=false;
    }
    if(!sz(primes)){
        for(int i=0;i<n;i++)printf("%d ",arr[i]);
        return 0;
    }
    sort(primes.begin(),primes.end());
    primes.erase(unique(primes.begin(),primes.end()),primes.end());
    best.resize(sz(primes));
    int ind=0;
    for(int x:primes){
        best[ind].resize(x);
        done[ind].resize(x);
        use.insert({x,ind});
        ind++;
    }
    loc++;
    for(int i=loc;i<n;i++){
        int mi=INT_MAX;
        for(auto x:use){
            if(i-(loc-1)>=x.first){
                int te=i%x.first;
                if(!done[x.second][te]){
                    for(int j=loc-1+((te-((loc-1)%x.first)>=0)?(te-((loc-1)%x.first)):(x.first+te-((loc-1)%x.first)));j<n;j+=x.first){
                        best[x.second][te].push_back(arr[j]);
                    }
                    sort(best[x.second][te].begin(),best[x.second][te].end(),greater<int>());
                    best[x.second][te].pop_back();
                    done[x.second][te]=true;
                }
                precalc[x.second]=best[x.second][te].back();
                mi = min(mi, best[x.second][te].back());
            }
            else {
                int fsdj=INT_MAX;
                for(int idk=i;idk<n;idk+=x.first){
                    fsdj=min(fsdj,arr[idk]);
                }
                precalc[x.second]=fsdj;
                mi=min(mi,fsdj);
            }
        }
        for(auto x:use){
            int te=i%x.first;
            if(precalc[x.second]!=mi)toerase.push_back(x);
            else if(i-(loc-1)>=x.first) best[x.second][te].pop_back();
        }
        for(pii x:toerase)use.erase(x);
        toerase.clear();
    }
    int k=use.begin()->first;
    vector<priority_queue<int,vector<int>,greater<int>>> fin;
    fin.resize(k);
    for(int i=0;i<n;i++){
        fin[i%k].push(arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",fin[i%k].top());
        fin[i%k].pop();
    }
    return 0;
}