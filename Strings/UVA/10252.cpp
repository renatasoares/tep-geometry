#include <bits/stdc++.h>

using namespace std;

vector<char> alfa = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(){
	string a, b;
	while(getline(cin, a)){
		getline(cin, b);
		map<char, int> h1;
		map<char, int> h2;
		for(auto c: a) ++h1[c];
		for(auto c: b) ++h2[c];
		for(int i=1; i<=26; i++){
			char aux = alfa[i];
			//cout << aux << " " << h1[aux] << " " << h2[aux] << endl;
			if(h1[aux] != 0 and h2[aux] != 0){
				int menor = min(h1[aux], h2[aux]);
				for(int j=0; j<menor; j++){
			 		cout << alfa[i];
				}
			}
		}
		cout << endl;
	}
	return 0;
}
