#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
ll cost[MAXN];
pair<ll,int> deals[21];
vector<int> toerase[MAXN];
int ind[MAXN],rnk[MAXN],tmp[MAXN],lcp[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ll w,x,y,z;
        cin>>n>>m>>w>>x>>y>>z;
        string s;
        cin>>s;
        int ssize=sz(s);
        for(int i=1;i<ssize;i++)cost[i]=LLONG_MAX,toerase[i-1]=vector<int>();
        iota(ind,ind+ssize+1,0),sort(ind,ind+ssize,[&](auto &lhs, auto &rhs){return s[lhs]<s[rhs];}),rnk[ssize]=-1,rnk[ind[0]]=0;
        for(int i=1;i<ssize;i++)rnk[ind[i]]=(s[ind[i]]==s[ind[i-1]]?rnk[ind[i-1]]:i);
        for(int h=1;h<ssize;h<<=1)for(int i=0,left=0;i<ssize;i++){
            if(rnk[ind[i]]!=rnk[ind[i+1]]&&left!=i){
                sort(ind+left,ind+i+1,[&](auto &lhs, auto &rhs){return rnk[lhs+h]<rnk[rhs+h];});
                tmp[left]=rnk[ind[left]];for(int j=left+1;j<=i;j++)tmp[j]=(rnk[ind[j]+h]==rnk[ind[j-1]+h]?tmp[j-1]:j);
                for(left=left+1;left<=i;left++)rnk[ind[left]]=tmp[left];
            }
            else left+=rnk[ind[i]]!=rnk[ind[i+1]];
        }
        for(int i=0,j=ind[rnk[i]+1],k=0;i<ssize;i++,k-=k>0,j=ind[rnk[i]+1]){
            while(i+k<ssize&&j+k<ssize&&s[i+k]==s[j+k])k++;
            lcp[rnk[i]]=k;
            if(rnk[i]!=ssize-1)toerase[lcp[rnk[i]]].push_back(rnk[i]);
        }
        multiset<ld> vals;
        for(int i=0;i<n;i++){
            cin>>deals[i].first>>deals[i].second;
            for(int j=0;j<m;j++){
                vals.insert(-deals[i].first);
                if(sz(vals)>m)vals.erase(vals.begin());
            }
            cost[deals[i].second]=min(cost[deals[i].second],deals[i].first);
        }
        set<pii> segments={{0,ssize-1}};
        multiset<int> lengths={ssize};
        for(int i=1;i<ssize;i++){
            for(int j=0;j<n;j++){
                if(i-deals[j].second>0&&cost[i-deals[j].second]!=LLONG_MAX)cost[i]=min(cost[i],cost[i-deals[j].second]+deals[j].first+w);
            }
            for(auto cur:toerase[i-1]){
                auto it=prev(segments.upper_bound({cur,INT_MAX}),1);
                lengths.erase(lengths.find(it->second-it->first+1));
                lengths.insert(cur-it->first+1);
                lengths.insert(it->second-cur);
                segments.insert({it->first,cur});
                segments.insert({cur+1,it->second});
                segments.erase(it);
            }
            auto it=lengths.rbegin();
            if(cost[i]!=LLONG_MAX) for (int j = 0; j < m && it != lengths.rend(); j++, it = next(it, 1)) {
                vals.insert((y * ll(ssize - abs(x - i)) * ll(ssize - abs(x - i)) + z) * (ld(*it) / ld(ssize - i + 1) * ld(*it - 1) / ld(ssize - i)) - cost[i]);\
                if(sz(vals)>m)vals.erase(vals.begin());
            }
        }
        auto it=vals.rbegin();
        for(int i=0;i<m;i++)printf("%.9Lf%c",*it," \n"[i==m-1]),it++;
    }
    return 0;
}