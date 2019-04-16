#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10000
#define MAXTIME 600
#define INF MAXTIME + 1

struct edge {
	int dest, len;
	edge(int d, int l) {
		dest = d;
		len = l;
	}
};

bool operator<(const edge &a, const edge &b) {
	return a.len > b.len;
}

typedef vector<edge> VE;
VE adj[MAXN];

bool has_hotel[MAXN];
int len[MAXN];

int main() {
	int n;
	freopen("hotel.in", "r", stdin);
	while(scanf("%d", &n) == 1 && n) {
		assert(n >= 2 && n <= MAXN);
		for (int i=0; i<n; ++i) {
			has_hotel[i] = false;
			adj[i].clear();
		}
		int h, id;
		scanf("%d", &h);
		assert(h >= 0 && h <= n && h <= 100);
		for (int i=0; i<h; ++i) {
			scanf("%d", &id);
			--id;
			assert(id >= 0 && id < n && !has_hotel[id]);
			has_hotel[id] = true;
		}
		int m;
		scanf("%d", &m);
		assert(m > 0 && m <= 100000);
		while(m--) {
			int a, b, t;
			scanf("%d %d %d", &a, &b, &t);
			assert(a >= 1 && a <= n && b >= 1 && b <= n && t > 0 && t <= MAXTIME);
			--a;
			--b;
			adj[a].push_back(edge(b, t));
			adj[b].push_back(edge(a, t));
		}
		queue<int> Q;
		Q.push(0);
		int hotels = 0;
		while(!Q.empty()) {
			int oldsize = Q.size();
			while(oldsize--) {
				int cur = Q.front();
				Q.pop();
				for (int i=0; i<n; ++i)
					len[i] = INF;
				priority_queue<edge> PQ;
				PQ.push(edge(cur, 0));
				len[cur] = 0;
				while(!PQ.empty()) {
					int c = PQ.top().dest;
					int clen = PQ.top().len;
					PQ.pop();
					if (c == n-1)
						goto found;
					if (has_hotel[c]) {
						has_hotel[c] = false;
						Q.push(c);
					}
					for (VE::iterator it=adj[c].begin(); it!=adj[c].end(); ++it) {
						int l = it->len + clen;
						if (l < len[it->dest]) {
							len[it->dest] = l;
							PQ.push(edge(it->dest, l));
						}
					}
				}
			}
			++hotels;
		}
		puts("-1");
		continue;
found:
		printf("%d\n", hotels);
	}
	return 0;
}
