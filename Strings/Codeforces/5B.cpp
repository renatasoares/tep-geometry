#include <bits/stdc++.h>

using namespace std;

void espaco(int n){
	for(int i=0; i<(n/2); i++){
		printf(" ");
	}
}

int main(){
       	string line;
	vector<string> text;
	int maior = 0;
       	while(getline(cin, line)){	
		if(line.size() > maior){ maior = line.size(); }
		text.push_back(line);
		

	}
	for(int i=0; i<maior+2; i++){
		cout << "*";	
	}
	cout << endl;
	bool left = false;
	for(int i=0; i< text.size(); i++){
		int tamanho = text[i].size();
		if(tamanho == 0){
			cout <<"*";
			espaco(maior*2);
			cout <<"*" << endl;
		}
	        else if(tamanho == maior){ 
			cout << "*" << text[i] << "*" << endl;
		}
		else{
			int resto = maior - tamanho;
			if(resto%2 == 0){
				cout << "*";
				espaco(resto);
				cout << text[i];
				espaco(resto);
				cout << "*" << endl;
			}
			else{
				cout << "*";
				if(left){
					espaco(resto+1);
					cout << text[i];
					espaco(resto-1);
					left = 1 - left;
				}
				else{
					espaco(resto-1);
					cout << text[i];
					espaco(resto+1);
					left = 1 - left;
				}
				cout << "*" << endl;
			}
		}
	}
	for(int i=0; i<maior+2; i++){
		cout << "*";	
	}
	cout << endl;
	return 0;
}
