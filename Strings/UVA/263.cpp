#include<bits/stdc++.h>

using namespace std;

int main(){
	string a;
	map<int, bool> check; 
	
	while(1){
		check.clear();
		int chain=0;
		cin >> a;
		if(a == "0") return 0;	
		cout << "Original number was " << a << endl; 
		
		while(1){
			chain++;
			sort(a.begin(), a.end());
	    		string copy(a);
	    		reverse(copy.begin(), copy.end());

			int x = atoi( a.c_str()), y = atoi( copy.c_str());

			int sub = y - x;

			cout << y << " - " << x << " = " << sub << endl;
	
			if(check[sub]){
				cout << "Chain length "<<  chain << endl;
				cout << endl;
		 		break;
			}
			check[sub] = true;
			a=to_string(sub);

		
		}
	}
	return 0;
}
