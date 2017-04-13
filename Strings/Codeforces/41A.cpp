#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	cin >> a;
	cin >> b;
	reverse(a.begin(), a.end());

	cout << (a == b? "YES" : "NO") << endl;

	return 0;
}
