#include <bits/stdc++.h>

#define MAX 1024

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
vector<ii> movements {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
        int n, m;
        cin >> n >> m;
        memset(grid, '#', sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                        cin >> grid[i][j];
                }
        }
        for(int x = 1; x <= n; ++x) {
                for(int y = 1; y <= m; ++y) {
                        if(grid[x][y] == '.') {
                                cout << "(" << x << ", " << y << "):";
                                for(auto& move : movements) {
                                        int dx = move.first, dy = move.second;
                                        if(grid[x + dx][y + dy] == '.') {
                                                cout << " (" << x + dx << ", " << y + dy << ")";
                                        }
                                }
                                cout << endl;
                        }
                }
        }
        return 0;
}
