#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

vector<int> graph[MAX];
vector<char> resp[MAX];
bool visited[MAX];

vector<char> letras = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<char>::iterator it;

void dfs(int u, int count) {
        visited[u] = true;
        for(auto& v : graph[u]) {
                if(not visited[v]) {
                        dfs(v, count);
                }
        }
        resp[count].push_back(letras[u]);
}

int main(){
        int n, m, teste;
	cin >> teste;
	for(int i=1; i<=teste; i++){
		cin >> n >> m; 
		memset(visited, false, sizeof visited);
		for(int i = 1; i <= m; ++i) {
		        char u, v;
		        cin >> u >> v;

			it=find(letras.begin(),letras.end(),u);
			int a = distance(letras.begin(), it);

			it=find(letras.begin(),letras.end(),v);
			int b = distance(letras.begin(), it);


		        graph[a].push_back(b);
		        graph[b].push_back(a);
		}
		int count = 0;
		cout << "Case #" << i << ":" << endl;
		for(int u = 1; u <= n; ++u){
		        if(not visited[u]){
		                dfs(u, count);
				count++;
		        }
		}

		for(int u=0; u<count; u++){
			sort(resp[u].begin(), resp[u].end());
		}

		for(int x= 0; x < count; x++){
		        for(auto& v : resp[x]){
				cout << v << ",";
			}
			cout << endl;
		}

		cout << count <<" connected components" << endl;
		cout<< endl;
		for(int j = 1; j <= n; ++j){
			graph[j].clear();
		}
		for(int j = 0; j <= count; ++j){
			resp[j].clear();
		}
	}
        return 0;
}
