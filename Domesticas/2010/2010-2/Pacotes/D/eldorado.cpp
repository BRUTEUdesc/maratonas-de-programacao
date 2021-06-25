// Autor: Adrian Kuegel
// Date: 7. 7. 2008
// Complexity: O(n^3)
// Algorithm: Dynamic Programming

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <set>
using namespace std;

#define MAXN 128

int a[MAXN];
long long dp[MAXN][MAXN];

int main() {
	//freopen("eldorado.in", "r", stdin);
	int n, k;
	while(scanf("%d %d", &n, &k) == 2 && (n > 0 || k > 0)) {
		assert(0 < n && n <= 100);
		assert(0 < k && k <= n);
		long long ans = 0;
		set<int> have;
		for (int i=0; i<n; ++i) {
			assert(scanf("%d", &a[i]) == 1);
			assert(-10000 <= a[i] && a[i] <= 10000);
			assert(have.find(a[i]) == have.end());
			have.insert(a[i]);
			dp[i][0] = 1;
			for (int j=1; j<k; ++j) {
				dp[i][j] = 0;
				for (int ii=0; ii<i; ++ii) {
					if (a[ii] >= a[i])
						continue;
					assert(LLONG_MAX-dp[i][j] >= dp[ii][j-1]);
					dp[i][j] += dp[ii][j-1];
				}
			}
			assert(LLONG_MAX-ans >= dp[i][k-1]);
			ans += dp[i][k-1];
		}
		printf("%lld\n", ans);
	}
	assert(n == 0 && k == 0);
	return 0;
}
