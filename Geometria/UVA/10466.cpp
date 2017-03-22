#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)

int main(){
	int n, T, r, t;
	while (scanf("%d %d", &n, &T)!=EOF){
		vector <pair<double, double>> coord;
		for(int i=0; i<n; i++){
			scanf("%d %d", &r, &t);
			double teta = (2*PI*T)/t;
			printf(" teta = %lf\n", teta);
			double x, y;
			x = r*cos(teta);
			y = r*sin(teta);
			printf("< %lf, %lf >\n", x, y);
			coord.push_back(make_pair(x,y));
		}
			double somax=0;
			double somay=0;
		for(int j=0; j<n; j++){
			if(j>0) printf(" ");

			somax += coord[j].first;
			somay += coord[j].secon
d;
			printf("%.4lf", (sqrt( somax*somax + somay*somay )) + 1e-10);	
		}
		printf("\n");
	}
	return 0;
}
