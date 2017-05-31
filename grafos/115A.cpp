#include <bits/stdc++.h>
#define MAX 2010

using namespace std;

const int oo = 1e9;

vector<int> graph[MAX], dist(MAX);

void bfs(int source) {
        queue<int> q;
        fill(dist.begin(), dist.end(), oo);
        dist[source] = 1;
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
	int n;
	cin >> n;
	vector<int> roots;
	for(int i=1; i<=n; i++){
		int aux;
		cin >> aux;
		if(aux != -1){
			graph[aux].push_back(i);
		}else{
			roots.push_back(i);
		}
	}
	int maior, soma=0, todos = 0;
 	for(int u = 0; u < roots.size(); ++u) {
		bfs(roots[u]);
		maior = 1e-9;
		for(int j=1; j<=n; j++){
			if(dist[j]!= oo and dist[j] > maior ){
				maior = dist[j];
			}
		}
		todos = max(todos, maior);
        }
	cout << todos << endl;
	return 0;
}
