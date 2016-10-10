#include <bits/stdc++.h>

using namespace std;

int main(){
	int teste;
	scanf("%d", &teste);
	for(int i=0; i<teste; i++){
		double r1, r2, r3;
		scanf("%lf %lf %lf", &r1, &r2, &r3);
		
		double a = r1+r2, b = r1+r3, c=r2+r3;
		double s = (a+b+c)/2.0;
		double areaTri = sqrt(s*(s - a)*(s - b)*(s - c)); 

		auto AB = acos((c*c - a*a - b*b)/(-2*a*b));
		auto AC = acos((b*b - a*a - c*c)/(-2*a*c));
		auto BC = acos((a*a - b*b - c*c)/(-2*b*c));

		double total = areaTri - ((AB*r1*r1)/2.0) - ((AC*r2*r2)/2.0) - ((BC*r3*r3)/2.0);

		printf("%.6lf\n", total);
	}
	return 0;
}
