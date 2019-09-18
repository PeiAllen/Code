#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
const int MAXN=2e5+1;
vector<int> matrix[2*MAXN];
int inde[2*MAXN];
int outde[2*MAXN];
map<string,int> to;
pii dis[2*MAXN];
string oth[2*MAXN];
int find(int a){
	if(a==dis[a].first)return a;
	return dis[a].first=find(dis[a].first);
}
void uni(int a, int b){
	int ap=find(a),bp=find(b);
	if(ap==bp)return;
	if(dis[ap].second<dis[bp].second)swap(ap,bp);
	dis[bp].first=ap;
	dis[ap].second+=dis[bp].second;
}
vector<int> nodes;
int edgecnt=0;
stack<int> path;
void dfs(int loc){
	path.push(loc);
	while(matrix[loc].size()){
		int x=matrix[loc][matrix[loc].size()-1];
		matrix[loc].pop_back();
		edgecnt++;
		dfs(x);
	}
	path.pop();
	nodes.push_back(loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    sc(n,k);
    string arr[n+1];
    int cnt=1;
    map<string,int> se;
	for(int i=1;i<2*MAXN;i++)dis[i]={i,1};
    for(int i=1;i<=n;i++){
    	sc(arr[i]);
    	string a=arr[i].substr(0,k-1);
    	string b=arr[i].substr(1,k-1);
    	se[arr[i]]+=1;
    	int ai=(to.count(a)?to[a]:to[a]=cnt++);
	    int bi=(to.count(b)?to[b]:to[b]=cnt++);
	    oth[ai]=a,oth[bi]=b;
	    matrix[ai].push_back(bi);
	    outde[ai]+=1,inde[bi]+=1;
	    uni(ai,bi);
    }
	if(k==1){
		for(int i=1;i<=n;i++)pr(arr[i]);
		return 0;
	}
    int st=0;
    int en=0;
    bool work=true;
    for(int i=1;work&&i<cnt;i++){
    	if(find(i)!=find(1))work=false;
    	if(inde[i]==outde[i])continue;
    	else if(inde[i]==outde[i]+1){
    	    if(en)work=false;
    	    else en=i;
    	}
	    else if(inde[i]+1==outde[i]){
		    if(st)work=false;
		    else st=i;
	    }
	    else work=false;
    }
    if(!work&&k>1){
    	prl("-1");return 0;
    }
    dfs((st?st:1));
    while(path.size()){
    	nodes.push_back(path.top());
    	path.pop();
    }
    reverse(nodes.begin(),nodes.end());
    if((!en||nodes[nodes.size()-1]!=en)&&nodes[0]!=nodes[nodes.size()-1]){
	    prl("-1");return 0;
    }
    if(n!=edgecnt){
	    prl("-1");return 0;
    }
	string ans=oth[nodes[0]];
	for(int i=1;i<nodes.size();i++)ans+=oth[nodes[i]].back();
	prl(ans);
    return 0;
}