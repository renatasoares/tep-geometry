#include <bits/stdc++.h>
#define MAX 30010

const int oo = 1e9;

using namespace std;

vector<int> graph[MAX], dist(MAX);

void bfs(int source) {
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
}

int main(){
	int x, y;
	cin >> x >> y;
	for(int i=1; i<x; i++){
		int aux;
		cin >> aux;
		graph[i].push_back(aux+i);
	}
	bfs(1);
	if(dist[y] == oo){
		cout << "NO" <<endl;
	}
	else{
		cout << "YES" << endl;	
	}
	return 0;
}
