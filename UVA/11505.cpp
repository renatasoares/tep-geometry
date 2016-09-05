#include <bits/stdc++.h>

using namespace std;

#define rad acos(-1.0)/180

int main(){
	int teste;
	scanf("%d", &teste);
	while(teste--){
		int n;
		string comando;
		scanf("%d", &n);
		double dist, x=0, y=0, teta=0;
		for(int i=0; i<n; i++){
			cin >> comando >> dist;
			//cout << "comando = " << comando << endl;
			if(comando == "fd"){
				x += dist * cos(teta * rad);
				y += dist * sin(teta * rad);

				//printf(" x = %.5lf | dist = %.5lf | cos = %.5lf\n", x, dist, cos(teta*rad));
				//printf(" y = %.5lf | dist = %.5lf | sin = %.5lf\n", y, dist, sin(teta*rad));
			}
			if(comando == "bk"){
				x -= dist * cos(teta * rad);
				y -= dist * sin(teta * rad);

			}
			if(comando == "lt"){
				teta += dist;
			}
			if(comando == "rt"){
				teta -= dist;
			}
		}
		double raiz = (sqrt(x*x + y*y )) + 0.5; 
		printf("%d\n", (int)raiz);	
	}
	return 0;
}
