#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i=1; i<=n; i++){
			long long a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			if(a+b<=c || b+c<=a || a+c<=b || a<=0 || b<=0 || c<=0){
		        	printf("Case %d: Invalid\n", i);
			}
			else{
				if(a == b && b == c){
					printf("Case %d: Equilateral\n", i);
				}
				else if(a != b && b!=c && c!=a){
					printf("Case %d: Scalene\n", i);
				}
				else{
					printf("Case %d: Isosceles\n", i);
				}
			}
		}
	}
	return 0;
}
	


