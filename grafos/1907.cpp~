#include <bits/stdc++.h>

#define MAX 1030

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
vector<ii> graph[MAX][MAX];
vector<ii> movements {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool visited[MAX][MAX];

void dfs(int x, int y) {
        visited[x][y] = true;
        for(auto& v : graph[x][y]){
                if(not visited[v.first][v.second]) {
                        dfs(v.first, v.second);
                }
        }
}

int main() {
        int n, m;

	cin >> n >> m;

	memset(grid, 'o', sizeof grid);
	memset(visited, false, sizeof visited);

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> grid[i][j];
		}
	}

	for(int x = 1; x <= n; ++x) {
		for(int y = 1; y <= m; ++y) {
			if(grid[x][y] == '.') {
		        	for(auto& move : movements) {
		                	int dx = move.first, dy = move.second;
		                        if(grid[x + dx][y + dy] == '.') {
						graph[x][y].push_back(make_pair(x+dx, y+dy));
		                        }
		                }
		         }
		 }
	}
		
	int count = 0;
	for(int x = 1; x <= n; ++x) {
		for(int y = 1; y <= m; ++y) {
			if(not visited[x][y] and grid[x][y] == '.'){
				dfs(x, y);
				count ++;
			}
		}
	}

	cout << count << endl;
		
        return 0;
}
