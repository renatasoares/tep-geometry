#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;
    for(int i = 1; i < n; i++) {
        if(i <= R) {
            z[i] = min(z[i - L], R - i + 1);
        }
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) {
            z[i]++;
        }
        if(R < i + z[i] - 1) {
            L = i, R = i + z[i] - 1;
        }
    }
    return z;
}

int main(){
	vector<int> z;
	string a, b;
	cin >> a >> b;
	int tam = b.size();
	string s =  b + '#' + a;
	int count =0;
	z = z_function(s);
	for(int i= tam; i<z.size(); i++){
		if(z[i] == tam){
			count ++;
			i= i+tam-1;
		}
	}
	cout << count << endl;
	return 0;
}
