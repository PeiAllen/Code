#include<bits/stdc++.h>
//helping 4fecta
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;
struct Line { //Convex hull trick. since we only need to know max of each i, we rep each cut as a line and only track max

	long a, b; //partial sum, cost of previ splits
	int i; //loc of split

	Line(int idx=0, long x=0, long y=0) {
		i = idx;
		a = x;
		b = y;
	}

	long sum(long pos) {
		return a * (pos - a) + b;
	}

	long to(Line right) {
		if (a == right.a) {
			//if (b == right.b) {
			return a;
			//}
			//return Integer.MAX_VALUE;
		}
		return ((a * a - right.a * right.a + right.b - b) / (a - right.a));
	}
};
const int MAXN=100001;
int a[MAXN];
long psa[MAXN]; //helper array of partial sums
Line q[MAXN]; //this is an array rep of queue, STL is slow af
long previ[MAXN]; //previious optimal points anding at index i
int ans[201][MAXN]; //memeo each cut
long memo [MAXN];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;


        for (int i = 0; i < n; i++) {
          cin>>a[i];
        }
        for (int i = 0; i < n; i++) {
            psa[i + 1] = a[i] + psa[i];
        }

        for (int i = 0; i < k; i++) {
            long sum[n + 1]={}; //current optimal points starting at i
            int r, l;
            r = l = 0;
            for (int j = 0; j <= n; j++) { //cut each
                while (r + 1 < l && q[r].sum(psa[j]) <= q[r + 1].sum(psa[j])) {
                    r++; //candidate, push back
                }
                if (r < l) { //queue empty, val is optimal
                    sum[j] = q[r].sum(psa[j]);
                    ans[i][j] = q[r].i;
                }
                Line line = Line(j, psa[j], previ[j]);
                while (r + 1 < l) {
                    long t1;
                    long t2;
                    t1 = memo[l - 2];
                    t2 = q[l - 1].to(line);
                    memo[l - 1] = t2;
                    if (t1 < t2) { //never useful
                        break;
                    } else { //push front
                        l--;
                    }
                }
                if (r + 1 >= l && l > 0) {
                    memo[l - 1] = q[l - 1].to(line);
                }
                q[l++] = line;
            }
            for(int i=0;i<=n;i++){
            	previ[i]=sum[i];
            }
        }
       cout<<previ[n]<<"\n";
        string out = "";
        for (int ik = k - 1, ii = n; ik >= 0; ik--) {
            ii = ans[ik][ii];
            out = to_string(ii) + " " + out;
        }
        cout<<out;
	return 0;
}