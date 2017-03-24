#include <bits/stdc++.h>

#define MAX 5000

using namespace std;

vector<int> graph[MAX];
bool visited[MAX];

void dfs(int u) {
        visited[u] = true;
        for(auto& v : graph[u]) {
                if(not visited[v]) {
                        dfs(v);
                }
        }
}

int main() {
	int teste, n, m;
	cin >> teste;
	for(int i=1; i<=teste; ++i){
		memset(visited, false, sizeof visited);
		cin >> n >> m;
		for(int i = 1; i <= m; ++i) {
		        int u, v;
		        cin >> u >> v;
		        graph[u].push_back(v);
		        graph[v].push_back(u);
		}
		int count = 0;
		for(int u = 1; u <= n; ++u) {
		        if(not visited[u]) {
		                dfs(u);
				count ++;
		        }
		}

		if(count == 1 ){ 
			printf("Caso #%d: a promessa foi cumprida\n", i); 
		}
		else{ 
			printf("Caso #%d: ainda falta(m) %d estrada(s)\n", i , count-1); 
		}
		for(int i=0; i<=m; ++i){
			graph[i].clear();
		}
	}
        return 0;
}
