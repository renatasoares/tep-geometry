#include <bits/stdc++.h>

using namespace std;

int main(){
	int test;
	scanf("%d", &test);
	vector <pair<long long, long long>> pontos;
	vector <pair<long long, long long>> comp;
	for(int z=0; z<test; z++){
		long long n;
		long long meiox=0, meioy=0, mesmo=0;
		scanf("%lld", &n);		
		for(int i=0; i<n; i++){
			long long x, y;
			scanf("%lld %lld", &x, &y);
			pontos.push_back(make_pair(x,y));
		}
		if (n == 1){
			cout << "yes" << endl;
			continue;
		}
		sort(pontos.begin(), pontos.end());

		long long r=n-1;
		for(int j=0; j<n/2;j++){
			meiox = pontos[j].first + pontos[r].first;
			meioy = pontos[j].second + pontos[r].second;
			comp.push_back(make_pair(meiox,meioy));
			r--;
		}
		sort(comp.begin(), comp.end());
		long long tam = comp.size() - 1;

		if(comp[0].first == comp[tam].first && comp[0].second == comp[tam].second){
			mesmo++;
		}
		if(n%2 ==0){
			if(mesmo != 0){
				printf("yes\n");
			}
			else{
				printf("no\n");
			}
		}
		else{
			if(mesmo != 0 && comp[0].first == (pontos[n/2].first * 2) && comp[0].second == (pontos[n/2].second * 2)){
				printf("yes\n");
			}
			else{
				printf("no\n");
			}
		}
		pontos.clear();
		comp.clear();
	}
	return 0;
}
