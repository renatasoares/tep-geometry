#include <bits/stdc++.h>

using namespace std;

double det(int x1, int y1, int x2, int y2, int x, int y) {
		double aux = (x1 * y2 + y1 * x + x2 * y) - (x * y2 + y * x1 + x2 * y1);
		return aux;
}

int main(){
	while(1){
		int x, y, n;
		vector <pair<int,int>> pto;
		vector <double> dif;
		int esquerda=0, direita=0;
		scanf("%d", &n);
		if(n == 0) return 0;
		for(int r=0; r<n; r++){
			scanf("%d %d", &x, &y);
			pto.push_back(make_pair(x,y));
		}
		for(int i=0; i<pto.size(); i++){
			for(int j=0; j < pto.size();j++){
				if(j == i) continue;
				double esquerda=0, direita=0;
				for(int z=0; z < pto.size(); z++){
					if(j == z || z == i) continue;
					double temp = det(pto[i].first, pto[i].second, pto[j].first, pto[j].second, pto[z].first, pto[z].second);

					double a = pto[i].second-pto[j].second;
					double b = pto[j].first-pto[i].first;
					double c = pto[i].first*pto[j].second - pto[j].first* pto[i].second;

					double distance = abs(a*pto[z].first+ b*pto[z].second + c) / sqrt(a*a + b* b);

					if(temp > 0){
						//printf("Ponto a esquerda(%.2lf): (%d[%d] %d[%d]) da reta %d, %d ------ %d, %d\n", distance, pto[z].first,z, pto[z].second,z, pto[i].first, pto[i].second, pto[j].first, pto[j].second);

						esquerda += distance;
					}
					else{
						//printf("Ponto a direita(%.2lf): (%d[%d] %d[%d]) da reta %d, %d ------ %d, %d\n", distance, pto[z].first,z, pto[z].second,z, pto[i].first, pto[i].second, pto[j].first, pto[j].second);
						
						direita += distance;
					}
					
				}
				//printf("%d esquerda e %d direita\n", count1, count2);
				//printf("distance = %.2lf\n", abs(esquerda-direita));
				dif.push_back(abs(esquerda-direita));
				//printf("\n\n");
		
			}
			
		}
		
		sort(dif.begin(), dif.end());
		printf("%.3lf\n", dif[0]);
		
		pto.clear();
		dif.clear();
		
	}
	return 0;
}
