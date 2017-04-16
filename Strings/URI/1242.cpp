#include <bits/stdc++.h>

using namespace std;

vector <string> combinations = {"BS", "SB", "CF", "FC"};

int main() {
	string a;
	while (cin >> a) {
    		int count = 0;
    		while (a.size() > 1){
      			bool foi = false;
      			for (auto &t : combinations) {
        			int x = a.find(t);
        			if (x == string::npos) continue;
       		 		a = a.substr(0, x) + a.substr(x + 2);
        			count++;
        			foi = true;
        			break;
      			}
      			if(!foi) break;
    		}
    		cout << count << endl;
  	}
  	return 0;
}
