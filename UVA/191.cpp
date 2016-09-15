#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

double equals(double x, double y) {
	return fabs(x - y) < EPS;
}

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool operator<(const point& other) const {                                                                                                                  
		return fabs(x - other.x) < EPS ? (y - other.y) < -EPS : (x - other.x) < -EPS;
	}
};

double det(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

class segment {
public:
	point p, q;

	segment(point a, point b) {
		p = min(a, b);
		q = max(a, b);
	}

	bool contains(const point& a) {
		return equals(p.x, q.x) ? (p.y - EPS < a.y && q.y + EPS > a.y) :
					  (p.x - EPS < a.x && q.x + EPS > a.x);
	}

	bool intersects(segment& s) {
		auto det1 = det(p, q, s.p);
		auto det2 = det(p, q, s.q);
		auto det3 = det(s.p, s.q, p);
		auto det4 = det(s.p, s.q, q);

		return (equals(det1, 0) && contains(s.p)) || (equals(det2, 0) && contains(s.q)) ||
		       (equals(det3, 0) && s.contains(p)) || (equals(det4, 0) && s.contains(q)) || (det1 * det2 < -EPS && det3 * det4 < -EPS);
	}
};

bool pto(double x1, double y1, double x2, double y2){
		if(equals(x1, x2) && equals(y1,y2)){
			return true;
		}
		else{
			return false;
		}
}

int main(){
	int teste;
	scanf("%d", &teste);
	while(teste--){
		vector <segment> s;
		double x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

		double xl, yl, xr, yr;
		
		xl = min(x3, x4);
		yl = max(y3, y4);
		xr = max(x3, x4);
		yr = min(y3, y4);

		if(x1 >= xl && x1 <= xr && y1 >= yr && y1 <= yl){
			cout << "T" << endl;
			continue;
		}

		if(x2 >= xl && x2 <= xr && y2 >= yr && y2 <= yl){
			cout << "T" << endl;
			continue;
		}
		
		s.push_back(segment(point(x1, y1), point(x2, y2)));
		//primeira reta do retangulo
		s.push_back(segment(point(xl, yl), point(xr, yl)));
		//segunda reta do retangulo
		s.push_back(segment(point(xl, yr), point(xr, yr)));
		//terceira reta do retangulo
		s.push_back(segment(point(xl, yl), point(xl, yr)));
		//quarta reta do retangulo
		s.push_back(segment(point(xr, yl), point(xr, yr)));
		
		int r=0;

		if(!pto(x1, y1, x2, y2)){
			for(int i=1; i< s.size();i++){
				if(s[0].intersects(s[i])){
					cout << "T" << endl;
					r++;
					break;
				}
			}
		}
	
		if(r == 0){
			cout << "F" << endl;
		}

		s.clear();
	}
	return 0;
}
