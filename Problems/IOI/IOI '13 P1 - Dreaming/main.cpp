#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

struct pa {
	int dest;
	lli dist;

	pa(int a = -1, lli b = 0) : dest(a), dist(b) {}
};

const int MAXN = 100001;
vector<pa> matrix[MAXN];
bool gone[MAXN];
int tree = 0;
pa deepestsubtree[MAXN];
pa secdeepestsubtree[MAXN];
lli goupdepth[MAXN];
lli radi[MAXN];
lli dias[MAXN];

void finddepth(int dest, int parent) {
	gone[dest] = true;
	for (pa x:matrix[dest]) {
		if (x.dest != parent) {
			finddepth(x.dest, dest);
			if (x.dist + deepestsubtree[x.dest].dist > deepestsubtree[dest].dist) {
				secdeepestsubtree[dest] = deepestsubtree[dest];
				deepestsubtree[dest] = pa(x.dest, x.dist + deepestsubtree[x.dest].dist);
			} else if (x.dist + deepestsubtree[x.dest].dist > secdeepestsubtree[dest].dist) {
				secdeepestsubtree[dest] = pa(x.dest, x.dist + deepestsubtree[x.dest].dist);
			}
		}
	}
}

void findradius(int dest, int parent, int dist) {
	if (parent != -1) {
		goupdepth[dest] = max(goupdepth[parent],
		                      max((deepestsubtree[parent].dest == dest ? 0 : deepestsubtree[parent].dist),
		                          (secdeepestsubtree[parent].dest == dest ? 0 : secdeepestsubtree[parent].dist))) +
		                  dist;
	}
	dias[tree] = max(dias[tree], max(goupdepth[dest], deepestsubtree[dest].dist));
	radi[tree] = min(radi[tree], max((lli) 0, max(goupdepth[dest], deepestsubtree[dest].dist)));
	for (pa x:matrix[dest]) {
		if (x.dest != parent)findradius(x.dest, dest, x.dist);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,q;
	cin>>n>>m>>q;
	lli a,b,c;
	for (int i = 0; i < m; i++) {
		cin>>a>>b>>c;
		matrix[a].push_back(pa(b, c));
		matrix[b].push_back(pa(a, c));
	}
	for (int i = 1; i <= n; i++)radi[i] = LLONG_MAX;
	vector<lli> radius;
	for (int i = 1; i <= n; i++) {
		if (!gone[i]) {
			tree += 1;
			finddepth(i, -1);
			findradius(i, -1, 0);
			radius.push_back(radi[tree]);
		}
	}
	if(q==1){
		lli ans=0;
		for(int i=1;i<=tree;i++){
			ans+=dias[i];
		}
		ans+=tree-1;
		printf("%lli\n",ans);
	}
	else{
		sort(radius.begin(), radius.end());
		lli ans = radius.back();
		if (radius.size() >= 2) {
			ans = max(ans, 1 + radius[radius.size() - 2]);
		}
		printf("%lli\n", ans);
	}
	return 0;
}