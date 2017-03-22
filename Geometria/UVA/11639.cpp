#include <bits/stdc++.h>

#define total 10000

using namespace std;

class Point {
public:
    double x;
    double y;

    Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

class Rectangle {
public:
    	Point P, Q;
   	double b, h;

    	Rectangle(const Point& pv, const Point& qv) : P(pv), Q(qv) {}

	double area() const {
		return abs(P.x - Q.x) * abs(P.y - Q.y);
	}

	Rectangle intersection(const Rectangle& r) const {
		auto ax = max(P.x, r.P.x);
		auto bx = min(Q.x, r.Q.x);

		auto ay = max(P.y, r.P.y);
		auto by = min(Q.y, r.Q.y);

		if(ax < bx and ay < by) {
			return Rectangle(Point(ax, ay), Point(bx, by));
		}else{
			return Rectangle(Point(0,0), Point(0,0));
		}
	}
};	

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		double x1, y1, x2, y2;
		double x3, y3, x4, y4;

		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);

		Point p(x1, y1), q(x2, y2);
		Point s(x3, y3), t(x4, y4);

		Rectangle r(p, q);
		Rectangle x(s, t);
		Rectangle inter = r.intersection(x);

		double strong = inter.area();
		double weak = (r.area() + x.area()) - 2*strong;
		double unsecure = total - weak - strong;

		printf("Night %d: %.0lf %.0lf %.0lf\n", i,strong ,weak, unsecure);

	}
	return 0;
}
