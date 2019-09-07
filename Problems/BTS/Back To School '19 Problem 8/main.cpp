#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
	setbuf(stdout,NULL);
	for(int i=0;i<10;i++) {
		int n;
		cin >> n;
		assert(n!=-400);
		int lo = 0;
		int hi = 1e7;
		int in, in2;
		int days = 0;
		while (lo != hi) {
			assert(days<=40000);
			int mid = (lo + hi) / 2;
			printf("? %d %d %d %d %d\n", 1, 0, 0, 0, mid);
			days += 1;
			cin >> in;
			if (in == -400)return 0;
			if (in == 1)lo = mid + 1;
			else if (in == -1)hi = mid - 1;
			else {
				lo = mid;
				hi = mid;
			}
		}
//		printf("C %d %d\n", days, days);
//		cin >> in;
//		if (in == -400)assert(0);
//		cin >> in2;
		printf("!\n");
		printf("%d %d\n", lo, in);
	}
	return 0;
}