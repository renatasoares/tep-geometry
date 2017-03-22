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

double equals(double x, double y) {
	return fabs(x - y) < EPS;
}

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


int main(){
	int teste;
	scanf("%d", &teste);
	while(teste--){
		vector <segment> s;
	
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			double x1, y1, x2, y2;			
			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			s.push_back(segment(point(x1, y1), point(x2, y2)));
		}
		int valid[110];
		memset(valid, 0, sizeof valid);

		for(int i=0; i<n;i++){
			for(int j=0; j<n; j++){
				if(i == j) continue;
				if(s[i].intersects(s[j])){
					valid[i] += 1;
				}
			}
		}

		int count=0;

		for(int i=0; i<n; i++){
			if(valid[i] == 0){
				count++;
			}
		}

		cout << count << endl;
		
		s.clear();
	}
	return 0;
}
