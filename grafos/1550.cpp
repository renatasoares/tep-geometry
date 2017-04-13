#include <bits/stdc++.h>

#define MAX 10005
#define oo 0x3f3f3f3f

using namespace std;

int dist[MAX];

int revert(int n){
        int ret=0;
        int i=1;
   
        while(i<=n){
                ret*=10;
                ret+=(n%(i*10)-n%i)/i;
                i*=10;
        }
        return ret;
}

void bfs(int source, int chegada) {
        queue<int> q;
        memset(dist, oo, sizeof dist);
        dist[source] = 0;
        q.push(source);
        while(not q.empty()) {
                int u = q.front();
		int v = u+1;
		int z = revert(u);
                if(v <= 10000 && dist[v] == oo) {
                	dist[v] = dist[u] + 1;
                        q.push(v);
                }
		if(z <= 10000 && dist[z] == oo){
                	dist[z] = dist[u] + 1;
                        q.push(z);
                }
                if(v == chegada || z == chegada) break;
                q.pop();
        }
}

int main(){
        int teste;
        cin >> teste;
        for(int i=0; i<teste; i++){
                int origem, chegada;
                cin >> origem;
                cin >> chegada;
                bfs(origem, chegada);
                cout << dist[chegada] << endl;
        }
	return 0;
}
