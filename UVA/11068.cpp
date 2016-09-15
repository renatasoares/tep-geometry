#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

bool equals(double x, double y) {
	return fabs(x - y) < EPS;
}

int main(){
	while(1){
		double a1, b1, c1, a2, b2, c2;
		scanf("%lf %lf %lf", &a1, &b1, &c1);
		scanf("%lf %lf %lf", &a2, &b2, &c2);
		if(a1 == 0 && b1 == 0 && c1 == 0 && a2 == 0 && b2 == 0 && c2 == 0) return 0;
		
		double det = a1*b2 - b1*a2;
		double detx = (c1*b2) - (b1*c2);
		double dety = (a1*c2) - (c1*a2);

		if(det != 0){
			double x = detx/det;
			double y = dety/det;
			if(equals(x, 0)){
				x = 0;
			}
			if(equals(y, 0)){
				y = 0;
			}
			printf("The fixed point is at %.2lf %.2lf.\n", x, y);
		}
		else{
			printf("No fixed point exists.\n");
		}

	}
	return 0;
}
