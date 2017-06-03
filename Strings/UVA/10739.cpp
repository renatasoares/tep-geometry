#include <bits/stdc++.h>

#define MAX_M   1010
#define MAX_N   1010

using namespace std;

int st[MAX_M][MAX_N];
int c_i = 1, c_r = 1, c_s = 1;    

int edit(const string& s, const string& t){
	int m = s.size();
	int n = t.size();

	for (int i = 0; i <= m; ++i){
		st[i][0] = i*c_r;
	}
	for (int j = 1; j <= n; ++j){
		st[0][j] = j*c_i;
	}

	for (int i = 1; i <= m; ++i){
		for (int j = 1; j <= n; ++j){
		    int insertion = st[i][j - 1] + c_i;
		    int deletion = st[i - 1][j] + c_r; 
		    int change = st[i - 1][j - 1] + c_s * (s[i - 1] == t[j - 1] ? 0 : 1);
		    st[i][j] = min(insertion, deletion);
		    st[i][j] = min(st[i][j], change);
		}
	}	       
	return st[m][n];
}

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		string a, b;
		cin >> a;
		b = a;
        	reverse(b.begin(), b.end());
		cout << "Case " << i << ": " << edit(a, b)/2 << endl;
	}
	return 0;
}
