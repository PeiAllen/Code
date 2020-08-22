#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
pii arr[6][501];
int standing[501][6];
ll choose[501][7];
set<vector<int>> algo;
struct state{
    int score, locs[6],unique;
    ll am;
    state(){
        score=0,unique=0,am=0;
        for(int i=0;i<6;i++)locs[i]=0;
    }
    bool operator<(const state& rhs)const {
        return score<rhs.score;
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    choose[0][0]=1;
    for(int i=1;i<=500;i++){
        choose[i][0]=1;
        for(int j=1;j<=min(6,i);j++){
            choose[i][j]=choose[i-1][j-1]+choose[i-1][j];
        }
    }
    int n,k;
    ll c;
    cin>>n>>k>>c;
    int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a;
            arr[j][i]={a,i};
        }
    }
    for(int j=0;j<k;j++){
        sort(arr[j],arr[j]+n,greater<>());
        for(int i=0;i<n;i++)standing[arr[j][i].second][j]=i;
    }
    vector<int> ree;
    for(int i=0;i<k;i++){
        ree.push_back(0);
    }
    algo.insert(ree);
    set<int> peeps;
    int sum=0;
    for(int i=0;i<k;i++){
        peeps.insert(arr[i][0].second);
        sum+=arr[i][0].first;
    }
    state fist;
    fist.score=sum,fist.unique=sz(peeps),fist.am=choose[n-sz(peeps)][k-sz(peeps)];
    priority_queue<state> q;
    q.push(fist);
    while(sz(q)){
        state cur=q.top();
        q.pop();
        if(cur.am>=c){
            printf("%d\n",cur.score);
            return 0;
        }
        c-=cur.am;
        set<int> used;
        for(int i=0;i<k;i++){
            if(used.count(i))continue;
            vector<int> godown;
            for(int j=i;j<k;j++){
                if(arr[j][cur.locs[j]].second==arr[i][cur.locs[i]].second)godown.push_back(j),used.insert(j);
            }
            state te=cur;
            bool work=true;
            for(auto x:godown) {
                te.score -= arr[x][te.locs[x]].first;
                bool done=false;
                while (te.locs[x] + 1 < n) {
                    te.locs[x]++;
                    bool baf = false;
                    int add = 1;
                    for (int j = 0; j < k && !baf; j++) {
                        if (standing[arr[x][te.locs[x]].second][j] < te.locs[j]) {
                            baf = true;
                        } else if (j!=x&&standing[arr[x][te.locs[x]].second][j] == te.locs[j])add = 0;
                    }
                    if (baf)continue;
                    te.unique += add;
                    te.score += arr[x][te.locs[x]].first;
                    done=true;
                    break;
                }
                work&=done;
            }
            if(work){
                set<int> tepeeps;
                vector<int> reete;
                for (int j = 0; j < k; j++)tepeeps.insert(arr[j][te.locs[j]].second),reete.push_back(te.locs[j]);
                te.am = choose[n - te.unique][k - sz(tepeeps)];
                if(!algo.count(reete)) {
                    q.push(te);
                    algo.insert(reete);
                }
            }
        }
    }
    assert(0);
    return 0;
}