#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

vector<int> graph[MAX];

int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
        }
        for(int u = 1; u <= n; ++u) {
                cout << u << ":";
                for(auto& v : graph[u]) {
                        cout << " " << v;
                }
                cout << endl;
        }
        return 0;
}
