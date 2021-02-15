#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int head[MN];
struct edge{
    int nxt,to,dist;
    edge(int a=0,int b=0,int c=0){
        to=a,dist=b,nxt=c;
    }
}edges[2*MN];
int edgeptr=0;
bitset<MN> gone;
stack<int> path;
vector<int> cyc;
deque<pair<ll,int>> deq;
ll cyc2[2];
int bads[2];
bool dfs(int loc, int edgefrom){
    gone[loc]=true;
    path.push(loc);
    for(int ei=head[loc];ei!=-1;ei=edges[ei].nxt){
        const auto &x=edges[ei];
        if(ei!=edgefrom){
            if(gone[x.to]){
                while(1){
                    cyc.push_back(path.top());
                    path.pop();
                    if(cyc.back()==x.to)break;
                }
                return true;
            }
            else if(dfs(x.to,ei^1))return true;
        }
    }
    path.pop();
    return false;
}
pair<ll,int> dfs2(int loc, int parent){
    gone[loc]=true;
    pair<ll,int> longest={0,loc};
    for(int ei=head[loc];ei!=-1;ei=edges[ei].nxt){
        const auto &x=edges[ei];
        if(x.to!=parent) {
            pair<ll, int> te = dfs2(x.to, loc);
            longest = max(longest, {te.first + x.dist, te.second});
        }
    }
    return longest;
}
ll getdia(int loc, int parent, int bada, int badb){
    ll longest=0;
    for(int ei=head[loc];ei!=-1;ei=edges[ei].nxt){
        const auto &x=edges[ei];
        if(x.to!=parent&&x.to!=bada&&x.to!=badb)longest=max(longest,getdia(x.to,loc,bada,badb)+x.dist);
    }
    return longest;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        edges[edgeptr]=edge(a,b,head[i]),head[i]=edgeptr++;
        edges[edgeptr]=edge(i,b,head[a]),head[a]=edgeptr++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            ll tot=0;
            dfs(i,-1);
            path=stack<int>();
            ll sum=0;
            ll onenode=LLONG_MIN;
            ll psum=0;
            if(sz(cyc)==2){
                int nodecnt=0;
                for(int ei=head[cyc[0]];ei!=-1;ei=edges[ei].nxt){
                    const auto &x=edges[ei];
                    if(x.to==cyc[1]){
                        cyc2[nodecnt++]=x.dist;
                    }
                }
            }
            for(int j=0;j<2*sz(cyc);j++){
                ll best=0,dist=0;
                int bestloc=cyc[j%sz(cyc)];
                ll mi=LLONG_MAX;
                int nodecnt=0;
                for(int ei=head[cyc[j%sz(cyc)]];ei!=-1;ei=edges[ei].nxt){
                    const auto &x=edges[ei];
                    if(x.to!=cyc[(j+1)%sz(cyc)]&&x.to!=cyc[(j-1+sz(cyc))%sz(cyc)]){
                        pair<ll,int> te=dfs2(x.to,cyc[j%sz(cyc)]);
                        if(te.first+x.dist>best)best=te.first+x.dist,bestloc=te.second;
                    }
                    else{
                        bads[nodecnt++]=x.to;
                        mi=min(mi,ll(x.dist));
                        if(x.to==cyc[(j+1)%sz(cyc)]){
                            sum+=x.dist;
                            if(sz(cyc)>2)dist=x.dist;
                            else dist=cyc2[j%sz(cyc)];
                        }
                    }
                }
                onenode=max(onenode,best-mi);
                if(bestloc!=cyc[j%sz(cyc)])tot=max(tot,getdia(bestloc,0,bads[0],bads[1]));
                if(sz(deq)&&deq.front().second==j)deq.pop_front();
                if(sz(deq))tot=max(tot,deq.front().first+psum+best);
                while(sz(deq)&&deq.back().first<=best-psum)deq.pop_back();
                deq.push_back({best-psum,j+sz(cyc)});
                psum+=dist;
            }
            sum/=2;
            if(sz(cyc)==2)sum/=2;
            tot=max(tot,sum+onenode);
            deq=deque<pair<ll,int>>();
            cyc=vector<int>();
            ans+=tot;
        }
    }
    printf("%lli\n",ans);
    return 0;
}