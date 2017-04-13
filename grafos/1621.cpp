#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX = 512, oo = 0x3f3f3f3f;

char grid[MAX][MAX];
int    dist[MAX][MAX];
vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

ii bfs(int x0, int y0) {
	queue<ii> q;
	memset(dist, oo, sizeof dist);
	dist[x0][y0] = 0;
	q.push(ii(x0, y0));
	ii furthest;
	while(not q.empty()) {
		auto current = q.front(); q.pop();
		auto x = current.first, y = current.second;
		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(grid[x + dx][y + dy] == '.' and dist[x + dx][y + dy] == oo) {
				dist[x + dx][y + dy] = dist[x][y] + 1;
				q.push(ii(x + dx, y + dy));
			}
		}
		furthest = current;
	}
	return furthest;
}

int main() {
	int n, m;
	while(cin >> n >> m, n | m) {
		int x, y;
 		memset(grid, '#', sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> grid[i][j];
				if(grid[i][j] == '.') {
					x = i, y = j;
				}
			}
		}
		auto p = bfs(x, y);
		auto q = bfs(p.first, p.second);
		cout << dist[q.first][q.second] << endl;
	}
	return 0;
}
