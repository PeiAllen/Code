#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int cas = 1; cas <= 5; cas++) {
		int r, c, n;
		cin >> r >> c >> n;
		int rowdel = 0;
		int coldel = 0;
		bool row[r + 1];
		bool col[c + 1];
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));
		int ans = r * c;
		int a,b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			if(!row[a]){
				row[a]=true;
				ans-=(c-coldel);
				rowdel+=1;
			}
			if(!col[b]){
				col[b]=true;
				ans-=(r-rowdel);
				coldel+=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}