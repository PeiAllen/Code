#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
const int MAXN=5e4+1;
const int MAXM=1e5+1;
pii disjoint[MAXN];
int find(int a){
	if(disjoint[a].first==a)return a;
	return find(disjoint[a].first);
}
pii ops[MAXM];
int r=-1;
void uni(int a, int b, bool addtost){
	int ap=find(a),bp=find(b);
	if(ap==bp)return;
	if(disjoint[ap].second<disjoint[bp].second) swap(ap,bp);
	if(addtost)ops[++r]={ap,bp};
	disjoint[bp].first=ap;
	disjoint[ap].second+=disjoint[bp].second;
}
void deuni(){
	pii cur=ops[r--];
	disjoint[cur.second].first=cur.second;
	disjoint[cur.first].second-=disjoint[cur.second].second;
}
int n,m,q;
vector<pair<int,pii>> edges;
pair<int,pii> edge[MAXM];
vector<pair<int,pii>> toadd;
vector<pair<int,pii>> queries;
bool add[MAXM];
vector<pii> ans;
int ch[MAXM];
int used[MAXM];
int ru=-1;
void solve(){
	for(int i=1;i<=n;i++)disjoint[i]={i,1};
	memset(add,1,sizeof(add));
	toadd.clear();
	for(auto x:edges)add[x.second.first]=0;
	for(int i=1;i<=m;i++){
		if(add[i])toadd.push_back({edge[i]});
		else edges.push_back({0,{i,edge[i].first}});
	}
	sort(edges.begin(),edges.end());
	sort(toadd.begin(),toadd.end(),greater<pair<int,pii>>());
	int loc=0;
	sort(queries.begin(),queries.end(),greater<pair<int,pii>>());
	for(auto x:queries){
		while(loc<toadd.size()&&toadd[loc].first>=x.first){
			uni(toadd[loc].second.first,toadd[loc].second.second,false);
			loc++;
		}
		int te=0;
		while(te<edges.size()&&edges[te].first<=x.second.second){
			if(!ch[edges[te].second.first])used[++ru]=edges[te].second.first;
			ch[edges[te].second.first]=edges[te].second.second;
			te++;
		}
		while(ru>=0){
			if(ch[used[ru]]>=x.first)uni(edge[used[ru]].second.first,edge[used[ru]].second.second,true);
			ch[used[ru]]=0;
			ru--;
		}
		ans.push_back({x.second.second,disjoint[find(x.second.first)].second});
		while(r>=0)deuni();
	}
	for(auto x:edges){
		edge[x.second.first].first=x.second.second;
	}
	queries.clear();
	edges.clear();
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)disjoint[i]={i,1};
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		edge[i]={c,{a,b}};
	}
	cin>>q;
	int blocksize=max(1,(int)(3*sqrt(q)));
	for(int i=1;i<=q;i++){
		cin>>a>>b>>c;
		if(a==1)edges.push_back({i,{b,c}});
		else queries.push_back({c,{b,i}});
		if((i-1)%blocksize==0)solve();
	}
	if(queries.size())solve();
	sort(ans.begin(),ans.end());
	for(auto x:ans){
		printf("%d\n",x.second);
	}
	return 0;
}