#include <bits/stdc++.h>

using namespace std;

#define MAX 9999

int main(){
	vector <double> ptox;
	vector <double> ptoy;
	vector <double> ptoz;
	while(1){
		double x, y, z;
		scanf("%lf %lf %lf", &x, &y, &z);
		if(x == 0 && y == 0 && z == 0) break;
		ptox.push_back(x);
		ptoy.push_back(y);
		ptoz.push_back(z);
	}
	int counts[15];
	memset(counts, 0, sizeof counts);
	for(int i=0; i < ptox.size(); i++){
		double temp, menor=MAX;
		for(int j=0; j < ptox.size();j++){
			if(i==j){
				continue;			
			}
			temp = sqrt( pow(ptox[i]-ptox[j],2) + pow(ptoy[i]-ptoy[j],2) + pow(ptoz[i]-ptoz[j],2) );
			if(temp < menor){		
				menor = temp;
			}
		}
		if(menor < 10){
			//cout << menor << endl;
			counts[(int)menor] += 1;
		}
	}
	for(int r=0; r<10; r++){
		printf("%4d", counts[r]);
	}
	printf("\n");
		
	return 0;
} 
