#include <bits/stdc++.h>

#define PI acos(-1.0)

using namespace std;

int main(){
	double a, b, c;
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		double sunflowers, violetes, roses;

		double perimetro = a + b + c;
        	double s = perimetro/2.0;
        	double areaTri = sqrt(s*(s - a)*(s - b)*(s - c));

		double raioRose = 2*areaTri/perimetro;
		double raioSun = (a * b * c)/ (4*areaTri);

		double areaRose = PI*raioRose*raioRose;
		double areaSun = PI*raioSun*raioSun;
	
		printf("%.4lf %.4lf %.4lf\n", areaSun - areaTri, areaTri - areaRose, areaRose);
	
	}
	return 0;
}

