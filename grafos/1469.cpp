#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

vector<int> graph[MAX];
vector<int> idades;
bool visited[MAX];
int menor;

int dfs(int u, int x) {
        visited[u] = true;
	if(u != x){
		if(idades[u-1] < menor){
			menor = idades[u-1];
		}
	}
        for(auto& v : graph[u]) {
                if(not visited[v]) {
                        dfs(v, x);
                }
        }
	return menor;
}

int main(){
	int n, m , l;
	while (scanf("%d %d %d", &n, &m, &l)!=EOF){
		for(int i=0; i<n; i++){
			int aux;
			scanf("%d", &aux);
			idades.push_back(aux);

		}	
		for(int j=0; j<m; j++){
			int x, y;
			scanf("%d %d", &x, &y);
			graph[y].push_back(x);		
		
		}
		for(int x=0; x<l; x++){
			char command;
			int r, z, t;
			cin >> command;	
			if(command == 'P'){
				cin >> t;
				memset(visited, false, sizeof visited);
				menor = 1e9;
				int aux = dfs(t, t);
				if(aux == 1e9){
					cout << "*" << endl;
				}else{
					cout << aux << endl;
				}

			}
			if(command == 'T'){
				vector<int> adjacenciasR, adjacenciasZ;
				cin >> r >> z;
				for(int i=1; i<=n; i++){
					for(int j=0; j< graph[i].size(); j++){
						if(graph[i][j] == r){
							graph[i][j] = z;
						}
						else if(graph[i][j] == z){
							graph[i][j] = r;
						}
					}
				}
			

				for(int i=0; i< graph[r].size(); i++){
					adjacenciasR.push_back(graph[r][i]);
				}	
				for(int j=0; j< graph[z].size(); j++){
					adjacenciasZ.push_back(graph[z][j]);
				}		
				graph[r].clear();
				graph[z].clear();
				for(int i=0; i<adjacenciasZ.size() ; i++){
					graph[r].push_back(adjacenciasZ[i]);
				}
				for(int j=0; j<adjacenciasR.size() ; j++){
					graph[z].push_back(adjacenciasR[j]);
				}
				adjacenciasZ.clear();
				adjacenciasR.clear();
			}
		}

		idades.clear();
		for(int i=0; i<=n; i++){
			graph[i].clear();
		}	
	}
	return 0;
}
