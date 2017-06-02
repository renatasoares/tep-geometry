#include <bits/stdc++.h>

using namespace std;

int main(){
	int i=1;
	while(1){
		string a, b;
		cin >> a;
		if(a == "0") break;
		cin >> b;

		size_t found = b.find(a);
		if(i!=1){cout << endl;}
		cout << "Instancia " << i++ << endl;
		cout << (found!=std::string::npos ? "verdadeira" : "falsa") << endl;
			
	}
	return 0;
}
