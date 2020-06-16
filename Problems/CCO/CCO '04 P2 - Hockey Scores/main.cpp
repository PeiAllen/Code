#include <bits/stdc++.h>
using namespace std;

main() {
	int i, j, x, y, n, N;
    freopen("out.txt","w",stdout);
	for( scanf( " %d", &N ); N--; ) {
		scanf( " %d", &n );
		vector<pair<int, int> > hs;
		for( i = 0; i < n; i++ ) {
			scanf( " %d-%d", &x, &y );
			hs.push_back(make_pair(min(x,y), max(x,y)));
		}
		sort(hs.begin(), hs.end());
		vector<vector<int> > seqs;
		for( i = 0; i < hs.size(); i++ ) {
			for( j = 0; j < seqs.size(); j++ )
				if( hs[seqs[j].back()].second <= hs[i].second ) break;
			if( j == seqs.size() ) seqs.push_back(vector<int>());
			seqs[j].push_back(i);
		}
		printf( "%d\n", seqs.size() );
		for( i = 0; i < seqs.size(); i++ )
			for( j = 0; j < seqs[i].size(); j++ )
				printf( "%d-%d%c", hs[seqs[i][j]].first, hs[seqs[i][j]].second,
						(j == seqs[i].size()-1) ? '\n' : ' ' );
	}
}