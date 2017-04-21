#include<bits/stdc++.h>

using namespace std;

int main(){
       string line;
       while(getline(cin, line), line!="e/o/i"){
               istringstream is (line);
   	 	string token1, token2, token3;
    		
		getline(is, token1, '/');
    		getline(is, token2, '/');
    		getline(is, token3, '/');

		vector<string> tokens;
		tokens.push_back(token1);
		tokens.push_back(token2);
		tokens.push_back(token3);

		bool vogal = false;
		bool certo = false;

		for(int j=0; j<tokens.size(); j++){
			int count = 0; 
			vogal = false;
			for(int i=0; i< tokens[j].size(); i++){
				if(tokens[j][i] == 'a' ||tokens[j][i] == 'e' || tokens[j][i] == 'i' || tokens[j][i] == 'o' || tokens[j][i] == 'u' || tokens[j][i] == 'y'){
					if(!vogal)count++;				
					vogal = true;			
				}
				else{
					vogal = false;
				}
			}
			if(count == 5 && j == 0){ certo = true;}
			else if(count == 7 && j == 1){certo = true;}
			else if(count == 5 && j == 2){certo = true;}
			else{
				certo = false;
				cout << j+1 << endl; 
				break;
			}
	
		}
		if(certo) cout << "Y" << endl;

       }
	return 0;
}
