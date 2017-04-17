#include<bits/stdc++.h>

using namespace std;

int main(){
       string line;
	vector<char> carac;
       while(getline(cin, line), line!="*"){
		
               istringstream is (line);
               string word, aux;
               while(is >> word){
			carac.push_back(tolower(word[0]));			
                }
    		carac.erase(unique(carac.begin(), carac.end()), carac.end());

		cout << (carac.size() == 1 ? "Y" : "N") << endl;

		carac.clear();
		
       }
	return 0;
}
