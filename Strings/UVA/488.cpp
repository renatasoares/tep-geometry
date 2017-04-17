#include <bits/stdc++.h>

using namespace std;

vector <string> num = {"zero", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};

int main(){
	int teste;
	scanf("%d\n\n", &teste);
	for(int i=1; i<=teste; i++){
		int a,f;
		cin >> a >> f;
		for(int x=1; x<=f; x++){
			for(int j=1; j<=a; j++){
				cout << num[j] << endl;
			}
			for(int z=(a-1); z>=1; z--){
				cout << num[z] << endl;
			}
			if(i == teste && x == f){}
			else{cout << endl;}
		}
		scanf("\n");
	}
	return 0;
}
