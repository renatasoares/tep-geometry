#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string name;
	
	scanf("%d", &n);
	cin>>name;

	int tamanho1 = name.length();

    	name.erase(unique(name.begin(), name.end()), name.end());

	int tamanho2 =  name.length();

	cout << tamanho1-tamanho2 << endl;
	
	return 0;
}
