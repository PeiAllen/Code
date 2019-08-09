#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
random_device rd;
struct node {
	int data, size;
	struct node *child[2];
	unsigned int priority;
	node() {
		size = 1;
		data = 0;
		child[0] = NULL;
		child[1] = NULL;
		priority = rd();
	}
};
struct SMTreap {
	int gtsz(int a) { return (child[a] ? child[a]->size : 0); }
	void recalc() { size = gtsz(0) + gtsz(1) + 1; }
	void split(int key, node *&left, node *&right) {//inclusive left
		if (gtsz(0) + 1 <= key) {
			if (child[1])child[1]->split(key, child[1], right), left = this;
			else right = NULL, left = this;
		} else {
			if (child[0])child[0]->split(key, left, child[0]), right = this;
			else left = NULL, right = this;
		}
		recalc();
	}
	void merge()
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	return 0;
}