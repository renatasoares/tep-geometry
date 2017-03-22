#include <bits/stdc++.h>

using namespace std;

int main(){
	int teste;
	scanf("%d", &teste);
	double x1, y1, x2, y2, x3, y3, x4, y4;
	for(int i=0; i<teste; i++){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		if(i == 0) printf ("INTERSECTING LINES OUTPUT\n");
		double a1 = y1-y2;
		double a2 = y3-y4;
		double b1 = x2-x1;
		double b2 = x4-x3;
		double c1 = x1*y2 - x2*y1;
		double c2 = x3*y4 - x4*y3;

		double det = a1*b2 - b1*a2;
		double detx = (c1*-1*b2) - (b1*-1*c2);
		double dety = (a1*-1*c2) - (c1*-1*a2);

		//printf ("a1 = %.2lf, b1 = %.2lf , c1 = %.2lf && a2 = %.2lf, b2 = %.2lf , c2 = %.2lf\n",a1, b1, c1, a2, b2, c2);

		if(a1==0){
			a1 = a1/b1;
			c1 = c1/b1;
			b1 = b1/b1;
		}
		else{
			b1 = b1/a1;
			c1 = c1/a1;
			a1 = a1/a1;
		}

		if(a2==0){
			a2 = a2/b2;
			c2 = c2/b2;
			b2 = b2/b2;
		}
		else{
			b2 = b2/a2;
			c2 = c2/a2;
			a2 = a2/a2;
		}

		//printf ("a1 = %.2lf, b1 = %.2lf , c1 = %.2lf && a2 = %.2lf, b2 = %.2lf , c2 = %.2lf\n",a1, b1, c1, a2, b2, c2);
		if(det == 0 && c1 != c2) printf("NONE\n");
		else if(det == 0 && c1 == c2) printf("LINE\n");
		else{
			double x = detx/det;
			double y = dety/det;
			printf("POINT %.2lf %.2lf\n", x, y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
