#include <bits/stdc++.h>

using namespace std;

int main(){
	double ptox[1010], ptoy[1010], dist[1010];
	double x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lf %lf %lf", &ptox[i], &ptoy[i], &dist[i]);
	}
	double distance = sqrt (pow(x1-x2, 2) + pow(y1-y2, 2));
	printf("Relatorio Vogon #35987-2\n");
	printf("Distancia entre referencias: %.2lf anos-luz\n", distance);

	int casualidade=0, oeste=0, leste=0;
	double somao=0, somal=0;
	for(int j=0; j<n; j++){
		double det = (x1 * y2 + y1 * ptox[j] + x2 * ptoy[j]) - (ptox[j] * y2 + ptoy[j] * x1 + x2 * y1);
		//cout << det << endl;
		if(det == 0){
			casualidade++;
		}
		else if(det > 0){
			oeste++;
			somao += dist[j];
		}
		else{
			leste++;
			somal += dist[j];
		}
		
	}
	printf("Setor Oeste:\n");
	printf("- %d planeta(s)\n", oeste);
	printf("- %.0lf bilhao(oes) de habitante(s)\n", somao);
	printf("Setor Leste:\n");
	printf("- %d planeta(s)\n", leste);
	printf("- %.0lf bilhao(oes) de habitante(s)\n", somal);
	printf("Casualidades: %d planeta(s)\n", casualidade);
	return 0;
}
