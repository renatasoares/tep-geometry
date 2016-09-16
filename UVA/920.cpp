#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool operator<(const point& other) const {                                                                                                                  
		return fabs(x - other.x) < EPS ? (y - other.y) < -EPS : (x - other.x) < -EPS;
	}
};

class segment {
public:
	point p, q;

	segment(point a, point b) {
		p = a;
		q = b;
	}
};

int main(){
	int teste;
	scanf("%d", &teste);
	while(teste--){
		int n;
		vector <point> pto;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			pto.push_back(point(x,y));
		}

		sort(pto.begin(), pto.end());

		double distance=0, maior = 0;

		for(int j= pto.size()-1 ; j >= 1 ; j--){
			auto aux = segment(pto[j-1], pto[j]);
			if(pto[j-1].y >= maior){

				auto temp = segment(point(0, maior), point(-10, maior));

				double x1 = aux.p.x;
				double y1 = aux.p.y;
				double x2 = aux.q.x;
				double y2 = aux.q.y;
				double x3 = temp.p.x;
				double y3 = temp.p.y;
				double x4 = temp.q.x;
				double y4 = temp.q.y;

				double a1 = y1-y2;
				double a2 = y3-y4;
				double b1 = x2-x1;
				double b2 = x4-x3;
				double c1 = x1*y2 - x2*y1;
				double c2 = x3*y4 - x4*y3;

				double det = a1*b2 - b1*a2;
				double detx = (-1*c1*b2) - (-1*b1*c2);
				double dety = (-1*a1*c2) - (-1*c1*a2);

				double x = detx/det;
				double y = dety/det;

				double comp1, comp2;

				if(y1 > y2){
					comp1 = x1;
					comp2 = y1;
				}
				else{
					comp1 = x2;
					comp2 = y2;
				}
				distance += hypot( comp1 - x , comp2 - y);
				maior = pto[j-1].y;
			} 
		}
		printf("%.2lf\n", distance);
	}
	return 0;
}
