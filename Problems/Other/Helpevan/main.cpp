#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int arr[MAXN], pos[MAXN];
double dp[MAXN];
vector<int> cheese[MAXN];
deque<int> buf[MAXN];
int k, n;

double g(int i)
{
	return i ? dp[i-1] : 0;
}

double f(int i, int j)
{
	long long cnti = pos[i];
	long long cntj = pos[j];
	return (g(i) - g(j) - cntj*cntj + cnti*cnti - 2 * cnti + 2 * cntj) / (2.0 * (cnti - cntj));
}

int main()
{
	scanf("%i%i", &k, &n);
	if (k == 2)
		return 0 * printf("%i\n", n);
	for (int x = 1; x <= n; x++)
	{
		scanf("%i", &arr[x]);
		pos[x] = cheese[arr[x]].size();
		cheese[arr[x]].push_back(x);
	}
	if (k == 3)
	{
		for (int x = 1; x <= n; x++)
		{
			for (int y = 0; y <= pos[x]; y++)
				dp[x] = max(dp[x], pow(pos[x] - y + 1, k/2.0) + dp[cheese[arr[x]][y]-1]);
		}
	}
	else
	{
		for (int x = 1; x <= n; x++)
		{
			int a = arr[x];
			while (buf[a].size() >= 2 && f(buf[a][buf[a].size()-2], buf[a][buf[a].size()-1]) <= f(buf[a].back(), x))
				buf[a].pop_back();
			buf[a].push_back(x);
			while (buf[a].size() >= 2 && f(buf[a][buf[a].size()-2], buf[a][buf[a].size()-1]) <= pos[x])
				buf[a].pop_back();
			int k = buf[a].back();
			long long cntk = pos[k] - 1;
			dp[x] = g(k) + (pos[x] - cntk) * (pos[x] - cntk);
			cout<<x<<" "<<k<<" "<<dp[x]<<endl;
		}
	}
	printf("%.10lf\n", dp[n]);
}
