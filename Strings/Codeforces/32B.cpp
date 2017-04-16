#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	for(int i=0; i< a.size(); i = i+2){
		if(a[i] == '.'){
			cout << 0;
			i= i-1;
		}
		else if((i+1) <= (a.size()-1) and a[i] == '-' and a[i+1] == '-'){
			cout << 2;
		}
		else if((i+1) <= (a.size()-1) and a[i] == '-' and a[i+1] == '.'){
			cout << 1;
		}
	}	
	cout << endl;
	return 0;
}
