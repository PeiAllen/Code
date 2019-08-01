#include <bits/stdc++.h>
using namespace std;
int arr[50001];
vector<int> adj[50001];
vector<int> euler;
int leftt[50001];
int rightt[50001];
int depth[50001];
int lca[50001][17];
struct pa{
	int l,r, index;
	pa(int a=0, int b=0, int c=0):l(a),r(b),index(c){}
};
struct comparator{
	bool operator()(const pa& lhs, const pa& rhs){
		return lhs.l<rhs.l;
	}
};
struct comparator2{
	bool operator()(const pa& lhs, const pa& rhs){
		if(lhs.r==rhs.r)return lhs.l<rhs.l;
		return lhs.r<rhs.r;
	}
};
void geneuler(int loc, int parent){
	depth[loc]=depth[parent]+1;
	lca[loc][0]=parent;
	euler.push_back(loc);
	leftt[loc]=euler.size()-1;
	for(int i:adj[loc]){
		if(i!=parent){
			geneuler(i,loc);
		}
	}
	euler.push_back(loc);
	rightt[loc]=euler.size()-1;
}
int getlca(int a, int b){
	if(a==b){
		return a;
	}
	if(depth[a]!=depth[b]){
		if(a>b)swap(a,b);
		int depthdiff=abs(depth[a]-depth[b]);
		for(int i=0;i<=16;i++){
			if(depthdiff&(1<<i)){
				a=lca[a][i];
			}
		}
	}
	if(a==b){
		return a;
	}
	for(int i=16;i>=0;i--){
		if(lca[a][i]!=lca[b][i]){
			return getlca(lca[a][i],lca[b][i]);
		}
	}
	return lca[a][0];
}
int u,v;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(lca,0,sizeof(lca));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[1]=0;
	geneuler(1,0);
	for(int i=1;i<ceil(log2((double)n));i++) {
		for (int j = 0; j < n; j++) {
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
		}
	}
	int blocksize = ceil(sqrt((double) (2*n)));
	pa queries[q];
	for (int i = 0; i < q; i++) {
		cin>>u>>v;
		u=leftt[u];
		v=leftt[v];
		if(u>v)swap(u,v);
		queries[i]=pa(u,v,i);
	}
	int solution[q];
	sort(queries,queries+q,comparator());
	int le=0;
	for (int i = 0; i < q; i++) {
		if(leftt[queries[i].l]-leftt[queries[le].l]>=blocksize){
			sort(queries+le,queries+i,comparator2());
			int l=queries[le].l;
			int r=queries[le].r;
			bool gone[n+1];
			memset(gone,false,sizeof(gone));
			multiset<int> values;
			multiset<int> diff;
			for (int j = l; j <=r ; j++) {
				if(gone[euler[j]]){
					values.erase(arr[euler[j]]);
					auto lot=values.lower_bound(arr[euler[j]]);
					if(lot!=values.end()) {
						diff.erase((*lot) - arr[euler[j]]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.erase(arr[euler[j]] - (*lot));
					}
					gone[euler[j]]=false;
				}
				else{
					auto lot=values.lower_bound(arr[euler[j]]);
					if(lot!=values.end()) {
						diff.insert((*lot) - arr[euler[j]]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.insert(arr[euler[j]] - (*lot));
					}
					values.insert(arr[euler[j]]);
					gone[euler[j]]=true;
				}
			}
			int tej=getlca(euler[l],euler[r]);
			if(tej!=euler[l]){
				if(gone[euler[l]]){
					values.erase(arr[euler[l]]);
					auto lot=values.lower_bound(arr[euler[l]]);
					if(lot!=values.end()) {
						diff.erase((*lot) - arr[euler[l]]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.erase(arr[euler[l]] - (*lot));
					}
					gone[euler[l]]=false;
				}
				else{
					auto lot=values.lower_bound(arr[euler[l]]);
					if(lot!=values.end()) {
						diff.insert((*lot) - arr[euler[l]]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.insert(arr[euler[l]] - (*lot));
					}
					values.insert(arr[euler[l]]);
					gone[euler[l]]=true;
				}
			}
			if(gone[tej]){
				values.erase(arr[tej]);
				auto lot=values.lower_bound(arr[tej]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[tej]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[tej] - (*lot));
				}
				gone[tej]=false;
			}
			else{
				auto lot=values.lower_bound(arr[tej]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[tej]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[tej] - (*lot));
				}
				values.insert(arr[tej]);
				gone[tej]=true;
			}
			solution[queries[le].index]=*diff.begin();
			if(tej!=euler[l]){
				if(gone[euler[l]]){
					values.erase(arr[euler[l]]);
					auto lot=values.lower_bound(arr[euler[l]]);
					if(lot!=values.end()) {
						diff.erase((*lot) - arr[euler[l]]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.erase(arr[euler[l]] - (*lot));
					}
					gone[euler[l]]=false;
				}
				else{
					auto lot=values.lower_bound(arr[euler[l]]);
					if(lot!=values.end()) {
						diff.insert((*lot) - arr[euler[l]]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.insert(arr[euler[l]] - (*lot));
					}
					values.insert(arr[euler[l]]);
					gone[euler[l]]=true;
				}
			}
			if(gone[tej]){
				values.erase(arr[tej]);
				auto lot=values.lower_bound(arr[tej]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[tej]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[tej] - (*lot));
				}
				gone[tej]=false;
			}
			else{
				auto lot=values.lower_bound(arr[tej]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[tej]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[tej] - (*lot));
				}
				values.insert(arr[tej]);
				gone[tej]=true;
			}
			for(int j=le+1;j<i;j++){
				while(r<queries[j].r){
					r+=1;
					if(gone[euler[r]]){
						values.erase(arr[euler[r]]);
						auto lot=values.lower_bound(arr[euler[r]]);
						if(lot!=values.end()) {
							diff.erase((*lot) - arr[euler[r]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.erase(arr[euler[r]] - (*lot));
						}
						gone[euler[r]]=false;
					}
					else{
						auto lot=values.lower_bound(arr[euler[r]]);
						if(lot!=values.end()) {
							diff.insert((*lot) - arr[euler[r]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.insert(arr[euler[r]] - (*lot));
						}
						values.insert(arr[euler[r]]);
						gone[euler[j]]=true;
					}
				}
				while(l<queries[j].l){
					if(gone[euler[l]]){
						values.erase(arr[euler[l]]);
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.erase((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.erase(arr[euler[l]] - (*lot));
						}
						gone[euler[l]]=false;
					}
					else{
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.insert((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.insert(arr[euler[l]] - (*lot));
						}
						values.insert(arr[euler[l]]);
						gone[euler[l]]=true;
					}
					l+=1;
				}
				while(l>queries[j].l){
					l-=1;
					if(gone[euler[l]]){
						values.erase(arr[euler[l]]);
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.erase((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.erase(arr[euler[l]] - (*lot));
						}
						gone[euler[l]]=false;
					}
					else{
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.insert((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.insert(arr[euler[l]] - (*lot));
						}
						values.insert(arr[euler[l]]);
						gone[euler[l]]=true;
					}
				}
				tej=getlca(euler[l],euler[r]);
				if(tej!=euler[l]){
					if(gone[euler[l]]){
						values.erase(arr[euler[l]]);
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.erase((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.erase(arr[euler[l]] - (*lot));
						}
						gone[euler[l]]=false;
					}
					else{
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.insert((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.insert(arr[euler[l]] - (*lot));
						}
						values.insert(arr[euler[l]]);
						gone[euler[l]]=true;
					}
				}
				if(gone[tej]){
					values.erase(arr[tej]);
					auto lot=values.lower_bound(arr[tej]);
					if(lot!=values.end()) {
						diff.erase((*lot) - arr[tej]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.erase(arr[tej] - (*lot));
					}
					gone[tej]=false;
				}
				else{
					auto lot=values.lower_bound(arr[tej]);
					if(lot!=values.end()) {
						diff.insert((*lot) - arr[tej]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.insert(arr[tej] - (*lot));
					}
					values.insert(arr[tej]);
					gone[tej]=true;
				}
				solution[queries[j].index]=*diff.begin();
				if(gone[tej]){
					values.erase(arr[tej]);
					auto lot=values.lower_bound(arr[tej]);
					if(lot!=values.end()) {
						diff.erase((*lot) - arr[tej]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.erase(arr[tej] - (*lot));
					}
					gone[tej]=false;
				}
				else{
					auto lot=values.lower_bound(arr[tej]);
					if(lot!=values.end()) {
						diff.insert((*lot) - arr[tej]);
					}
					if(lot!=values.begin()) {
						lot--;
						diff.insert(arr[tej] - (*lot));
					}
					values.insert(arr[tej]);
					gone[tej]=true;
				}
				if(tej!=euler[l]){
					if(gone[euler[l]]){
						values.erase(arr[euler[l]]);
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.erase((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.erase(arr[euler[l]] - (*lot));
						}
						gone[euler[l]]=false;
					}
					else{
						auto lot=values.lower_bound(arr[euler[l]]);
						if(lot!=values.end()) {
							diff.insert((*lot) - arr[euler[l]]);
						}
						if(lot!=values.begin()) {
							lot--;
							diff.insert(arr[euler[l]] - (*lot));
						}
						values.insert(arr[euler[l]]);
						gone[euler[l]]=true;
					}
				}
			}
			le=i;
		}
	}
	sort(queries+le,queries+q,comparator2());
	int l=queries[le].l;
	int r=queries[le].r;
	bool gone[n+1];
	memset(gone,false,sizeof(gone));
	multiset<int> values;
	multiset<int> diff;
	for (int j = l; j <=r ; j++) {
		if(gone[euler[j]]){
			values.erase(arr[euler[j]]);
			auto lot=values.lower_bound(arr[euler[j]]);
			if(lot!=values.end()) {
				diff.erase((*lot) - arr[euler[j]]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.erase(arr[euler[j]] - (*lot));
			}
			gone[euler[j]]=false;
		}
		else{
			auto lot=values.lower_bound(arr[euler[j]]);
			if(lot!=values.end()) {
				diff.insert((*lot) - arr[euler[j]]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.insert(arr[euler[j]] - (*lot));
			}
			values.insert(arr[euler[j]]);
			gone[euler[j]]=true;
		}
	}
	int tej=getlca(euler[l],euler[r]);
	if(tej!=euler[l]){
		if(gone[euler[l]]){
			values.erase(arr[euler[l]]);
			auto lot=values.lower_bound(arr[euler[l]]);
			if(lot!=values.end()) {
				diff.erase((*lot) - arr[euler[l]]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.erase(arr[euler[l]] - (*lot));
			}
			gone[euler[l]]=false;
		}
		else{
			auto lot=values.lower_bound(arr[euler[l]]);
			if(lot!=values.end()) {
				diff.insert((*lot) - arr[euler[l]]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.insert(arr[euler[l]] - (*lot));
			}
			values.insert(arr[euler[l]]);
			gone[euler[l]]=true;
		}
	}
	if(gone[tej]){
		values.erase(arr[tej]);
		auto lot=values.lower_bound(arr[tej]);
		if(lot!=values.end()) {
			diff.erase((*lot) - arr[tej]);
		}
		if(lot!=values.begin()) {
			lot--;
			diff.erase(arr[tej] - (*lot));
		}
		gone[tej]=false;
	}
	else{
		auto lot=values.lower_bound(arr[tej]);
		if(lot!=values.end()) {
			diff.insert((*lot) - arr[tej]);
		}
		if(lot!=values.begin()) {
			lot--;
			diff.insert(arr[tej] - (*lot));
		}
		values.insert(arr[tej]);
		gone[tej]=true;
	}
	solution[queries[le].index]=*diff.begin();
	if(tej!=euler[l]){
		if(gone[euler[l]]){
			values.erase(arr[euler[l]]);
			auto lot=values.lower_bound(arr[euler[l]]);
			if(lot!=values.end()) {
				diff.erase((*lot) - arr[euler[l]]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.erase(arr[euler[l]] - (*lot));
			}
			gone[euler[l]]=false;
		}
		else{
			auto lot=values.lower_bound(arr[euler[l]]);
			if(lot!=values.end()) {
				diff.insert((*lot) - arr[euler[l]]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.insert(arr[euler[l]] - (*lot));
			}
			values.insert(arr[euler[l]]);
			gone[euler[l]]=true;
		}
	}
	if(gone[tej]){
		values.erase(arr[tej]);
		auto lot=values.lower_bound(arr[tej]);
		if(lot!=values.end()) {
			diff.erase((*lot) - arr[tej]);
		}
		if(lot!=values.begin()) {
			lot--;
			diff.erase(arr[tej] - (*lot));
		}
		gone[tej]=false;
	}
	else{
		auto lot=values.lower_bound(arr[tej]);
		if(lot!=values.end()) {
			diff.insert((*lot) - arr[tej]);
		}
		if(lot!=values.begin()) {
			lot--;
			diff.insert(arr[tej] - (*lot));
		}
		values.insert(arr[tej]);
		gone[tej]=true;
	}
	for(int j=le+1;j<q;j++){
		while(r<queries[j].r){
			r+=1;
			if(gone[euler[r]]){
				values.erase(arr[euler[r]]);
				auto lot=values.lower_bound(arr[euler[r]]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[euler[r]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[euler[r]] - (*lot));
				}
				gone[euler[r]]=false;
			}
			else{
				auto lot=values.lower_bound(arr[euler[r]]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[euler[r]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[euler[r]] - (*lot));
				}
				values.insert(arr[euler[r]]);
				gone[euler[j]]=true;
			}
		}
		while(l<queries[j].l){
			if(gone[euler[l]]){
				values.erase(arr[euler[l]]);
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[euler[l]] - (*lot));
				}
				gone[euler[l]]=false;
			}
			else{
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[euler[l]] - (*lot));
				}
				values.insert(arr[euler[l]]);
				gone[euler[l]]=true;
			}
			l+=1;
		}
		while(l>queries[j].l){
			l-=1;
			if(gone[euler[l]]){
				values.erase(arr[euler[l]]);
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[euler[l]] - (*lot));
				}
				gone[euler[l]]=false;
			}
			else{
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[euler[l]] - (*lot));
				}
				values.insert(arr[euler[l]]);
				gone[euler[l]]=true;
			}
		}
		tej=getlca(euler[l],euler[r]);
		if(tej!=euler[l]){
			if(gone[euler[l]]){
				values.erase(arr[euler[l]]);
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[euler[l]] - (*lot));
				}
				gone[euler[l]]=false;
			}
			else{
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[euler[l]] - (*lot));
				}
				values.insert(arr[euler[l]]);
				gone[euler[l]]=true;
			}
		}
		if(gone[tej]){
			values.erase(arr[tej]);
			auto lot=values.lower_bound(arr[tej]);
			if(lot!=values.end()) {
				diff.erase((*lot) - arr[tej]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.erase(arr[tej] - (*lot));
			}
			gone[tej]=false;
		}
		else{
			auto lot=values.lower_bound(arr[tej]);
			if(lot!=values.end()) {
				diff.insert((*lot) - arr[tej]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.insert(arr[tej] - (*lot));
			}
			values.insert(arr[tej]);
			gone[tej]=true;
		}
		solution[queries[j].index]=*diff.begin();
		if(gone[tej]){
			values.erase(arr[tej]);
			auto lot=values.lower_bound(arr[tej]);
			if(lot!=values.end()) {
				diff.erase((*lot) - arr[tej]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.erase(arr[tej] - (*lot));
			}
			gone[tej]=false;
		}
		else{
			auto lot=values.lower_bound(arr[tej]);
			if(lot!=values.end()) {
				diff.insert((*lot) - arr[tej]);
			}
			if(lot!=values.begin()) {
				lot--;
				diff.insert(arr[tej] - (*lot));
			}
			values.insert(arr[tej]);
			gone[tej]=true;
		}
		if(tej!=euler[l]){
			if(gone[euler[l]]){
				values.erase(arr[euler[l]]);
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.erase((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.erase(arr[euler[l]] - (*lot));
				}
				gone[euler[l]]=false;
			}
			else{
				auto lot=values.lower_bound(arr[euler[l]]);
				if(lot!=values.end()) {
					diff.insert((*lot) - arr[euler[l]]);
				}
				if(lot!=values.begin()) {
					lot--;
					diff.insert(arr[euler[l]] - (*lot));
				}
				values.insert(arr[euler[l]]);
				gone[euler[l]]=true;
			}
		}
	}
	for(int i=0;i<q;i++)printf("%d\n",solution[i]);
	return 0;
}