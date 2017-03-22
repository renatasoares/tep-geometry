#include <bits/stdc++.h>

#define PI acos(-1.0)
#define EPS 1e-9

using namespace std;

int main(){
	while(1){
		vector <long long> lado;
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		if ( a == 0 && b == 0 && c == 0) return 0;

		lado.push_back(a);
		lado.push_back(b);
		lado.push_back(c);

		sort(lado.begin(), lado.end());

		long long hyp = lado[2] * lado[2];
		long long soma = (lado[0] * lado[0]) + (lado[1] * lado[1]);

		if(hyp == soma){
			printf("right\n");
		}
		else{
			printf("wrong\n");
		}
		lado.clear();
	}
	return 0;
}
