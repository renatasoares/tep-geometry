#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Point {
public:
    ll x;
    ll y;

    Point(ll xv = 0, ll yv = 0) : x(xv), y(yv) {}

    bool operator<(const Point& P) const
    {
        return x == P.x ? y < P.y : x < P.x;
    }
};

ll D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

vector<Point> monotone_chain_ch(vector<Point>& P)
{
    sort(P.begin(), P.end());

    vector<Point> L, U;

    for (auto p : P)
    {
        while (L.size() >= 2 and D(L[L.size() - 2], L[L.size() -1], p) < 0)
            L.pop_back();

        L.push_back(p);
    }

    reverse(P.begin(), P.end());

    for (auto p : P)
    {
        while (U.size() >= 2 and D(U[U.size() - 2], U[U.size() -1], p) < 0)
            U.pop_back();

        U.push_back(p);
    }

    L.pop_back();
    U.pop_back();

    L.reserve(L.size() + U.size());
    L.insert(L.end(), U.begin(), U.end()); 

    return L;
}

int main(){
	int test, n;
	scanf("%d", &test);
	for(int j=0; j<test; j++){
		vector<Point> pontos;
		vector<Point> result;

		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int x, y;
			char aux[3];
			scanf("%d %d %s", &x, &y, aux);
			if(strcmp(aux, "Y") == 0){
				Point temp(x, y);
				pontos.push_back(temp);
			}
		}
		result =  monotone_chain_ch(pontos);

		cout << result.size() << endl;

		for(int k=0; k<result.size(); k++){
			cout << result[k].x << " " << result[k].y << endl;
		}
	}
	return 0;
}
