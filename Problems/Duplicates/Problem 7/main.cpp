#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN = 100000;
vector<int> matrix[MAXN];
int depth[MAXN];
vector<vector<int>> sqrttree;
int blocksize = 800;
int partof[MAXN];
int n, q;
vector<int> blockeulerbegin;
vector<int> blockeulerend;
int eulerbegin[MAXN];
int eulerend[MAXN];
int eulerloc = 0;
vector<int> vertex[MAXN];

struct node {
	lli data, sumofd, nodes;
	lli lazyc, lazyd;
	int le, ri,mind,maxd,eulerst,euleren;
	node(lli a = 0, lli b = 0, lli c = 0, lli d = -1, lli e = 0, int f=INT_MAX, int g=0, int h=0, int i=0) : data(a), nodes(b), sumofd(c), lazyc(d), lazyd(e), le(0), ri(0),mind(f),maxd(g),eulerst(h),euleren(i) {}
};

vector<vector<node>> sumtree;

void maketree(int l, int r, int par, int ind, int loc) {
	sumtree[ind][loc].le = l;
	sumtree[ind][loc].ri = r;
	int left = loc + 1;
	int right = loc + (((sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2 - sumtree[ind][loc].le + 1) << 1);
	if (sumtree[ind][loc].le != sumtree[ind][loc].ri) {
		int mid = (sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2;
		maketree(l, mid, par, ind, left);
		maketree(mid + 1, r, par, ind, right);
		sumtree[ind][loc].sumofd = sumtree[ind][left].sumofd + sumtree[ind][right].sumofd;
		sumtree[ind][loc].nodes = sumtree[ind][left].nodes + sumtree[ind][right].nodes;
		sumtree[ind][loc].mind = sumtree[ind][left].mind;
		sumtree[ind][loc].maxd = sumtree[ind][right].maxd;
	} else {
		sumtree[ind][loc].sumofd = (lli) depth[sqrttree[ind][sumtree[ind][loc].le]];
		sumtree[ind][loc].nodes = (lli) 1;
		sumtree[ind][loc].mind=depth[sqrttree[ind][sumtree[ind][loc].le]];
		sumtree[ind][loc].maxd=sumtree[ind][loc].mind;
		sumtree[ind][loc].eulerst=eulerbegin[sqrttree[ind][sumtree[ind][loc].le]];
		sumtree[ind][loc].euleren=eulerend[sqrttree[ind][sumtree[ind][loc].le]];
	}
}

void resolvelazy(int ind, int loc) {
	int left = loc + 1;
	int right = loc + (((sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2 - sumtree[ind][loc].le + 1) << 1);
	sumtree[ind][loc].data += sumtree[ind][loc].lazyc * sumtree[ind][loc].sumofd - sumtree[ind][loc].lazyd * sumtree[ind][loc].nodes;
	if (right < sumtree[ind].size()&&sumtree[ind][loc].le!=sumtree[ind][loc].ri) {
		if (sumtree[ind][left].nodes) {//(c+c2)*sumd-nodes(c*d(i)+c2*d(j))
			if (sumtree[ind][left].lazyc == -1)sumtree[ind][left].lazyc = 0;
			sumtree[ind][left].lazyc += sumtree[ind][loc].lazyc;
			sumtree[ind][left].lazyd += sumtree[ind][loc].lazyd;
		}
		if (sumtree[ind][right].nodes) {
			if (sumtree[ind][right].lazyc == -1)sumtree[ind][right].lazyc = 0;
			sumtree[ind][right].lazyc += sumtree[ind][loc].lazyc;
			sumtree[ind][right].lazyd += sumtree[ind][loc].lazyd;
		}
	}
	sumtree[ind][loc].lazyc = -1;
	sumtree[ind][loc].lazyd = 0;
}

void rangein(lli c, lli d, int l, int r, int ind, int loc) {
	int left = loc + 1;
	int right = loc + (((sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2 - sumtree[ind][loc].le + 1) << 1);
	if (sumtree[ind][loc].lazyc != -1)resolvelazy(ind, loc);
	if (l > r || l > sumtree[ind][loc].maxd || r < sumtree[ind][loc].mind)return;
	if (l <= sumtree[ind][loc].mind && r >= sumtree[ind][loc].maxd) {
		sumtree[ind][loc].lazyc = c;
		sumtree[ind][loc].lazyd = d * c;
		resolvelazy(ind, loc);
		return;
	}
	rangein(c, d, l, r, ind, left);
	rangein(c, d, l, r, ind, right);
	sumtree[ind][loc].data = sumtree[ind][left].data + sumtree[ind][right].data;
}

lli sumq(int l, int r, int ind, int loc) {
	int left = loc + 1;
	int right = loc + (((sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2 - sumtree[ind][loc].le + 1) << 1);
	if (sumtree[ind][loc].lazyc != -1)resolvelazy(ind, loc);
	if (l > r || l > sumtree[ind][loc].maxd || r < sumtree[ind][loc].mind) return 0;
	if (l <= sumtree[ind][loc].mind && r >= sumtree[ind][loc].maxd) {
		return sumtree[ind][loc].data;
	}
	return sumq(l, r, ind, left) + sumq(l, r, ind, right);
}

void onein(lli c, lli d, int u, int a, int b, int ind, int loc) {
	int left = loc + 1;
	int right = loc + (((sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2 - sumtree[ind][loc].le + 1) << 1);
	if (sumtree[ind][loc].lazyc != -1)resolvelazy(ind, loc);
	if (a > sumtree[ind][loc].maxd || sumtree[ind][loc].mind > b)return;
	if (sumtree[ind][loc].le != sumtree[ind][loc].ri) {
		onein(c, d, u, a, b, ind, left);
		onein(c, d, u, a, b, ind, right);
		sumtree[ind][loc].data = sumtree[ind][left].data + sumtree[ind][right].data;
		return;
	}
	if (sumtree[ind][loc].eulerst >= eulerbegin[u] && sumtree[ind][loc].euleren <= eulerend[u]) {
		sumtree[ind][loc].data += c * ((lli) sumtree[ind][loc].mind - d);
	}
}

lli oneq(int u, int a, int b, int ind, int loc) {
	int left = loc + 1;
	int right = loc + (((sumtree[ind][loc].le + sumtree[ind][loc].ri) / 2 - sumtree[ind][loc].le + 1) << 1);
	if (sumtree[ind][loc].lazyc != -1)resolvelazy(ind, loc);
	if (a > sumtree[ind][loc].maxd || sumtree[ind][loc].mind > b) return 0;
	if (sumtree[ind][loc].le != sumtree[ind][loc].ri) {
		return oneq(u, a, b, ind, left) + oneq(u, a, b, ind, right);
	}
	if (sumtree[ind][loc].eulerst >= eulerbegin[u] && sumtree[ind][loc].euleren <= eulerend[u]) {
		return sumtree[ind][loc].data;
	}
	return 0;
}

struct compartor {
	bool operator()(const int &lhs, const int &rhs) const {
		return depth[lhs] < depth[rhs];
	}
};

void makesqrttree(int loc, int parent) {
	eulerbegin[loc] = eulerloc++;
	for (int x:matrix[loc]) {
		if (x != parent) {
			makesqrttree(x, loc);
			if (vertex[loc].size() < vertex[x].size())vertex[loc].swap(vertex[x]);
			vertex[loc].insert(vertex[loc].end(), vertex[x].begin(), vertex[x].end());
		}
		if (vertex[loc].size() > blocksize) {
			int mi = INT_MAX;
			int ma = INT_MIN;
			sort(vertex[loc].begin(), vertex[loc].end(), compartor());
			for (int i = 0; i < vertex[loc].size(); i++) {
				mi = min(mi, eulerbegin[vertex[loc][i]]);
				ma = max(ma, eulerend[vertex[loc][i]]);
				partof[vertex[loc][i]] = sqrttree.size();
			}
			blockeulerbegin.push_back(mi);
			blockeulerend.push_back(ma);
			sqrttree.push_back(vertex[loc]);
			vertex[loc].clear();
		}
	}
	eulerend[loc] = eulerloc++;
	vertex[loc].push_back(loc);
}

void update(int u, int a, int b, lli c) {
	for (int i = 0; i < sqrttree.size(); i++) {
		if (partof[u] != i && blockeulerbegin[i] >= eulerbegin[u] && blockeulerend[i] <= eulerend[u]) {
			rangein(c, depth[u], a, b, i, 0);
		}
	}
	onein(c, depth[u], u, a, b, partof[u], 0);
}

lli query(int u, int a, int b) {
	lli ans = 0;
	for (int i = 0; i < sqrttree.size(); i++) {
		if (partof[u] != i && blockeulerbegin[i] >= eulerbegin[u] && blockeulerend[i] <= eulerend[u]) {
			ans += sumq(a, b, i, 0);
		}
	}
	ans += oneq(u, a, b, partof[u], 0);
	return ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	int in;
	for (int i = 1; i < n; i++) {
		cin >> in;
		matrix[i].push_back(in);
		matrix[in].push_back(i);
		depth[i] = depth[in] + 1;
	}
	makesqrttree(0, -1);
	int mi = INT_MAX;
	int ma = INT_MIN;
	sort(vertex[0].begin(), vertex[0].end(), compartor());
	for (int i = 0; i < vertex[0].size(); i++) {
		mi = min(mi, eulerbegin[vertex[0][i]]);
		ma = max(ma, eulerend[vertex[0][i]]);
		partof[vertex[0][i]] = sqrttree.size();
	}
	blockeulerbegin.push_back(mi);
	blockeulerend.push_back(ma);
	sqrttree.push_back(vertex[0]);
	vertex[0].clear();
	sumtree.resize(sqrttree.size());
	for (int i = 0; i < sqrttree.size(); i++) {
		sumtree[i].resize(2 * sqrttree[i].size());
		maketree(0, sqrttree[i].size()-1, i, i, 0);
	}
	string qu;
	int u, a, b;
	lli c;
	for (int i = 0; i < q; i++) {
		cin >> qu;
		if (qu == "UPDATE") {
			cin >> u >> a >> b >> c;
			update(u, a, b, c);
		} else {
			cin >> u >> a >> b;
			printf("%lli\n", query(u, a, b));
		}
	}
}