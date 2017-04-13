#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

map<string, int> ids;
vector<int> graph[4096], dist(4096);

int bfs(int source, int destination) {
        queue<int> q;
        fill(dist.begin(), dist.end(), oo);
        dist[source] = 0;
        q.push(source);
        while(not q.empty()) {
                int u = q.front(); q.pop();
                for(auto& v : graph[u]) {
                        if(dist[v] == oo) {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                        }
                }
        }
        return dist[destination];
}

int main() {
        int n, m;
        cin >> n >> m;
        int k = 1;
        for(int i = 1; i <= m; ++i) {
                string a, b;
                cin >> a >> b;
                if(ids[a] == 0) {
                        ids[a] = k++;
                }
                if(ids[b] == 0) {
                        ids[b] = k++;
                }
                graph[ids[a]].push_back(ids[b]);
                graph[ids[b]].push_back(ids[a]);
        }
        cout << bfs(ids["Entrada"], ids["*"]) + bfs(ids["*"], ids["Saida"]) << endl;
        return 0;
}
