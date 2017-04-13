#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

const int oo = 1e9;
vector<int> graph[MAX], dist(MAX);

void bfs(int source, int dest){
	queue<int> q;
	fill(dist.begin(), dist.end(), oo);
	dist[source] = 0;
	q.push(source);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		int v1 = u-1;
		int v2 = u*2;
		if(dist[v1] == oo and v1 <= 1e4){
			dist[v1] = dist[u]+1;
			q.push(v1);
			if(v1 == dest) break;
		}
		if(dist[v2] == oo and v2 <= 1e4){
			dist[v2] = dist[u]+1;
			q.push(v2);
			if(v2 == dest) break;
		}
		
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	bfs(n,m);
	cout << dist[m] << endl;
	return 0;
}
