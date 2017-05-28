#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

vector<int> graph[10010], dist(10010);

void bfs(int source, int n) {
        queue<int> q;
        dist[source] = 0;
        q.push(source);
        while(not q.empty()) {
                int u = q.front(); q.pop();
		if(u == n) break;
                for(auto& v : graph[u]) {
                        if(dist[v] == oo) {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                        }
                }
        }
}

int main() {
        int n, m;
	scanf("%d %d\n", &n, &m);
	string line;
	int i=0;
        fill(dist.begin(), dist.end(), oo);
	while(getline(cin, line)){
		vector<int> bus;
		istringstream is (line);	
		string num;
		is>> num;
		while(is >> num){
			std::string::size_type sz;   
			int dec = stoi(num,&sz);
			bus.push_back(dec);
		}
		for(int i=0; i<bus.size(); i++){
			int x = bus[i];
			for(int j=0; j<bus.size(); j++){
				int y = bus[j];
				if(y!=x){
					graph[x].push_back(y);
					graph[y].push_back(x);
				}
			}
		}
		bus.clear();
	}
	bfs(1, n);
	cout << dist[n] << endl;
        return 0;
}
