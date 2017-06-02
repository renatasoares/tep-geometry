#include <bits/stdc++.h>

#define MAX_M   1000
#define MAX_N   1000

using namespace std;

map<string, char> cores;
double st[MAX_M][MAX_N];
double c_i = 2.5, c_r = 0.5, c_s = 1.0;     

double edit(const string& s, const string& t){
    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m; ++i)
        st[i][0] = i*c_r;

    for (int j = 1; j <= n; ++j)
        st[0][j] = j*c_i;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            double insertion = st[i][j - 1] + c_i;
            double deletion = st[i - 1][j] + c_r; 
            double change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);
        }
                       
    return st[m][n];
}

int main(){

	int k, t, r, m, s;
	string c, c2, s1, s2;

	cin >> t;
	for(k = 1; k <= t; ++k){
		cin >> r;
		cin >> m;
		char cont = 'a';
		s1 = "";
		s2 = "";
		for(int i = 1; i <= m; ++i){
			cin >> c;
			if(!cores[c])
				cores[c] = cont++;
			
			s1 += cores[c];
		}
		cin >> s;
		for(int i = 0; i < s; ++i){
			cin >> c2;
			if(!cores[c2])
				cores[c2] = cont++;
			
			s2 += cores[c2];
		}
		cores.clear();
		double x = edit(s1,s2) * r;
		string x2 = to_string(x);
		istringstream is(x2);
		string token;

		cout << "Caso #" << k <<": R$ "; 

		getline(is, token, '.');
		cout << token << ",";
		
		getline(is, token);
		cout << token[0] << token[1] << endl;
	}

	return 0;
}
